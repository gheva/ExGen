ROOT := $(strip ${ROOT})/..
DIRNAME := unittests

STATIC_MODULES += svgtests

DIR_MODULE := svgtests
include $(strip ${BLDFILES})/header.mk

unittests_MODULES += svgtests
unittests_MODULES += svg
unittests_MODULES += xml

DIR_OBJS += svgelementtests
DIR_OBJS += svgfonttests

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

