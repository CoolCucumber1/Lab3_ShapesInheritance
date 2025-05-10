#include "simplecanvas/simplecanvas.h"
#include <string>
#include <sstream>
#include <math.h>
#include "shapes.h"
using namespace std;

Shape::Shape(float thickness, int color[3]) {
    this->thickness = thickness;
    for (int k = 0; k < 3; k++) {
        this->color[k] = color[k];
    }
}

/**
 * Setter method for a color
 * @param color An RGB color to set
 */
void Shape::setColor(int color[3]) {
    for (int k = 0; k < 3; k++) {
        this->color[k] = color[k];
    }
}

/**
 * Setter method for thickness
 * @param thickness The thickness
 */
void Shape::setThickness(float thickness) {
    this->thickness = thickness;
}

/**
 * Subclasses should override this method to actually draw things
 */
void Shape::draw(SimpleCanvas* canvas) {
    cout << "Warning: Calling draw on base class";
}

/**
 * Subclasses should override this method to compute an appropriate area
 */
float Shape::getArea() {
    cout << "Warning: Calling getArea on base class";
    return 0;
}

/**
 * Subclasses should override this method to return an appropriate string
 * defining this shape
 */
string Shape::toString() {
    return "Shape";
}



/////////////////////////////////////////////////////



/**
 * Constructor for a point
 * @param thickness Radius of the point when drawing
 * @param color Color to draw
 * @param ax X coordinate of the point
 * @param ay Y coordinate of the point
 */
Point::Point(float thickness, int color[3], float ax, float ay):Shape(thickness, color) {
    this->ax = ax;
    this->ay = ay;
}

void Point::setX(float ax) {
    this->ax = ax;
}

void Point::setY(float ay) {
    this->ay = ay;
}

float Point::getX() {
    return ax;
}

float Point::getY() {
    return ay;
}

/**
 * Get the area of a point
 * @return 0; A point has zero area
 */
float Point::getArea() {
    return 0.0;
}

void Point::draw(SimpleCanvas* canvas) {
    canvas->fillCircle((int)ax, (int)ay, thickness, color[0], color[1], color[2]);
}

string Point::toString() {
    stringstream stream;
    stream << "Point(" << ax << ", " << ay << ")";
    return stream.str();
}



/////////////////////////////////////////////////////




/**
 * Line segment constructor that accepts point objects
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param a The first point
 * @param b The second point
 */
LineSegment::LineSegment(float thickness, int color[3], 
                        Point a, Point b):Shape(thickness, color) {
    this->a = a;
    this->b = b;
}

/**
 * Get the length of this line segment by using the 
 * Pythagorean theorem
 * @return The length of the line segment
 */
float LineSegment::getLength() {
    float diffx = a.getX() - b.getX();
    float diffy = a.getY() - b.getY();
    return sqrt(diffx*diffx + diffy*diffy);
}

/**
 * Get the area of a line segment
 * @return 0; A line segment has zero area
 */
float LineSegment::getArea() {
    return 0.0;
}

/**
 * Draw the line segment to a particular canvas
 * @param canvas Pointer to canvas
 */
void LineSegment::draw(SimpleCanvas* canvas) {
    canvas->drawLine(a.getX(), a.getY(), b.getX(), b.getY(), thickness, color[0], color[1], color[2]);
}

string LineSegment::toString() {
    stringstream stream;
    stream << "Line Segment from " << a.toString() + " to " << b.toString();
    return stream.str();
}


/////////////////////////////////////////////////////
// TODO: Fill in Triangle, Square, and Circle

/**
 * Constructor for a triangle
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param a The first point
 * @param b The second point
 * @param c The third point
 */

Triangle::Triangle(float thickness, int color[3], 
                   Point a, Point b, Point c):Shape(thickness, color) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->ab = LineSegment(thickness, color, a, b);
    this->bc = LineSegment(thickness, color, b, c);
    this->ca = LineSegment(thickness, color, c, a);
}   
/**
 * Get the area of a triangle
 * @return The area of the triangle
 */
