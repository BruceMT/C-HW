#include <iostream>
#include <cmath>
using namespace std;
class Vec3d{
private:
    double x=0.0,y=0.0,z=0.0;
public:
    Vec3d(double x,double y,double z):x(x),y(y),z(z){}
    Vec3d(double x):x(x),y(0),z(0){}
    Vec3d(double x,double y):x(x),y(y),z(0){}
    Vec3d():x(0),y(0),z(0){}

    friend Vec3d operator +(const Vec3d& m, const Vec3d& n){
        return Vec3d(m.x+n.x , m.y+n.y , m.z+n.z);
    }
    Vec3d operator -( const Vec3d& n)const{
        return Vec3d(this->x-n.x , y-n.y , z-n.z);
    }
    Vec3d operator -()const{
        return Vec3d(-x , -y , -z);
    }
    friend ostream&operator<<(ostream& s,const Vec3d v){
        return s<<"(" <<v.x<<','<<v.y<<','<<v.z<<")";
    }
    friend double dot(const Vec3d& e, const Vec3d& f){
        return e.x*f.x + e.y*f.y + e.z*f.z;

    }
    double dot(const Vec3d& b)const{
        return this->x*b.x + this->y*b.y +this->z*b.z;

    }
    double mag()const{
        double result=0.0;
        result= pow(x,2)+pow(y,2)+pow(z,2);
        return sqrt(result);
    }
    double magSq()const{
        return pow(x,2)+pow(y,2)+pow(z,2);
    }
    double dist(const Vec3d& b)const{
        double reslut= 0.0;
        reslut = pow(x-b.x,2)+pow(y-b.y,2)+pow(z-b.z,2);
        return sqrt(reslut);
    }

};

int main() {
    // Main() Section 1
    const Vec3d a(1.0,2.5,3.5); // double precision!
    const Vec3d b(2.0);         //(2,0,0)
    const Vec3d c(2.0,3.5);     //(2,3.5,0)
    const Vec3d d;              //(0,0,0)

    // Main() Section 2
    const Vec3d e = a + d;
    const Vec3d f = c - b;
    const Vec3d g = -e;

    // Main() Section 3
    double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z
    double s = e.dot(f); // method

    // Main() Section 4
    double x = e.mag(); // square root of sum of square
    double y = e.magSq(); // sum of square
    double z = e.dist(f); // sqrt of sum of square of diff

    // Main() Section 5
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "c: " << c << '\n';
    cout << "d: " << d << '\n';
    cout << "e: " << e << '\n';
    cout << "f: " << f << '\n';
    cout << "g: " << g << '\n';
    cout << "r: " << r << '\n';
    cout << "s: " << s << '\n';
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
    cout << "z: " << z << '\n';
}