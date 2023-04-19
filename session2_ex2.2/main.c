#include<stdio.h>
#include<stdint.h>
#include "division.h"
#include <float.h>

main()
{
int c, d;
c=7;
d=3;

/*We need float numbers to receive a proper float result of the equation*/
float a, b;
a=7;
b=3;

    printf("%d\t/\t%d\t=\t%d\n", c,d, div_with_reminder(c,d));
    printf("%f\t/\t%f\t=\t%f\n", a, b, div_without_reminder(a,b));
}
