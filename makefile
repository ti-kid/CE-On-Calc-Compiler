# ----------------------------
# Makefile Options
# ----------------------------

NAME = CC
ICON = icon.png
DESCRIPTION = "CE C89 Compiler"
COMPRESSED = YES
ARCHIVED = NO
OUTPUT_MAP = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
