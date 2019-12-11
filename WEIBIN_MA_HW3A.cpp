
/*
	Make the following main work by writing a class Complex.
	Replace this comment with your author information and cite as necessary.
	Notice that since objects are const, you will have to promise not to change them
 // Created by MWB20 on 9/17/2019.
 // version : 0.8
 */
#include <iostream>
#include <iomanip>

using namespace std;
class Complex{

 public:
    double real,imag;
    Complex(){ real = 0; imag = 0; }
    Complex(double r, double i){
     real = r;
     imag = i;
    }

    friend Complex operator +(double i,Complex &c);
    Complex operator -()const {
        Complex c2(-real,-imag);

        return c2;
    }
    void print()const;

    Complex add(const Complex c1)const;
};

    Complex operator +(const Complex &c1,const Complex &c2){
    return Complex(c1.real+c2.real,c1.imag+c2.imag);}



void Complex::print()const
{
    cout<< fixed << setprecision(1) << "(" << real << "," << imag <<")"<< endl;
}
Complex Complex::add (const Complex c1) const {
    return  *this+c1;

    }

int main() {
    const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
    const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
    const Complex c = a + b;   // overload operator + using a friend function
     c.print(); // should print the following to cout: (1.5,2.0)
    // (member syntax).  Should look the same as method add where the name add
    // is replaced by operator +
    const Complex d = a.add(b); // this should be the same as the above except the name
    d.print();
    Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
    e.print();
}