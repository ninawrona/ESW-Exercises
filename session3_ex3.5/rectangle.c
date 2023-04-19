#include <stdio.h>
#include "rectangle.h"


struct rectangle {
    int length;
    int width;
};

int r_calculate_area(struct rectangle rect){

    printf("The length of rectangle is %d and its width %d\n", rect.length, rect.width);
    int area = rect.length * rect.width;

    printf("The area of rectangle is %d\n", area);
    return area;
}

int r_calculate_area2(struct rectangle* rect){

    int l = rect->length;
    int w = rect->width;

    //printf("The length of rectangle is %d and its width %d\n",l, w);
    int area = l * w;

    //printf("The area of rectangle is %d\n", area);
    return area;
}




int r_compare(struct rectangle* rec1, struct rectangle* rec2){

    int area1 = r_calculate_area2(rec1);
    int area2 = r_calculate_area2(rec2);

    if(area1 > area2){
        printf("The area of rectangle 1 is greater than the area of rectangle 2\n");
        return 1;
    }
    else if(area1 == area2){
        printf("The area of rectangle 1 is the same as the area of rectangle 2\n");
        return 0;
    }else{
        printf("The area of rectangle 1 is smaller than the area of rectangle 2\n");
        return -1;
    }

}