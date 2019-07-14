ROOT := $(strip ${ROOT})/..
DIRNAME := exgen2httpdsl

include $(strip ${BLDFILES})/header.mk

$(call ADD_EXE, exgen2httpdsl)

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

