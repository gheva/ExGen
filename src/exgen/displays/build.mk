ROOT := $(strip ${ROOT})/..
DIRNAME := displays

STATIC_MODULES += exgen_displays
DIR_MODULE := exgen_displays

include $(strip ${BLDFILES})/header.mk

DIR_COMPILATION_FLAGS += -Isrc/svg -Isrc/xml -Isrc/mathex -Isrc/xgen

DIR_OBJS := svgdisplay
DIR_OBJS += exercisesvg
DIR_OBJS += plusminussvg
DIR_OBJS += muldivsvg

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

