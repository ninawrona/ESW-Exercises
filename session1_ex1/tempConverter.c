#include<stdio.h>
/* print Fahrenheit-Celsius tablefor fahr = 0, 20, ..., 300 */
main()
{
    setbuf(stdout, NULL);
    int fahr, 
    celsius,
    kelv;
    int lower, 
    upper, 
    step;
    lower= 0;/* lower limit of temperature scale */
    upper= 300;/* upper limit */
    step= 20;/* step size */
    fahr= lower;
    printf("%s\t%s\t%s\n", "Fahr", "Celsius", "Kelvin");
    while(fahr<= upper){
        celsius= 5* (fahr-32) / 9;
        kelv = celsius + 274;
        printf("%d\t%d\t%d\n", fahr, celsius, kelv);
        fahr= fahr+ step;
        }
}