float Triangle::getArea() {
    float s = (ab.getLength() + bc.getLength() + ca.getLength()) / 2;
    return sqrt(s * (s - ab.getLength()) * (s - bc.getLength()) * (s - ca.getLength()));
}

/**
 * Draw the triangle to a particular canvas
 * @param canvas Pointer to canvas
 */
void Triangle::draw(SimpleCanvas* canvas) {
    ab.draw(canvas);
    bc.draw(canvas);
    ca.draw(canvas);
}

string Triangle::toString() {
    stringstream stream;
    stream << "Triangle between " << a.toString() + ", " << b.toString() + ", and " << c.toString();
    return stream.str();
}
////////////////////////////////////////////////////////////////////////////////////////

/**
 * Constructor for a square
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param center Center point of the square
 * @param length Length of all square sides
 */

Square::Square(float thickness, int color[3], 
               Point center, float length):Shape(thickness, color) {
    this->center = center;
    this->length = length;
    float HalfLength = length / 2;
    this->a = LineSegment(thickness, color, 
                Point(thickness, color, center.getX() - HalfLength, center.getY() - HalfLength), 
                Point(thickness, color, center.getX() + HalfLength, center.getY() - HalfLength));
    this->b = LineSegment(thickness, color, 
                Point(thickness, color, center.getX() + HalfLength, center.getY() - HalfLength), 
                Point(thickness, color, center.getX() + HalfLength, center.getY() + HalfLength));
    this->c = LineSegment(thickness, color, 
                Point(thickness, color, center.getX() + HalfLength, center.getY() + HalfLength), 
                Point(thickness, color, center.getX() - HalfLength, center.getY() + HalfLength));
    this->d = LineSegment(thickness, color, 
                Point(thickness, color, center.getX() - HalfLength, center.getY() + HalfLength), 
                Point(thickness, color, center.getX() - HalfLength, center.getY() - HalfLength));
}
/**
 * Get the area of a square
 * @return The area of the square
 */
float Square::getArea() {
    return length * length;
}

/**
 * Draw the square to a particular canvas
 * @param canvas Pointer to canvas
 */
void Square::draw(SimpleCanvas* canvas) {
    a.draw(canvas);
    b.draw(canvas);
    c.draw(canvas);
    d.draw(canvas);
}

string Square::toString() {
    stringstream stream;
    stream << "Square with center at " << center.toString() + " and length " << length;
    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////////////

/**
 * Constructor for a circle
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param center Center point of the circle
 * @param radius Radius of the circle
 * @param NOS Number is sides that circle will have
 */

Circle::Circle(float thickness, int color[3], 
               Point center, float radius, int NOS):Shape(thickness, color) {
    this->center = center;
    this->radius = radius;
    this->NOS = NOS;
               }
/**
 * Get the area of a circle
 * @return The area of the circle
 */
float Circle::getArea() {
    return M_PI * radius * radius;
}

/**
 * Draw the circle to a particular canvas
 * @param canvas Pointer to canvas
 */
void Circle::draw(SimpleCanvas* canvas) {
    for (int i = 0; i < NOS; i++) {
        float x1 = center.getX() + radius * cos((2 * M_PI * i) / NOS);
        float y1 = center.getY() + radius * sin((2 * M_PI * i) / NOS);
        float x2 = center.getX() + radius * cos((2 * M_PI * (i + 1)) / NOS);
        float y2 = center.getY() + radius * sin((2 * M_PI * (i + 1)) / NOS);
        LineSegment line(thickness, color, Point(thickness, color, x1, y1), Point(thickness, color, x2, y2));
        line.draw(canvas);
    }
}

string Circle::toString() {
    stringstream stream;
    stream << "Circle with center at " << center.toString() + " with a radius of " << radius;
    return stream.str();
}
////////////////////////////////////////////////////////////////////////////////////////