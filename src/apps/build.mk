ROOT := $(strip ${ROOT})/..
DIRNAME := apps

include $(strip ${BLDFILES})/header.mk

$(call ADD_EXE, unittests)
$(call ADD_EXE, lined_page)

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

