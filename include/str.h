#ifndef STR_H
#define STR_H

#include <inttypes.h>

void memcpy(void *dest, void *src, int size);

int strlen(const char* s);

bool_t strequal(const char *s1, const char *s2);


#endif // STR_H