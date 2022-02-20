#ifndef POINT_H
#define POINT_H

#include "simplecanvas/simplecanvas.h"
#include "shape.h"
#include <iostream>
#include <string>
using namespace std;


class Point: public Shape {
    private:
        float ax;
        float ay;
    
    public:
        /**
         * Constructor for a point
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param ax X coordinate of the point
         * @param ay Y coordinate of the point
         */
        Point(SimpleCanvas* canvas, float thickness, int color[3], float ax, float ay);
        Point(){};

        void setX(float ax);
        void setY(float ay);
        float getX();
        float getY();
        float getArea();
        void draw();
        string toString();
};

#endif