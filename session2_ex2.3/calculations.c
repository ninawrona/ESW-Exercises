#include <stdio.h>

int power(int a, int b)
{
    int result = a;

    for(int i = 1; i<b; i++){
        result=result*a;
    }
    return result;
}


/*After a call to multiSwap, x should be equal to the old y, 
    y should be equal to the old z and z should be equal to the old x.*/

/* We use "*" to define that here we are using the content of the memory location that was passed. */
void multiswap(int* x, int* y, int* z)
{
    int temp;
    temp = *x;

    *x = *y;
    *y = *z;
    *z = temp;

}