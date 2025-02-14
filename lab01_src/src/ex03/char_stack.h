#ifndef CHAR_STACK_H
#define CHAR_STACK_H

#undef TYPE
#undef TPREFIX

#define TYPE char
#define TPREFIX(NAME) c_ ## NAME

#include "generic_stack.h"

#endif
