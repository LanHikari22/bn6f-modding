#include "str.h"

void memcpy(void *dest, void *src, int size){
    for(int i = 0; i<size; i++){
        ((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
    }
}

int strlen(const char* s){
    char c = s[0];
    int i;
    for (i = 0; ;i++){
        if(c == '\0')
            break;
        c = s[i];
    }
    return i;
}

bool_t strequal(const char *s1, const char *s2){
    bool_t output = true;
    do{
        output &= s1[0] == s2[0];
        s1++;
        s2++;
    } while(s1[0] != 0 || s2[0] != 0);

    return output;
}
