#include "028_Struct.h"
#include <string.h>
#include <stdio.h>

double CirclePerimeter(Circle *obj) {
    return 2 * obj->radius * PI;
}
double CircleArea(Circle *obj) {
    return obj->radius * obj->radius * PI;
}
void NewCircle(Circle *obj) {
    strcpy(obj->name, "Circle");
    scanf("%lf", &obj->radius);
    obj->perimeter = CirclePerimeter;
}

double RectPerimeter(Rectangle *obj) {
    return 2 * (obj->width + obj->height);
}
double RectArea(Rectangle *obj) {
    return obj->width * obj->height;
}
void NewRect(Rectangle *obj) {
    strcpy(obj->name, "Rectangle");
    scanf("%lf%lf", &obj->height, &obj->width);
    obj->perimeter = RectPerimeter;
}

double SquarePerimeter(Square *obj) {
    return 4 * obj->len;
}
double SquareArea(Square *obj) {
    return obj->len * obj->len;
}
void NewSquare(Square *obj) {
    strcpy(obj->name, "Square");
    scanf("%lf", &obj->len);
    obj->perimeter = SquarePerimeter;
}

double TrianglePerimeter(Triangle *obj) {
    return obj->a + obj->b + obj->c;
}
void NewTriangle(Triangle *obj) {
    strcpy(obj->name, "Triangle");
    scanf("%lf%lf%lf", &obj->a, &obj->b, &obj->c);
    obj->perimeter = TrianglePerimeter;
}