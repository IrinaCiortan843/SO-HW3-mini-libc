#include <errno.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int nanosleep(const struct timespec *dur, struct timespec *rem) {
    long ret = syscall(__NR_nanosleep, dur, rem);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return 0;
    }
}
