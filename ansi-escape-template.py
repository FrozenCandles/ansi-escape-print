
from sys import argv

try:
    n = int(argv[1])
except IndexError:
    raise SystemExit(f'Usage: py {argv[0]} n') from None
except ValueError:
    raise SystemExit('arg n must be an integer') from None


with open('ansi_escape_print_impl.h', 'w', encoding='utf8') as f:
    f.write('#ifndef __ANSI_ESCAPE_PRINT_IMPL__\n')
    f.write('#define __ANSI_ESCAPE_PRINT_IMPL__\n\n')

    f.write('#define __PRT_FORMAT_N(')
    f.write(', '.join([f'_{j}' for j in range(1, n+1)]))
    f.write(', NAME, ...) NAME\n\n')

    for i in range(1, n+1):
        f.write(f'#define __PRT_FORMAT_{i}(')
        f.write(', '.join([f'_{j}' for j in range(1, i+1)]))
        f.write(') ')
        f.write(' ";" '.join([f'_{j}' for j in range(1, i+1)]))
        f.write('\n')

    f.write('\n#define __PRT_FORMAT(...) \\\n')
    f.write('    __PRT_EXPAND(__PRT_FORMAT_N(__VA_ARGS__, \\\n')
    for i in range(n, 0, -1):
        f.write(f'        __PRT_FORMAT_{i}, \\\n')

    f.write('    )(__VA_ARGS__))\n')

    f.write('\n#endif /* __ANSI_ESCAPE_PRINT_IMPL__ */\n')
