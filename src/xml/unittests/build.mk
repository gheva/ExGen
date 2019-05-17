ROOT := $(strip ${ROOT})/..
DIRNAME := unittests

STATIC_MODULES += xmlut

DIR_MODULE := xmlut
include $(strip ${BLDFILES})/header.mk

unittests_MODULES += xmlut
unittests_MODULES += xml

DIR_OBJS += xmlnodetests

#$(call ADD_EXE, xmlnode_demo1)

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

