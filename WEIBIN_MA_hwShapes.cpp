/*
 * author: weibin ma
 * date: 10/07/2019
 * title: hwShapes
 *
 */


#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979;
class Shape{
private:
    double x,y;
public:
    Shape(){}
    virtual double area()const =0;

};
class Rect: public Shape{
private:
    double x,y,wid,height;
public:
    Rect(double x , double y,double wid, double height):x(x),y(y),wid(wid),height(height){}
    double area()const{
        return wid*height;
    }
};
class Circle: public Shape{
private:
    double x,y,R;
public:
    Circle(double x,double y,double R):x(x),y(y),R(R){}
    double area()const{
        return pow(R,2)*PI;
    }

};
class Line: public Shape{
private:
    double x,y,w,h;
public:
    Line(double x,double y, double w, double h):x(x),y(y),w(w),h(h){}
    double area()const{ return 0;}

};
int main() {
    Rect r1(100, 50, 20, 40);	// Rect(x,y, width, height)
    cout << r1.area() << '\n';
    Circle c1(400, 300, 50); // Circle(x,y,radius)
    cout << c1.area() << '\n'; // area should be pi * radius squared
    Line L1(0,0, 300, 400);
    cout << L1.area() << '\n'; // area should be 0
#if 0
    Shape* shapes[6];
	shapes[0] = &r1;
	shapes[1] = &c1;
	shapes[2] = &L1;
	for (int i = 0; i < 2; i++)
		cout << shapes[i]->area() << '\n';
	for (auto s : shapes)
		if (s != nullptr)
			cout << s->area() << '\n';

#endif
}