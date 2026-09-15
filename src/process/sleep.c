#include <errno.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec dur;
    struct timespec rem;
    dur.tv_sec = seconds;
    dur.tv_nsec = 0;

    nanosleep(&dur, &rem);
    return 0;
}
