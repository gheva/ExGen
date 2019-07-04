ROOT := $(strip ${ROOT})/..
DIRNAME := exgen

EDU_CXX_FLAGS := -Isrc/xgen

include $(strip ${BLDFILES})/header.mk

DIR_SUBDIRS += displays
$(call ADD_EXE, exgen)
$(call ADD_EXE, multiplication_course)

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

