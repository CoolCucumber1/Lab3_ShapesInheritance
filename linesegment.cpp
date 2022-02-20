#include "simplecanvas/simplecanvas.h"
#include "linesegment.h"
#include "point.h"
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

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
 * Update the first point
 * @param a Set the point a
 */
void LineSegment::setA(Point a) {
    this->a = a;
}


/**
 * Update the first point
 * @param a Set the point a
 */
void LineSegment::setB(Point b) {
    this->b = b;
}



/**
 * Return the first point on the line segment
 * @return Point The first point
 */
Point LineSegment::getA() {
    return a;
}

/**
 * Return the first point on the line segment
 * @return Point The first point
 */
Point LineSegment::getB(){
    return b;
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
