ROOT := $(strip ${ROOT})/..
DIRNAME := exgen

EDU_CXX_FLAGS := -Isrc/xgen

include $(strip ${BLDFILES})/header.mk

DIR_SUBDIRS += displays
$(call ADD_EXE, exgen)

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

