#include <stdio.h>
#include "rectangle.h"
#include "rectangleImpl.c"

int main()
{
    // 1

    struct Rectangle *reccy1 = rect_create(3, 5);

    int area = rect_get_area(reccy1);
    printf("Area of reccy: %d\n", area);

    int perimeter = rect_get_perimeter(reccy1);
    printf("Perimeter of reccy: %d\n", perimeter);

    rect_print_rectangle_info(reccy1);

    // 2

    struct Rectangle *reccy2 = rect_create(9, 5);

    int area2 = rect_get_area(reccy2);
    printf("Area of reccy: %d\n", area2);

    int perimeter2 = rect_get_perimeter(reccy2);
    printf("Perimeter of reccy: %d\n", perimeter2);

    rect_print_rectangle_info(reccy2);

    // 3

    struct Rectangle *reccy3 = rect_create(3, -1);

    int area3 = rect_get_area(reccy3);
    printf("Area of reccy: %d\n", area3);

    int perimeter3 = rect_get_perimeter(reccy3);
    printf("Perimeter of reccy: %d\n", perimeter3);

    rect_print_rectangle_info(reccy3);

    // 4

    struct Rectangle *reccy4 = rect_create(3, 0);

    int area4 = rect_get_area(reccy4);
    printf("Area of reccy: %d\n", area4);

    int perimeter4 = rect_get_perimeter(reccy4);
    printf("Perimeter of reccy: %d\n", perimeter4);

    rect_print_rectangle_info(reccy4);

    // 5

    struct Rectangle *reccy5 = rect_create(3, 3);

    int area5 = rect_get_area(reccy5);
    printf("Area of reccy: %d\n", area5);

    int perimeter5 = rect_get_perimeter(reccy5);
    printf("Perimeter of reccy: %d\n", perimeter5);

    rect_print_rectangle_info(reccy5);

    return 0;
}