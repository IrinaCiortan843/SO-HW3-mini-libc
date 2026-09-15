// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int puts(char* s) {
    while (*s != '\0') {
        write(1, s, 1);
        s++;
    }
    write(1, "\n", 1);
    return 1;
}
