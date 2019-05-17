ROOT := $(strip ${ROOT})/..
DIRNAME := svg

STATIC_MODULES += svg

DIR_MODULE := svg
include $(strip ${BLDFILES})/header.mk

DIR_OBJS += svgelement
DIR_OBJS += line
DIR_OBJS += font
DIR_OBJS += text
DIR_OBJS += g
DIR_OBJS += use
DIR_OBJS += defs
DIR_OBJS += linedtext
DIR_SUBDIRS += unittests

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

