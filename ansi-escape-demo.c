
#include <stdio.h>

#include "ansi_escape_print.h"


int main(int argc, char* argv[]) {

    // print with red color
    puts(PRT_FORMAT(PRT_COLOR_RED) "Hello World" PRT_END);
    // print with green color and black background
    puts(PRT_FORMAT(PRT_COLOR_GREEN, PRT_BACKGROUND_BLACK) "Hello World" PRT_END);
    // print with bold and underlined style
    puts(PRT_FORMAT(PRT_COLOR_CYAN, PRT_BRIGHT, PRT_UNDERLINE)
         "Hello World" PRT_END);
    // print with custom color and background
    puts(PRT_FORMAT(PRT_COLOR(47, 74, 155), PRT_BACKGROUND(255, 102, 98))
         "Hello World" PRT_END);
    // print at another position
    puts(PRT_CURSOR_UP(2) PRT_CURSOR_FORWARD(12) "And C Language!" PRT_CURSOR_DOWN() PRT_END);
    // dynamic background color printing
    for (int r = 255; r > 40; r -= 15) {
        for (int g = 0, b = 255; g < 200; (g += 10), (b -= 10))
            printf(PRT_FORMAT(PRT_BACKGROUND(%d, %d, %d)) " " PRT_END, r, g, b);
        putchar('\n');
    }


    return 0;
}