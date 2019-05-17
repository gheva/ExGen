ROOT := $(strip ${ROOT})/..
DIRNAME := xml

STATIC_MODULES += xml

DIR_MODULE := xml
include $(strip ${BLDFILES})/header.mk

DIR_SUBDIRS += unittests

DIR_OBJS += xmlnode

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

