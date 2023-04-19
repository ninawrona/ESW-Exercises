#include <stdio.h>
#include "my_string_func.h"
#define MAX_LENGTH 1000
#pragma warning(disable:4996)

int main(){
    
    char line[MAX_LENGTH];
    char upper[MAX_LENGTH];
    int line_length;

    /* Use a while loop to read input lines as long as there are any.
    For each input line, print the length of the line as well asthe upper case version of the line
    NOTE You are NOT allowed to use the standard toupper(...)function in string.h*/

    while(line != "")
        {
        printf("Enter some text: ");
        scanf("%s", line);
        printf("%s", line);
        my_to_upper(line, upper);
        line_length = my_length(line);
        printf("Length: %d\t Uppercase: %s\n", line_length, upper);
        }
        return 0;
}