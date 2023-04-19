#include <stdio.h>
#include "hello.h"

int main()
{
    int ch;

    hello();
    puts("Press any key.");
    ch = getchar();
    printf("\nYou pressed: %c \n", ch);

    return 0;
}