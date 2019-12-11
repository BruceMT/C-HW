/*
 * author: weibin ma
 * date: 10/07/2019
 * title: pointer
 *
 */



#include <iostream>
#include <cmath>
using namespace std;


// fill the array x with zeros (using pointer)
void fill(int x[], int size) {
    int* p;
    p = x;
    for(int i =0;i<=size;i++){
        *p++ = 0;// NO, use pointer!!! *p++ = 0
    }

}

// add 1 to every element of x
void increment(int x[], int size) {
    int* p;
    p = x;
    for(int i =0;i<=size;i++){
        *p++ += 1;
    }

}

// double every element of x
void doubleMe(int x[], int size) {
    int* p;
    p = x;
    for(int i =0;i<=size;i++){
        *p *= 2;
        p++;
    }


}

// print out every element of x separated by spaces  then newline
void print(int x[], int size) {
int *p=x;
    for(int i=0;i < size;i++){
        cout<<*p<<" ";
        p++;
    }
    cout<<endl;
}

int main() {
    int x[10] = {1};
    const int size = sizeof(x)/sizeof(int);
    print(x, size);
    fill(x, size);
    print(x, size);
    increment(x, size);
    print(x, size);
    doubleMe(x, size);
    print(x, size);
}