#include <stdio.h>
#include "calculations.h"

main()
{

    int a = 2, b= 3;
    int x=2, y=5, z=7;

    printf ("%d\t^\t%d\t=\t%d\n", a, b, power(a,b));

    /*We use "&" to specify this is a pointer to a memory location.*/
    multiswap(&x, &y, &z);
    printf ("%d\t, \t%d\t, \t%d\n", x, y, z);
}

