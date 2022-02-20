#include <iostream>
#include <string>
#include "shape.h"
using namespace std;

Shape::Shape(SimpleCanvas* canvas, float thickness, int color[3]) {
    this->canvas = canvas;
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
void Shape::draw() {
    cout << "Warning: Calling draw on base class";
}

float Shape::getArea() {
    cout << "Warning: Calling getArea on base class";
    return 0;
}

string Shape::toString() {
    return "Shape";
}
