#include "simplecanvas/simplecanvas.h"
#include "point.h"
#include <string>
#include <sstream>
using namespace std;


/**
 * Constructor for a point
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param ax X coordinate of the point
 * @param ay Y coordinate of the point
 */
Point::Point(SimpleCanvas* canvas, float thickness, int color[3], float ax, float ay):Shape(canvas, thickness, color) {
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

void Point::draw() {
    cout << "Drawing point\n";
    this->canvas->fillCircle((int)ax, (int)ay, thickness, color[0], color[1], color[2]);
}

string Point::toString() {
    stringstream stream;
    stream << "Point(" << ax << ", " << ay << ")";
    return stream.str();
}