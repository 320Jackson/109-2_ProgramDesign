#define ShapeText(TYPE) char name[10]; \
double (*perimeter)(struct TYPE*); \
double (*area)(struct TYPE*);
#define PI 3.14

typedef struct circle {
    ShapeText(circle);
    double radius;
} Circle;

double CirclePerimeter(Circle *obj);
double CircleArea(Circle *obj);
void NewCircle(Circle *obj);

typedef struct rectangle {
    ShapeText(rectangle);
    double width, height;
} Rectangle;

double RectPerimeter(Rectangle *obj);
double RectArea(Rectangle *obj);
void NewRect(Rectangle *obj);

typedef struct square {
    ShapeText(square);
    double len;
} Square;

double SquarePerimeter(Square *obj);
double SquareArea(Square *obj);
void NewSquare(Square *obj);

typedef struct triangle {
    ShapeText(triangle);
    double a, b, c;
} Triangle;

double TrianglePerimeter(Triangle *obj);
void NewTriangle(Triangle *obj);