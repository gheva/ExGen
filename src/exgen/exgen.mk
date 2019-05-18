EXECUTABLES += exgen

DIR_EXES += exgen
exgen_OBJS += exgen

exgen_MODULES += exgen_displays
exgen_MODULES += mathex
exgen_MODULES += cursex
exgen_MODULES += xml
exgen_MODULES += svg
exgen_MODULES += xgen

DIR_COMPILATION_FLAGS += -Isrc/xgen
DIR_COMPILATION_FLAGS += -Isrc/mathex
DIR_COMPILATION_FLAGS += -Isrc/cursex
DIR_COMPILATION_FLAGS += -Isrc/exgen

# vim: set noexpandtab :

