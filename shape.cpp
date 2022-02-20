#include "simplecanvas/simplecanvas.h"
#include <string>
#include "shape.h"
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
