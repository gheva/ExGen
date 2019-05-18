ROOT := $(strip ${ROOT})/..
DIRNAME := cursex

DIR_MODULE := cursex
STATIC_MODULES += cursex

include $(strip ${BLDFILES})/header.mk
DIR_COMPILATION_FLAGS += -Isrc/xgen

DIR_OBJS += cursiveexercise

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

