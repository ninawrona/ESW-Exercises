#include<stdio.h>
#include<stdint.h>


main(){

    //setbuf(stdout, NULL);
    char c;
    int n;
    char text[20];

    printf("Enter first char: ");
    scanf("%c", &c); //takes char input from the user

    printf("Enter first number: ");
    scanf("%d", &n);

    printf("Your answers: %c, %d ", c, n);

    printf("Enter a text: ");
    scanf("%s",text);

    printf("%s", text);

}