
# ANSI Escape Print

使用 ANSI 转义码实现漂亮的控制台彩色输出。

Beautify console output using ANSI escape codes.

## Usage

```c
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
// print with dynamic background color
for (int r = 255; r > 40; r -= 15) {
    for (int g = 0, b = 255; g < 200; (g += 10), (b -= 10))
        printf(PRT_FORMAT(PRT_BACKGROUND(%d, %d, %d)) " " PRT_END, r, g, b);
    putchar('\n');
}
```

一些问题：

* 为了实现默认参数，用到了 `IS_EMPTY` 宏，但是目前没想到比较好的实现，所以偷懒用了 `__VA_OPT__` ，这对编译器有一定要求
