#include "shapes.h"
#include "simplecanvas/simplecanvas.h"
#include <iostream>

using namespace std;

int main() {
    SimpleCanvas canvas(500, 500);
    canvas.clearRect(255, 255, 255);
    // int color[3] = {255, 0, 0};
    float thickness = 4;
    // Point p1(thickness, color, 100, 100);
    // Point p2(thickness, color, 400, 400);
    // LineSegment line(thickness, color, p1, p2);
    // line.draw(&canvas);
    // cout << line.toString() << "\n";
    // cout << "Length = " << line.getLength() << "\n";

// Triangle Test
    int cyan[3] = {0, 255, 255};
    Point a(thickness, cyan, 100, 400);
    Point b(thickness, cyan, 400, 400);
    Point c(thickness, cyan, 250, 100);
    Triangle tri(thickness, cyan, a, b, c);    
    tri.draw(&canvas);
    cout << tri.toString() << "\n";
    cout << "Area = " << tri.getArea() << "\n";

// // Square Test
//     int blue[3] = {0, 0, 255};
//     float len = 200;
//     Point center(thickness, blue, 150, 150);
//     Square square(thickness, blue, center, len);
//     square.draw(&canvas);
//     cout << square.toString() << "\n";
//     cout << "Area = " << square.getArea() << "\n";
//     float thickness2 = 1;
//     int green[3] = {0, 255, 0};
//     Point center2(thickness2, green, 250, 250);
//     float len2 = 100;
//     Square square2(thickness2, green, center2, len2);
//     square2.draw(&canvas);
//     cout << square2.toString() << "\n";
//     cout << "Area = " << square2.getArea() << "\n";

//     // Circle Test
//     int orange[3] = {255, 165, 0};
//     float radius = 100;
//     int NOS = 15;
//     Circle circle(thickness, blue, center, radius, NOS);
//     circle.draw(&canvas);
//     cout << circle.toString() << "\n";
//     cout << "Area = " << circle.getArea() << "\n";
//     float thickness3 = 2;
//     float radius2 = 50;
//     int NOS2 = 100;
//     Point center3(thickness3, orange, 350, 350);
//     Circle circle2(thickness3, orange, center3, radius2, NOS2);
//     circle2.draw(&canvas);
//     cout << circle2.toString() << "\n";
//     cout << "Area = " << circle2.getArea() << "\n";

    // Write the canvas to a file   
        canvas.write("out.png");
}
