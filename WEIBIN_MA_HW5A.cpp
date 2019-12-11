
 // Created by MWB20 on 10/17/2019.
 // version : 0.1
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
 using namespace std;

/*
	suggestion:
for this assignment:
class Shape {
public:
  virtual void draw(ostream& s) = 0;
};
class Polygon : public Shape {
 void draw(ostream& s) {...}
};
 */


 class Shape{
 public:
     virtual void draw(ostream& s) = 0;

 };

 class Rect: public Shape{
 private:
     double x,y,wid,height;
 public:
     Rect(double x , double y,double wid, double height):x(x),y(y),wid(wid),height(height){}

        void draw(ostream& s){
             s<<x<<" "<<y<<" moveto"<<endl;
             s<<x+wid<<" "<<y<<" lineto"<<endl;
             s<<x+wid<<" "<<y+height<<" lineto"<<endl;
             s<<x<<" "<<y+height<<" lineto"<<endl;
             s<<"closepath stroke"<<endl;
         }

 };
 class FilledRect: public Shape{
 private:
     double x,y,wid,height;
 public:
     FilledRect(double x , double y,double wid, double height):x(x),y(y),wid(wid),height(height){}
     void draw(ostream& s){
         s<<x<<" "<<y<<" moveto"<<endl;
         s<<x+wid<<" "<<y<<" lineto"<<endl;
         s<<x+wid<<" "<<y+height<<" lineto"<<endl;
         s<<x<<" "<<y+height<<" lineto"<<endl;
         s<<"closepath fill"<<endl;
     }
 };

 class Circle: public Shape{
 private:
     double x,y,R;
 public:
     Circle(double x,double y,double R):x(x),y(y),R(R){}
     void draw(ostream& s){
         s<<x<<" "<<y<<" "<<R<<" 0 360 arc stroke"<<endl;
     }
 };

 class FilledCircle: public Shape{
 private:
     double x,y,R;
 public:
     FilledCircle(double x,double y,double R):x(x),y(y),R(R){}
     void draw(ostream& s){
         s<<x<<" "<<y<<" "<<R<<" 0 360 arc fill"<<endl;
     }
 };

 class Polygon: public Shape{
     double x,y,R;
     int n;
 public:
     Polygon(double x, double y,double R,int n):x(x),y(y),R(R),n(n){}
     void draw(ostream& s){
         double x1,y1;
         for(int i=0;i<n;i++){
             x1=x+R*cos(M_PI*2/n*i);
             y1=y+R*sin(M_PI*2/n*i);
             s<<x1<<" "<<y1<<" ";
             if(i){
                 s<<"lineto";
             }else{
                 s<<"moveto";
             }s<<endl;
         }
         s<<"closepath stroke"<<endl;
     }
 };

 class Line: public Shape{
 private:
     double x,y,end_x,end_y;
 public:
     Line(double x,double y, double end_x, double end_y):x(x),y(y),end_x(end_x),end_y(end_y){}
     void draw(ostream& s){
         s<<x<<" "<<y<<" moveto ";
         s<<end_x<<" "<<end_y<<" lineto stroke"<<endl;
     }

 };

 class Rgb : public Shape{
    double r,g,b;
 public:
     Rgb(double r, double g,double b):r(r),g(g),b(b){}
     void draw(ostream& s){
         s<<r<<" "<<g<<" "<<b<<" setrgbcolor"<<endl;
     }
 };

 class Drawing {
 private:
     ofstream f;
     vector<Shape*> shapes;
 public:
     Drawing(string filename) : f(filename.c_str()), shapes() {
     }
     void add( Shape* s ) {
         shapes.push_back(s);
     }

     void draw() {
         int numShapes=shapes.size();
         for (int i = 0; i < numShapes; i++)
             shapes[i]->draw(f);
     }
     void setrgb(double r,double g,double b){

         shapes.push_back(new Rgb(r,g,b));
     }
 };

 int main() {
     ofstream f(  );
     Drawing d("test2.ps");
     d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
     d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
     d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
     for (int x = 0; x < 600; x += 100)
         d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
     d.setrgb(0,1,0); // the rest are green

     d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
     d.add(new Line(400,500, 600,550));
     d.add(new Polygon(200,200, 50, 6));
     d.draw();
 }