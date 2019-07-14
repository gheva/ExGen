ROOT := $(strip ${ROOT})/..
DIRNAME := apps

include $(strip ${BLDFILES})/header.mk

$(call ADD_EXE, unittests)
$(call ADD_EXE, lined_page)
$(call ADD_EXE, cursive_worksheet)

ifdef BUILD_LAMBDA
DIR_SUBDIRS += exgen2httpdsl
endif

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

