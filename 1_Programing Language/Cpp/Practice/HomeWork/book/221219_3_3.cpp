#include <iostream>

using namespace std;

class Point {
public:
    Point(float a, float b) : x(a), y(b) {}
    virtual ~Point() { cout << "executing Point destructor" << endl; }
private:
    float x, y;
};
    
class Circle : public Point {
public:
    Circle(float a, float b, float r) : Point(a, b), radius(r) {}
    virtual ~Circle() { cout << "executing Circle destructor" << endl; }
private:
    float radius;
};

int main() {

    Point *p = new Circle(2.5, 1.8, 4.5);
    delete p;

    return 0;
}