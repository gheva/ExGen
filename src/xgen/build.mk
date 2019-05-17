ROOT := $(strip ${ROOT})/..
DIRNAME := xgen

DIR_MODULE := xgen
STATIC_MODULES += xgen

include $(strip ${BLDFILES})/header.mk

DIR_OBJS += topic
DIR_OBJS += level
DIR_OBJS += exercise
DIR_OBJS += display

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

