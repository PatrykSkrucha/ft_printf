# ft_printf

> My own implementation of **`printf`**, built with variadic arguments.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

## About

`ft_printf` walks through the format string, writes plain characters as they are, and for every
`%` conversion pulls the next argument from a `va_list` and prints it. Like the real `printf`,
it returns the number of characters printed.

```c
int ft_printf(const char *format, ...);
```

## Supported conversions

| Conversion | Prints |
|---|---|
| `%c` | a character |
| `%s` | a string |
| `%p` | a pointer address in hexadecimal |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | a hexadecimal number, lower / upper case |
| `%%` | a percent sign |

## Build & use

```bash
make            # builds libftprintf.a
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! %d in hex is %x, main is at %p\n", "world", 42, 42, &main);
}
```

```bash
cc main.c libftprintf.a -o app
```

---

<sub>Part of the <a href="https://www.codam.nl/">Codam</a> (42 network) curriculum.</sub>
