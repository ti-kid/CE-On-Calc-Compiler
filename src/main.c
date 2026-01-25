#include <tice.h>
#include <fileioc.h>
#include <stdlib.h>
#include <string.h>
#include "chibicc.h"
#include "memfile.h"

// Load an entire AppVar into a RAM buffer
static char *load_appvar(const char *name) {
    ti_var_t var = ti_Open(name, "r");
    if (!var)
        return NULL;

    uint16_t size = ti_GetSize(var);
    char *buf = malloc(size + 1);
    if (!buf) {
        ti_Close(var);
        return NULL;
    }

    ti_Read(buf, size, 1, var);
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
        os_PutStrFull("Could not open AppVar: ");
        os_PutStrFull(src_name);
        while (!os_GetCSC());
        return 1;
    }

    // Tokenize → preprocess → parse
    File *f = new_file((char*)src_name, 1, src);
    Token *tok = tokenize(f);
    tok = preprocess(tok);
    Obj *prog = parse(tok);

    // Output buffer (CEdev supports fmemopen)
    char outbuf[8192];
    FILE *out = mem_fopen(outbuf, sizeof(outbuf));

    // Generate assembly (still x86-64 until we replace backend)
    codegen(prog, out);
    mem_fclose(out);

    // Print result to screen
    os_ClrHome();
    os_PutStrFull("=== Assembly Output ===\n");
    os_PutStrFull(outbuf);

    // Optionally save to AppVar
    ti_var_t outvar = ti_Open(out_name, "w");
    if (outvar) {
        ti_Write(outbuf, strlen(outbuf), 1, outvar);
        ti_Close(outvar);
    }

    os_NewLine();
    os_PutStrFull("[Done]");
    while (!os_GetCSC());
    return 0;
}

