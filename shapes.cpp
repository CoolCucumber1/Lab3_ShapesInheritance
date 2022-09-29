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