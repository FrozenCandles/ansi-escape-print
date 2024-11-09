#ifndef __ANSI_ESCAPE_PRINT__
#define __ANSI_ESCAPE_PRINT__

#define PRT_CSI "\033["
#define PRT_OSC "\033]"

#define PRT_RESET     "0"
#define PRT_BRIGHT    "1"
#define PRT_UNDERLINE "4"
#define PRT_NORMAL    "22"

#define PRT_COLOR_BLACK   "30"
#define PRT_COLOR_RED     "31"
#define PRT_COLOR_GREEN   "32"
#define PRT_COLOR_YELLOW  "33"
#define PRT_COLOR_BLUE    "34"
#define PRT_COLOR_MAGENTA "35"
#define PRT_COLOR_CYAN    "36"
#define PRT_COLOR_WHITE   "37"
#define PRT_COLOR_RESET   "39"

#define PRT_BACKGROUND_BLACK   "40"
#define PRT_BACKGROUND_RED     "41"
#define PRT_BACKGROUND_GREEN   "42"
#define PRT_BACKGROUND_YELLOW  "43"
#define PRT_BACKGROUND_BLUE    "44"
#define PRT_BACKGROUND_MAGENTA "45"
#define PRT_BACKGROUND_CYAN    "46"
#define PRT_BACKGROUND_WHITE   "47"
#define PRT_BACKGROUND_RESET   "49"


#define __PRT_EXPAND(...) __VA_ARGS__

#define __PRT_CAT_I(a, b) a ## b
#define __PRT_CAT(a, b) __PRT_CAT_I(a, b)

#define __PRT_ARG_1(_0, arg, ...) arg
#define __PRT_ARG_2(_0, _1, arg, ...) arg

#define __PRT_IS_EMPTY(true, false, ...) \
    __PRT_CAT(__PRT_IS_EMPTY_TRUE, __VA_OPT__(_FALSE))(true, false)

#define __PRT_IS_EMPTY_TRUE(true, false) true
#define __PRT_IS_EMPTY_TRUE_FALSE(true, false) false


#define PRT_COLOR(r, g, b) "38;2;" #r ";" #g ";" #b
#define PRT_BACKGROUND(r, g, b) "48;2;" #r ";" #g ";" #b


#define __PRT_CURSOR_UP_1(n)      PRT_CSI "1A"
#define __PRT_CURSOR_DOWN_1(n)    PRT_CSI "1B"
#define __PRT_CURSOR_FORWARD_1(n) PRT_CSI "1C"
#define __PRT_CURSOR_BACK_1(n)    PRT_CSI "1D"

#define __PRT_CURSOR_UP_N(n)      PRT_CSI #n "A"
#define __PRT_CURSOR_DOWN_N(n)    PRT_CSI #n "B"
#define __PRT_CURSOR_FORWARD_N(n) PRT_CSI #n "C"
#define __PRT_CURSOR_BACK_N(n)    PRT_CSI #n "D"

#define PRT_CURSOR_UP(arg) \
    __PRT_CAT(__PRT_CURSOR_UP_, __PRT_IS_EMPTY(1, N, arg))(arg)
#define PRT_CURSOR_DOWN(arg) \
    __PRT_CAT(__PRT_CURSOR_DOWN_, __PRT_IS_EMPTY(1, N, arg))(arg)
#define PRT_CURSOR_FORWARD(arg) \
    __PRT_CAT(__PRT_CURSOR_FORWARD_, __PRT_IS_EMPTY(1, N, arg))(arg)
#define PRT_CURSOR_BACK(arg) \
    __PRT_CAT(__PRT_CURSOR_BACK_, __PRT_IS_EMPTY(1, N, arg))(arg)

#define PRT_CURSOR_POS(x, y)    PRT_CSI #y ";" #x 'H'

#include "ansi_escape_print_impl.h"

#define PRT_FORMAT(...) \
    PRT_CSI __PRT_FORMAT(__VA_ARGS__) "m"

#define PRT_END PRT_FORMAT(PRT_RESET)

#endif /* __ANSI_ESCAPE_PRINT__ */
