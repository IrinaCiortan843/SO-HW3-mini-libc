// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
    /* TODO: Implement strcpy(). */
    char *p = destination;
    while (*source != '\0') {
        *p = *source;
        p++;
        source++;
    }
    *p = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncpy(). */
    char *p = destination;
    while (*source != '\0' && len > 0) {
        *p = *source;
        p++;
        source++;
        len--;
    }
    if (len != 0) {
        while (len != 0) {
            *p = '\0';
            p++;
            len--;
        }
    }
    return destination;
}

char *strcat(char *destination, const char *source) {
    /* TODO: Implement strcat(). */
    char *p = destination;
    while (*p != '\0') {
        p++;
    }
    while (*source != '\0') {
        *p = *source;
        p++;
        source++;
    }
    *p = '\0';
    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncat(). */
    char *p = destination;
    while (*p != '\0') {
        p++;
    }
    while (*source != '\0' && len > 0) {
        *p = *source;
        p++;
        source++;
        len--;
    }
    *p = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2) {
    /* TODO: Implement strcmp(). */
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;
        }
        if (*str1 < *str2) {
            return -1;
        }
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    }
    if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    }
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    /* TODO: Implement strncmp(). */
    while (*str1 != '\0' && *str2 != '\0' && len > 0) {
        if (*str1 > *str2) {
            return 1;
        }
        if (*str1 < *str2) {
            return -1;
        }
        str1++;
        str2++;
        len--;
    }
    return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {
    /* TODO: Implement strchr(). */
    const char *p = str;
    while (*p != '\0') {
        if (*p == c) {
            return (char *)p;
        }
        p++;
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    /* TODO: Implement strrchr(). */
    const char *p = str;
    const char *p1 = str;
    while (*p != '\0') {
        if (*p == c) {
            p1 = p;
        }
        p++;
    }
    if (p1 != str) {
        return (char*)p1;
    }
    return NULL;
}

char *strstr(const char *haystack, const char *needle) {
    /* TODO: Implement strstr(). */
    const char *p = haystack;
    const char *p1 = needle;
    //char *p2;           // found
    while (*p != '\0')  // haystack!=end
    {
        if (*p == *p1) {
            const char *temp = p;
            const char *p4 = p;
            const char *p3 = p1;
            int found = 1;
            while (*temp != '\0' && *p3 != '\0') {
                if (*temp != *p3) {
                    found = 0;
                    break;
                }
                temp++;
                p3++;
            }
            if (found == 1 && *p3 == '\0') {
                return (char *)p4;
            }
        }
        p++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    /* TODO: Implement strrstr(). */
    const char *p = haystack;
    const char *p1 = needle;
    char *p2 = NULL;    // found
    while (*p != '\0')  // haystack!=end
    {
        if (*p == *p1) {
            const char *temp = p;
            const char *p4 = p;
            const char *p3 = p1;
            int found = 1;
            while (*temp != '\0' && *p3 != '\0') {
                if (*temp != *p3) {
                    found = 0;
                    break;
                }
                temp++;
                p3++;
            }
            if (found == 1 && *p3 == '\0') {
                p2 = (char*)p4;
            }
        }
        p++;
    }
    if (p2 != NULL) {
        return p2;
    }
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
    /* TODO: Implement memcpy(). */
    char *p = destination;
    const char *p1 = source;
    while (num > 0 && p != NULL && p1 != NULL) {
        *p = *p1;
        p++;
        p1++;
        num--;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    /* TODO: Implement memmove(). */
    char *d = destination;
    const char *s = source;

    if (d <= s) {
        while (num > 0) {
            *d = *s;
            d++;
            s++;
            num--;
        }
    } else {
        d = d + num - 1;
        s = s + num - 1;
        while (num > 0) {
            *d = *s;
            d--;
            s--;
            num--;
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    /* TODO: Implement memcmp(). */
    const char *p1 = ptr1;
    const char *p2 = ptr2;

    while (p1 != NULL && p2 != NULL && num > 0) {
        if (*p1 > *p2) {
            return -1;
        }

        if (*p1 < *p2) {
            return 1;
        }
        p1++;
        p2++;
        num--;
    }
    return 0;
}

void *memset(void *source, int value, size_t num) {
    /* TODO: Implement memset(). */
    char *p = source;
    while (num > 0 && p != NULL) {
        *p = value;
        p++;
        num--;
    }
    return source;
}
