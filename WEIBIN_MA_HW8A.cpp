/*author: WEIBIN MA
 * DATE:25/11/2019
 * TITLE: HW8A
 *
 * */

/*
	Write a GrowArray class that is templated, and that allows you to 
	allocate memory but not call the constructor for each element.
	To do this you will have to cast and use placement new syntax.
	See placementnew.cc, GrowArray.cc
	You are encouraged to write the class from scratch without looking at 
	my code, once you understand the fundamentals.
*/

#include <iostream>
#include <memory.h>
#include <cstring>
using namespace std;

class Person {
private:
    uint32_t len;
    char *name;
public:
    Person(const char n[]) : len(strlen(n)) {
        cout << "Person constructor\n";
        name = new char[len];
        memcpy(name, n, len);
    }

    Person(const Person &orig) : len(strlen(orig.name)) {
        cout << "copying Person\n";
        name = new char[len];
        memcpy(name, orig.name, len);
    }

    ~Person() {
        cout << "Destructor\n";
        delete[] name;
    }
};

template <typename T>
class GrowArray {
private:
    uint32_t len;
    uint32_t cap;
    T* data;
public:
    GrowArray(uint32_t cap) : len(0), cap(cap),data((T*)new char[cap * sizeof(T)]) {}

    ~GrowArray() { for (int i = 0; i < len;  i++)// ok to delete nullptr
            data[i].~T();
        delete [] (char*)data;
    }
    GrowArray(const GrowArray& orig) : len(orig.len), cap(orig.cap),data((T*)new char[orig.cap * sizeof(T)]) {
        memcpy(data, orig.data, len * sizeof(int));
    }
    GrowArray& operator =(GrowArray & orig) {
        len = orig.len;
        cap = orig.cap;
        swap(data, orig.data);
        return *this;
    }
    GrowArray(GrowArray&& orig) : len (orig.len), cap(orig.cap),data(orig.data) {
        orig.data = nullptr;
    }
    void add(T Person) {
        new (&data[len++])T(Person);
    }

};

int main() {
    GrowArray<Person> list(1000000); // should not call constructor for Person!
    list.add(Person("Test")); // Should call the constructor once and the copy once
    /*
        Destructor should be called twice for person (once for the temp, and once for
        the object in the array. If the optimizer somehow can do it, it could be only once.
        But most important, you must not call the destructor 1000000 times!
    */
}