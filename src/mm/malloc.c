// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
    /* TODO: Implement malloc(). */
    // return NULL;
    if (size == 0) {
        return NULL;
    } else {
        void *p;
        p = mmap(NULL, size, PROT_READ | PROT_WRITE,
                 MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (p == MAP_FAILED) {
            return NULL;
        } else {
            mem_list_add(p, size);
            return p;
        }
    }
}

void *calloc(size_t nmemb, size_t size) {
    /* TODO: Implement calloc(). */
    size_t newsize = nmemb * size;
    void *p;
    p = malloc(newsize);
    if (p == NULL) {
        return NULL;
    } else {
        memset(p, 0, newsize);
        mem_list_add(p, newsize);
        return p;
    }
}

void free(void *ptr) {
    /* TODO: Implement free(). */
    if (ptr != NULL) {
        struct mem_list *elem = mem_list_find(ptr);
        if (elem != NULL) {
            munmap(ptr, elem->len);
            mem_list_del(ptr);
        }
    }
}

void *realloc(void *ptr, size_t size) {
    /* TODO: Implement realloc(). */
    // return NULL;
    if (ptr == NULL) {
        void *p = malloc(size);
        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
    if (ptr != NULL && size == 0) {
        free(ptr);
        return NULL;
    } else {
        void *p1 = malloc(size);
        if (p1 == NULL) {
            return NULL;
        } else {
            memcpy(p1, ptr, size);
            free(ptr);
            mem_list_del(ptr);
            mem_list_add(p1, size);
            return p1;
        }
    }
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    /* TODO: Implement reallocarray(). */
    // return NULL;
    size_t newsize;
    newsize = nmemb * size;
    void *p;
    p = realloc(ptr, newsize);
    if (p == NULL) {
        return NULL;
    } else {
        return p;
    }
}
