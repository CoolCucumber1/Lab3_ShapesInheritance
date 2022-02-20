#include "simplecanvas/simplecanvas.h"
#include "linesegment.h"
#include "point.h"
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

/**
 * Line segment constructor
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param ax X coordinate of first point
 * @param ay Y coordinate of first point
 * @param bx X coordinate of second point
 * @param by Y coordinate of second point
 */
LineSegment::LineSegment(SimpleCanvas* canvas, float thickness, int color[3],
                    float ax, float ay, float bx, float by)
                    :Shape(canvas, thickness, color) {
    Point thisa(canvas, thickness, color, ax, ay);
    Point thisb(canvas, thickness, color, bx, by);
    this->a = thisa;
    this->b = thisb;
}

/**
 * An alternative line segment constructor that accepts point objects
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param a The first point
 * @param b The second point
 */
LineSegment::LineSegment(SimpleCanvas* canvas, float thickness, int color[3], 
                        Point a, Point b):Shape(canvas, thickness, color) {
    this->a = a;
    this->b = b;
}

/**
 * Update the coordinates of the first point
 * @param ax X coordinate of first point
 * @param ay Y coordinate of first point
 */
void LineSegment::setA(float ax, float ay) {
    Point seta(canvas, thickness, color, ax, ay);
    this->a = seta;
}


/**
 * Update the coordinates of the second point
 * @param bx X coordinate of second point
 * @param by Y coordinate of second point
 */
void LineSegment::setB(float bx, float by) {
    Point setb(canvas, thickness, color, bx, by);
    this->b = setb;
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

void LineSegment::draw() {
    canvas->drawLine(a.getX(), a.getY(), b.getX(), b.getY(), thickness, color[0], color[1], color[2]);
}

string LineSegment::toString() {
    stringstream stream;
    stream << "Line Segment from " << a.toString() + " to " << b.toString();
    return stream.str();
}
