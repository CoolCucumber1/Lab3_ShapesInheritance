#ifndef SHAPE_H
#define SHAPE_H

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
        void draw();
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

#endif