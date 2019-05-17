EXECUTABLES += cursive_worksheet

DIR_EXES += cursive_worksheet

DIR_COMPILATION_FLAGS += -Isrc/svg -Iassets
cursive_worksheet_OBJS += cursive_worksheet

cursive_worksheet_MODULES += svg
cursive_worksheet_MODULES += xml

# vim: set noexpandtab :

