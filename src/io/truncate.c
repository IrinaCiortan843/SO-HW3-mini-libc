// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int truncate(const char *path, off_t length) {
    /* TODO: Implement truncate(). */
    if (path == NULL) {
        return -1;
    }
    if (length < 0) {
        return -1;
    }
    int ret = syscall(__NR_truncate, path, length);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return ret;
    }
}
