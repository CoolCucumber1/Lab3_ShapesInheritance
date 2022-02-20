#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "simplecanvas/simplecanvas.h"
#include "shape.h"
#include "point.h"
#include <iostream>
#include <string>
using namespace std;

class LineSegment: public Shape {
    private:
        Point a;
        Point b;
    
    public:
        /**
         * Line segment constructor
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param ax X coordinate of first point
         * @param ay Y coordinate of first point
         * @param bx X coordinate of second point
         * @param by Y coordinate of second point
         */
        LineSegment(SimpleCanvas* canvas, float thickness, int color[3],
                        float ax, float ay, float bx, float by);
        
        /**
         * An alternative line segment constructor that accepts point objects
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         */
        LineSegment(SimpleCanvas* canvas, float thickness, int color[3], Point a, Point b);
        
        /**
         * Update the coordinates of the first point
         * @param ax X coordinate of first point
         * @param ay Y coordinate of first point
         */
        void setA(float ax, float ay);
        
        
        /**
         * Update the coordinates of the second point
         * @param bx X coordinate of second point
         * @param by Y coordinate of second point
         */
        void setB(float bx, float by);
        
        /**
         * Get the length of this line segment by using the 
         * Pythagorean theorem
         * @return The length of the line segment
         */
        float getLength();
        
        /**
         * Get the area of a line segment
         * @return 0; A line segment has zero area
         */
        float getArea();
        void draw();
        string toString();
};

#endif