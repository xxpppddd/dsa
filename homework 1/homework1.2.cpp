#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};

class Line {
public:
    Point p1, p2;
    Line(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
};
// ax1 + b = y1
// ax2 + b = y2

bool isParallel(Line l1, Line l2) {
    double D1 = l1.p1.x - l1.p2.x;
    double DX1 = l1.p1.y - l1.p2.y;
    double DY1 = - l1.p1.y * l1.p2.x + l1.p1.x * l1.p2.y;
    double D2 = l2.p1.x - l2.p2.x;
    double DX2 = l2.p1.y - l2.p2.y;
    double DY2 = - l2.p1.y * l2.p2.x + l2.p1.x * l2.p2.y;

    if (D1 == 0 and D2 == 0 and l1.p1.x != l2.p1.x) return true;

    double a1 = DX1/D1;
    double b1 = DY1/D1;
    double a2 = DX2/D2;
    double b2 = DY2/D2;

    double D = - a1 + a2;
    double Dx = b1 - b2;
    double Dy = - a1 * b2 + b1 * a2;

    if (a1 == a2 and b1 != b2) return true;
    return false;
}
bool isTheSame(Line l1, Line l2) {
    double D1 = l1.p1.x - l1.p2.x;
    double DX1 = l1.p1.y - l1.p2.y;
    double DY1 = - l1.p1.y * l1.p2.x + l1.p1.x * l1.p2.y;
    double D2 = l2.p1.x - l2.p2.x;
    double DX2 = l2.p1.y - l2.p2.y;
    double DY2 = - l2.p1.y * l2.p2.x + l2.p1.x * l2.p2.y;

    if (D1 == 0 and D2 == 0 and l1.p1.x == l2.p1.x) return true;

    double a1 = DX1/D1;
    double b1 = DY1/D1;
    double a2 = DX2/D2;
    double b2 = DY2/D2;

    double D = - a1 + a2;
    double Dx = b1 - b2;
    double Dy = - a1 * b2 + b1 * a2;


    if (a1 == a2 and b1 == b2) return true;
    return false;
}

Point getIntersection(Line l1, Line l2) {
    double D1 = l1.p1.x - l1.p2.x;
    double DX1 = l1.p1.y - l1.p2.y;
    double DY1 = - l1.p1.y * l1.p2.x + l1.p1.x * l1.p2.y;
    double D2 = l2.p1.x - l2.p2.x;
    double DX2 = l2.p1.y - l2.p2.y;
    double DY2 = - l2.p1.y * l2.p2.x + l2.p1.x * l2.p2.y;
    //x=c
    //y = a2x +b2
    double x, y;

    if (D1 == 0 and D2 != 0) {
        double a2 = DX2/D2;
        double b2 = DY2/D2;
        x = l1.p1.x;
        y = a2 * x + b2;

    }
    else if (D1 != 0 and D2 == 0) {
        double a1 = DX1/D1;
        double b1 = DY1/D1;
        x = l2.p1.x;
        y = a1 * x + b1;
    }

    else {
        double a1 = DX1/D1;
        double b1 = DY1/D1;
        double a2 = DX2/D2;
        double b2 = DY2/D2;

        double D = - a1 + a2;
        double Dx = b1 - b2;
        double Dy = - a1 * b2 + b1 * a2;
        x = Dx / D;
        y = Dy / D;
    }

    return Point(x, y);

    }
int main() {
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    Point A(Ax, Ay);
    Point B(Bx, By);
    Point C(Cx, Cy);
    Point D(Dx, Dy);

    Line AB(A, B);
    Line CD(C, D);

    if (isParallel(AB,CD)) {
        cout << "NO" << endl;
    }
    else if (isTheSame(AB, CD)) {
        cout << "MANY" << endl;
    }
    else {
        Point p = getIntersection(AB, CD);
        cout << p.x <<" " << p.y;
    }

}
