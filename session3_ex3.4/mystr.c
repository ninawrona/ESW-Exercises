#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystr.h"


int my_strlen(const char* str)
{
    int i = 0;

    if ((str != NULL) && (str[0] == '\0')) {
        return 0;
    }

    while (str != '\0')
    {
        str++;
        i++;
    }
    

    return i;
}


int my_strcmp(const char* str1, const char* str2){

    for(int i = 0; i<my_strlen(str1); i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

char* my_strcpy(char* dest, const char* src){

    int i;

    for(i=0; i< my_strlen(src); i++){
        dest[i] = src[i];
    }

    return dest;
}


char* my_strdup(const char* str){
    char* dst = malloc(my_strlen(str)+1);
    if(dst == NULL) return NULL;

    my_strcpy(dst, str);
    return dst;
}
