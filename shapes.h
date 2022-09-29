#ifndef SHAPES_H
#define SHAPES_H

#include "simplecanvas/simplecanvas.h"
#include <iostream>
#include <string>
using namespace std;

class Shape {
    protected:
        float thickness;
        int color[3];
    
    public:
        /**
         * Constructor for a shape
         * @param thickness Thickness of pen drawing
         * @param color RGB Color to draw
         */
        Shape(float thickness, int color[3]);
        
        // Dummy constructor for empty object declarations
        Shape(){};
        
        /**
         * Setter method for a color
         * @param color An RGB color to set
         */
        void setColor(int color[3]);
        
        /**
         * Setter method for thickness
         * @param thickness The thickness
         */
        void setThickness(float thickness);
        /**
         * Subclasses should override this method to actually draw things
         */
        void draw(SimpleCanvas* canvas);
        /**
         * Subclasses should override this method to compute an appropriate area
         */
        float getArea();
        /**
         * Subclasses should override this method to return an appropriate string
         * defining this shape
         */
        string toString();
};



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



class LineSegment: public Shape {
    private:
        Point a;
        Point b;
    
    public:
        /**
         * Line segment constructor that accepts point objects
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         */
        LineSegment(float thickness, int color[3], Point a, Point b);

        // Dummy constructor for empty object declarations
        LineSegment(){};
        
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

        /**
         * Draw the line segment to a particular canvas
         * @param canvas Pointer to canvas
         */
        void draw(SimpleCanvas* canvas);
        string toString();
};


#endif