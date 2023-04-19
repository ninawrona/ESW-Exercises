typedef struct Rectangle *rect;

rect rect_create(int height, int width);
int rect_get_area(rect self);
int rect_get_perimeter(rect self);
void rect_print_rectangle_info(rect self);
