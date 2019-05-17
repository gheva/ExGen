SRCDIR := src
OUTDIR := build
LIBDIR := lib
EXEDIR := exe

CXXFLAGS += -std=c++11

OBJ_SFX := o
SHARED_SFX := so
STATIC_SFX := a
EXE_SFX := exe

MKDIR := mkdir -p
RMDIR := rm -rf
RM_F := rm -f

BLDFILES := mk

CXXFLAGS += -DMATH_EXERCISE_IDS_FIRST=0

DEBUG := 1

#DEBUG_MAKE := 1

include $(strip ${BLDFILES})/project.mk

docs: ${OUTDIR}
	doxygen Doxyfile

# vim: set noexpandtab :

