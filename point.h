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
         * @param thickness Radius of the point when drawing
         * @param color Color to draw
         * @param ax X coordinate of the point
         * @param ay Y coordinate of the point
         */
        Point(float thickness, int color[3], float ax, float ay);

        // Dummy constructor for empty object declarations
        Point(){};

        void setX(float ax);
        void setY(float ay);
        float getX();
        float getY();
        float getArea();
        void draw(SimpleCanvas* canvas);
        string toString();
};

#endif