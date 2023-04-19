#include <stdio.h>
#include "my_string_func.h"
/* read_line: read a line into s, return length */
int my_length(char* text){
    size_t i;

    // text[i] -> continue as long as there are variables in the array
    for (i = 0; text[i]; i++);
    return i;
}

void my_to_upper(char* str_in, char* str_out){
    /* You must implement your own version of toupper using 
    the two strings str_in and str_out.Loop over the 
    str_in (as long as it "contains" something).
    Look at the "current" character and check
     if its a lowercase letter.If it is, convert it to 
     the upper case version and add that to thestr_out 
     character array*/

    for(int i = 0; str_in[i]; i++){
       if( str_in[i] > 96 && str_in[i] < 123){
        str_in[i] = str_in[i]-32;
        str_out[i] = str_in[i];
       }
       str_out[i] = str_in[i];
    }

}
     
int read_line(char s[]){
    int c= 0;
    int i= 0;
    int done= 0;
    do{
        c= getchar();
        if(c== EOF|| c== '\n')
        {
            done= 1;
        }
        else
        {
            s[i++] = c;
        }
    } while(!done);
    s[i] = '\0';
    return i;
}

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


int my_strcmp(const char* str1, const char* str2) {

    for (int i = 0; i < my_strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

char* my_strcpy(char* dest, const char* src) {

    int i;

    for (i = 0; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }

    return dest;
}


char* my_strdup(const char* str) {
    //char* dst = malloc(my_strlen(str) + 1);
    //if (dst == NULL) return NULL;

    //my_strcpy(dst, str);
    return NULL;
}