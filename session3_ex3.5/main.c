#include <stdio.h>
#include "rectangle.h"

struct rectangle {
    int length;
    int width;
};

int main(){
    
    struct rectangle rect1 = {2, 3};
    struct rectangle rect2 = {2, 4};

    //r_calculate_area(rect1);
    r_compare(&rect1, &rect1);
    r_compare(&rect1, &rect2);

    return 0;
}