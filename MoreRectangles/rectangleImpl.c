#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

typedef struct Rectangle
{
    int height;
    int width;
} Rectangle;

// Constructor
rect rect_create(int height, int width)
{
    if (height <= 0)
    {
        return NULL;
    }

    if (width <= 0)
    {
        return NULL;
    }

    rect _newRect = calloc(1, sizeof(Rectangle));

    if (NULL == _newRect)
    {
        return NULL;
    }

    _newRect->height = height;
    _newRect->width = width;

    return _newRect;
}

int rect_get_area(rect self)
{
    if (NULL == self)
    {
        printf("\nThis rectangle cannot exist");
        return NULL;
    }
    int area = self->height * self->width;
    return area;
}

int rect_get_perimeter(rect self)
{
    if (NULL == self)
    {
        printf("\nThis rectangle cannot exist");
        return NULL;
    }
    int perimeter = self->height * 2 + self->width * 2;
    return perimeter;
}

void rect_print_rectangle_info(rect self)
{
    if (NULL == self)
    {
        printf("\nThis rectangle cannot exist");
        return;
    }

    printf("\nThis rectangle has width %d and height %d\n", self->width, self->height);
}
