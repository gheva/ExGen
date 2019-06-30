ROOT := $(strip ${ROOT})/..
DIRNAME := mathex

DIR_MODULE := mathex
STATIC_MODULES += mathex

include $(strip ${BLDFILES})/header.mk

ADDITION_OBJS := addition
ADDITION_OBJS += addingdigitsupto10
ADDITION_OBJS += addingdigitsupto20
ADDITION_OBJS += addingabove10
ADDITION_OBJS += carrying2digits

SUBTRACT_OBJ := subtraction
SUBTRACT_OBJ += plusminus
SUBTRACT_OBJ += subtractdigits
SUBTRACT_OBJ += subtractdigitfromnumber
SUBTRACT_OBJ += subtractsamedigit
SUBTRACT_OBJ += longplusminus

ARITHMETIC_OBJS := arithmetic
ARITHMETIC_OBJS += carryborrow
ARITHMETIC_OBJS += plustomul

MULTIPLICATION_OBJS := multiplication
MULTIPLICATION_OBJS += mulexercise
MULTIPLICATION_OBJS += countby
MULTIPLICATION_OBJS += multable
MULTIPLICATION_OBJS += multiplyby
MULTIPLICATION_OBJS += digitbydigit

DIR_OBJS := ${ADDITION_OBJS}
DIR_OBJS += ${SUBTRACT_OBJ}
DIR_OBJS += ${ARITHMETIC_OBJS}
DIR_OBJS += ${MULTIPLICATION_OBJS}
DIR_OBJS += mathexercise
DIR_OBJS += plusminusexercise
DIR_OBJS += randnum

DIR_COMPILATION_FLAGS += -Isrc/xgen

include $(strip ${BLDFILES})/footer.mk

# vim: set noexpandtab :

