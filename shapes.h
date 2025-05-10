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

class Triangle:public Shape {
    private:
        Point a;
        Point b;
        Point c;
        LineSegment ab;
        LineSegment bc;
        LineSegment ca;

    public:
        /**
         * Constructor for a triangle
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         * @param c The third point
         */
        Triangle(float thickness, int color[3], Point a, Point b, Point c);

        // Dummy constructor for empty object declarations
        Triangle(){};

        /**
         * Get the area of a triangle
         * @return The area of the triangle
         */
        float getArea();

        /**
         * Draw the triangle to a particular canvas
         * @param canvas Pointer to canvas
         */
        void draw(SimpleCanvas* canvas);
        string toString();
};

class Square:public Shape {
    private:
        Point center;
        float length;
        LineSegment a;
        LineSegment b;
        LineSegment c;
        LineSegment d;

    public:
        /**
         * Constructor for a square
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param center Center point of the square
         * @param length Length of all square sides
         */
        Square(float thickness, int color[3], Point center, float length);

        // Dummy constructor for empty object declarations
        Square(){};

        /**
         * Get the area of a square
         * @return The area of the square
         */
        float getArea();

        /**
         * Draw the square to a particular canvas
         * @param canvas Pointer to canvas
         */
        void draw(SimpleCanvas* canvas);
        string toString();
};

class Circle:public Shape {
    private:
        Point center;
        float radius;
        int NOS;
        LineSegment* segments;

    public:
        /**
         * Constructor for a circle
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param center Center point of the circle
         * @param radius Radius of the circle
         * @param NOS Number of sides that circle will have
         */
        Circle(float thickness, int color[3], Point center, float radius, int NOS);

        // Dummy constructor for empty object declarations
        Circle(){};

        /**
         * Get the area of a circle
         * @return The area of the circle
         */
        float getArea();

        /**
         * Draw the circle to a particular canvas
         * @param canvas Pointer to canvas
         */
        void draw(SimpleCanvas* canvas);
        string toString();
}; 
#endif