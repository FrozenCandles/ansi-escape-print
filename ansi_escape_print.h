#ifndef __ANSI_ESCAPE_PRINT__
#define __ANSI_ESCAPE_PRINT__


// macro utils
#define __PRT_EXPAND(...) __VA_ARGS__

#define __PRT_CAT_I(a, b) a ## b
#define __PRT_CAT(a, b) __PRT_CAT_I(a, b)

#define __PRT_ARG_1(_0, arg, ...) arg
#define __PRT_ARG_2(_0, _1, arg, ...) arg

#define __PRT_IS_EMPTY(true, false, ...) \
    __PRT_CAT(__PRT_IS_EMPTY_TRUE, __VA_OPT__(_FALSE))(true, false)

#define __PRT_IS_EMPTY_TRUE(true, false) true
#define __PRT_IS_EMPTY_TRUE_FALSE(true, false) false

#include "ansi_escape_print_impl.h"


// ASCII C0 control characters
#define PRT_BELL      "\x07"
#define PRT_BACKSPACE "\x08"
#define PRT_HTAB      "\x09"
#define PRT_LF        "\x0A"
#define PRT_CR        "\x0D"
#define PRT_ESC       "\x1B"

// ASCII C1 control characters
#define PRT_INDEX      PRT_ESC "D"
#define PRT_NEXT_LINE  PRT_ESC "E"
#define PRT_REV_INDEX  PRT_ESC "M"
#define PRT_SET_HTAB   PRT_ESC "H"
#define PRT_CSI        PRT_ESC "["
#define PRT_OSC        PRT_ESC "]"

// cursor controls
#define PRT_CURSOR_UP(n)             PRT_CSI #n "A"
#define PRT_CURSOR_DOWN(n)           PRT_CSI #n "B"
#define PRT_CURSOR_FORWARD(n)        PRT_CSI #n "C"
#define PRT_CURSOR_BACK(n)           PRT_CSI #n "D"
#define PRT_CURSOR_NEXT_LINE(n)      PRT_CSI #n "E"
#define PRT_CURSOR_PREVIOUS_LINE(n)  PRT_CSI #n "F"
#define PRT_CURSOR_HORIZENTAL(n)     PRT_CSI #n "G"
#define PRT_CURSOR_POS(x, y)         PRT_CSI #y ";" #x 'H'
#define PRT_ERASE_DISPLAY(n)         PRT_CSI #n "J"
#define PRT_ERASE_LINE(n)            PRT_CSI #n "K"
#define PRT_CURSOR_LINE_UP(n)        PRT_CSI #n "M"
#define PRT_SCROLL_UP(n)             PRT_CSI #n "S"
#define PRT_SCROLL_DOWN(n)           PRT_CSI #n "T"
#define PRT_CURSOR_SAVE_POS()        PRT_CSI "s"
#define PRT_CURSOR_RESTORE_POS()     PRT_CSI "u"
#define PRT_CURSOR_SAVE_POS_DEC()    PRT_ESC "7"
#define PRT_CURSOR_RESTORE_POS_DEC() PRT_CSI "8"
#define PRT_CURSOR_REQUEST_POS()     PRT_CSI "6n"
#define PRT_INSERT_CHAR(n)           PRT_CSI #n "@"
#define PRT_DELECTE_CHAR(n)          PRT_CSI #n "P"
#define PRT_ERASE_CHAR(n)            PRT_CSI #n "X"


// text formatting controls
#define PRT_RESET             "0"
#define PRT_BRIGHT            "1"  //! Depends on terminal implementation
#define PRT_BOLD              "1"
#define PRT_FAINT             "2"
#define PRT_ITALIC            "3"
#define PRT_UNDERLINE         "4"
#define PRT_INVERT            "7"
#define PRT_HIDE              "8"
#define PRT_STRIKE            "9"
#define PRT_NOT_BOLD          "21"
#define PRT_DOUBLE_UNDERLINE  "21"  //! Depends on terminal implementation
#define PRT_NORMAL            "22"
#define PRT_NOT_ITATIC        "23"
#define PRT_NOT_UNDERLINE     "24"
#define PRT_NOT_INVERT        "27"
#define PRT_NOT_HIDE          "28"
#define PRT_NOT_STRIKE        "29"

#define PRT_COLOR_BLACK   "30"
#define PRT_COLOR_RED     "31"
#define PRT_COLOR_GREEN   "32"
#define PRT_COLOR_YELLOW  "33"
#define PRT_COLOR_BLUE    "34"
#define PRT_COLOR_MAGENTA "35"
#define PRT_COLOR_CYAN    "36"
#define PRT_COLOR_WHITE   "37"
#define PRT_COLOR_RESET   "39"

#define PRT_COLOR_BRIGHT_BLACK   "90"
#define PRT_COLOR_BRIGHT_RED     "91"
#define PRT_COLOR_BRIGHT_GREEN   "92"
#define PRT_COLOR_BRIGHT_YELLOW  "93"
#define PRT_COLOR_BRIGHT_BLUE    "94"
#define PRT_COLOR_BRIGHT_MAGENTA "95"
#define PRT_COLOR_BRIGHT_CYAN    "96"
#define PRT_COLOR_BRIGHT_WHITE   "97"

#define PRT_BACKGROUND_BLACK   "40"
#define PRT_BACKGROUND_RED     "41"
#define PRT_BACKGROUND_GREEN   "42"
#define PRT_BACKGROUND_YELLOW  "43"
#define PRT_BACKGROUND_BLUE    "44"
#define PRT_BACKGROUND_MAGENTA "45"
#define PRT_BACKGROUND_CYAN    "46"
#define PRT_BACKGROUND_WHITE   "47"
#define PRT_BACKGROUND_RESET   "49"

#define PRT_BACKGROUND_BRIGHT_BLACK   "100"
#define PRT_BACKGROUND_BRIGHT_RED     "101"
#define PRT_BACKGROUND_BRIGHT_GREEN   "102"
#define PRT_BACKGROUND_BRIGHT_YELLOW  "103"
#define PRT_BACKGROUND_BRIGHT_BLUE    "104"
#define PRT_BACKGROUND_BRIGHT_MAGENTA "105"
#define PRT_BACKGROUND_BRIGHT_CYAN    "106"
#define PRT_BACKGROUND_BRIGHT_WHITE   "107"

#define PRT_COLOR8(n) "38:5:" #n
#define PRT_BACKGROUND8(n) "48:5:" #n

#define PRT_COLOR(r, g, b) "38;2;" #r ";" #g ";" #b
#define PRT_BACKGROUND(r, g, b) "48;2;" #r ";" #g ";" #b

#define PRT_FORMAT(...) \
    PRT_CSI __PRT_FORMAT(__VA_ARGS__) "m"

#define PRT_END PRT_FORMAT(PRT_RESET)

#endif /* __ANSI_ESCAPE_PRINT__ */
