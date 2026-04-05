#include <tice.h>
#include <fileioc.h>
#include <stdlib.h>
#include <string.h>
#include "chibicc.h"

// Global variables required by the compiler
StringArray include_paths;
bool opt_fpic = false;
bool opt_fcommon = true;
char *base_file;

bool file_exists(char *path) {
    ti_var_t var = ti_Open(path, "r");
    if (var) {
        ti_Close(var);
        return true;
    }
    return false;
}

// Load an entire AppVar into a RAM buffer
static char *load_appvar(const char *name) {
    ti_var_t var = ti_Open(name, "r");
    if (!var)
        return NULL;

    uint16_t size = ti_GetSize(var);
    char *buf = malloc(size + 2);
    if (!buf) {
        ti_Close(var);
        return NULL;
    }

    ti_Read(buf, size, 1, var);
    // Ensure newline termination
    if (size == 0 || buf[size - 1] != '\n')
        buf[size++] = '\n';
    buf[size] = '\0';
    ti_Close(var);
    return buf;
}

int main(int argc, char **argv) {
    os_ClrHome();

    if (argc < 2) {
        os_PutStrFull("Usage: CC <SRCVAR> [OUTVAR]");
        while (!os_GetCSC());
        return 1;
    }

    const char *src_name = argv[1];
    const char *out_name = (argc >= 3) ? argv[2] : "OUTASM";

    // Load source code from AppVar
    char *src = load_appvar(src_name);
    if (!src) {
        os_PutStrFull("Could not open: ");
        os_PutStrFull(src_name);
        while (!os_GetCSC());
        return 1;
    }

    base_file = (char *)src_name;

    // Tokenize -> preprocess -> parse
    File *f = new_file((char *)src_name, 1, src);
    init_macros();
    Token *tok = tokenize(f);
    tok = preprocess(tok);
    Obj *prog = parse(tok);

    // Output buffer for generated eZ80 assembly
    // 16KB should be sufficient for small programs on-calc
    char *outbuf = malloc(16384);
    if (!outbuf) {
        os_PutStrFull("Out of memory");
        while (!os_GetCSC());
        return 1;
    }

    OutBuf ob;
    outbuf_init(&ob, outbuf, 16384);

    // Generate eZ80 assembly
    codegen(prog, &ob);

    // Convert output to TI-OS token format for program editor
    {
        size_t len = outbuf_len(&ob);
        // Worst case: every tab expands to 4 bytes, so same buffer is fine
        // since tabs shrink from 1->4 but we allocated 16KB
        char *tmp = malloc(len * 4 + 1);
        size_t j = 0;
        for (size_t i = 0; i < len; i++) {
            char c = outbuf[i];
            if (c == '\t') {
                tmp[j++] = 0x29;
                tmp[j++] = 0x29;
                tmp[j++] = 0x29;
                tmp[j++] = 0x29;
            } else if (c == ' ') {
                tmp[j++] = 0x29;
            } else if (c == '\n') {
                tmp[j++] = 0x3F;
            } else if (c == '_') {
                tmp[j++] = 0x71;
            } else if (c == ',') {
                tmp[j++] = 0x2B;
            } else if (c >= 'a' && c <= 'z') {
                tmp[j++] = c - 32;
            } else {
                tmp[j++] = c;
            }
        }
        memcpy(outbuf, tmp, j);
        ob.pos = j;
        free(tmp);
    }

    // Show summary on screen
    os_ClrHome();
    os_PutStrFull("Compiled OK!");
    os_NewLine();
    char info[40];
    snprintf(info, sizeof(info), "Output: %d bytes", (int)outbuf_len(&ob));
    os_PutStrFull(info);
    os_NewLine();

    // Save as a TI program (viewable in program editor)
    ti_var_t outvar = ti_OpenVar(out_name, "w", TI_PRGM_TYPE);
    if (outvar) {
        ti_Write(outbuf, outbuf_len(&ob), 1, outvar);
        ti_Close(outvar);
        os_PutStrFull("Saved to prgm");
        os_PutStrFull(out_name);
    } else {
        os_PutStrFull("Failed to save!");
    }

    os_NewLine();
    os_PutStrFull("[Press any key]");
    while (!os_GetCSC());

    free(outbuf);
    return 0;
}
