#include "shape.h"
#include "point.h"
#include "linesegment.h"
#include "simplecanvas/simplecanvas.h"
#include <iostream>

using namespace std;

int main() {
    SimpleCanvas canvas(500, 500);
    canvas.clearRect(255, 255, 255);
    int color[3] = {255, 0, 0};
    float thickness = 4;
    Point p1(&canvas, thickness, color, 100, 100);
    Point p2(&canvas, thickness, color, 400, 400);
    LineSegment line(&canvas, thickness, color, p1, p2);
    line.draw();
    cout << line.toString() << "\n";
    canvas.write("out.png");
}
