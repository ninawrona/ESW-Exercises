#include <stdio.h>
#include "mystr.h"

int main(){
    
    const char* str1 = "HelloWorld";
    const char* str2 = "HelloWorld";
    char* str3;

    printf("Length: %d\t Is the same as str2?: %d\n Is the same as an empty string?: %d\n", my_strlen(str1),my_strcmp(str1, str2), my_strcmp(str1, ""));
    
    printf("Copying str1 to str3: %s\n", my_strcpy(str3, str1));
    printf("Duplicating str1 to a new dest: %s\n", my_strdup(str1));

    return 0;
}