#ifndef __ANSI_ESCAPE_PRINT_IMPL__
#define __ANSI_ESCAPE_PRINT_IMPL__

#define __PRT_FORMAT_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME

#define __PRT_FORMAT_1(_1) _1
#define __PRT_FORMAT_2(_1, _2) _1 ";" _2
#define __PRT_FORMAT_3(_1, _2, _3) _1 ";" _2 ";" _3
#define __PRT_FORMAT_4(_1, _2, _3, _4) _1 ";" _2 ";" _3 ";" _4
#define __PRT_FORMAT_5(_1, _2, _3, _4, _5) _1 ";" _2 ";" _3 ";" _4 ";" _5
#define __PRT_FORMAT_6(_1, _2, _3, _4, _5, _6) _1 ";" _2 ";" _3 ";" _4 ";" _5 ";" _6
#define __PRT_FORMAT_7(_1, _2, _3, _4, _5, _6, _7) _1 ";" _2 ";" _3 ";" _4 ";" _5 ";" _6 ";" _7
#define __PRT_FORMAT_8(_1, _2, _3, _4, _5, _6, _7, _8) _1 ";" _2 ";" _3 ";" _4 ";" _5 ";" _6 ";" _7 ";" _8
#define __PRT_FORMAT_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _1 ";" _2 ";" _3 ";" _4 ";" _5 ";" _6 ";" _7 ";" _8 ";" _9
#define __PRT_FORMAT_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) _1 ";" _2 ";" _3 ";" _4 ";" _5 ";" _6 ";" _7 ";" _8 ";" _9 ";" _10

#define __PRT_FORMAT(...) \
    __PRT_EXPAND(__PRT_FORMAT_N(__VA_ARGS__, \
        __PRT_FORMAT_10, \
        __PRT_FORMAT_9, \
        __PRT_FORMAT_8, \
        __PRT_FORMAT_7, \
        __PRT_FORMAT_6, \
        __PRT_FORMAT_5, \
        __PRT_FORMAT_4, \
        __PRT_FORMAT_3, \
        __PRT_FORMAT_2, \
        __PRT_FORMAT_1, \
    )(__VA_ARGS__))

#endif /* __ANSI_ESCAPE_PRINT_IMPL__ */
