//
// Created by MWB20 on 11/4/2019.
// title : hw_BitMap2
/*
  You have to write:
  1. Constructor (that allocates dynamic memory)
  2. Destructor (free the memory delete [])
  3. Copy Constructor
  4. Operator = (use either old way or copy and swap)
  5. Move Constructor
 */
#include <iostream>
#include <string>
#include <cmath>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "stb_image.h"
using namespace std;
class DynamicBitmap {
private:
    uint32_t width, height,color;
    uint32_t* p;
public:
    DynamicBitmap(uint32_t w, uint32_t h,uint32_t c) : width(w), height(h), color(c), p(new uint32_t[width*height]())
    {
        	for (int i = 0; i < w*h; i++)
        			p[i] = c;
    }
    //Destructor
    ~DynamicBitmap() { delete [] p; }
    //Copy Constructor
    DynamicBitmap(const DynamicBitmap &v):width(v.width),height(v.height),color(v.color),p(new uint32_t[width*height]()){
        memcpy(p,v.p, sizeof(int)*width*height);
        //cout<<"copy constructor"<<endl;//test
        //for (int i = 0; i < width*height; i++)
          //  p[i] = color;
    }
    //Operator = (use either old way or copy and swap)
    DynamicBitmap& operator=(DynamicBitmap a){

        width = a.width;
        height = a.height;
        color = a.color;
        swap(p,a.p);


       // for (int i = 0; i < width*height; i++)
         //   p[i] = color;
        return *this;
    }
    // Move Constructor
    DynamicBitmap(DynamicBitmap && m):width(m.width),height(m.height),color(m.color),p(m.p) {
       // cout<<"movie complete"; //test move constructor
        m.p = nullptr;
    }
    //draw map area
    void horizLine(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
        for (uint32_t i = x1; i <= x2; i++) {
            p[y*width+ i] = color;
        }
    }
    void vertLine(uint32_t y1,uint32_t y2,uint32_t x,uint32_t color){
        for (uint32_t i = y1; i <= y2; i++) {
            for(uint32_t j = x; j<=(y2-1)*width+x;j=j+width) {
                p[j] = color;
            }
        }
    }

    void ellipse(int x,int y,int xd,int yd){
        int m,n;
        double step=0.01;
        for (double r = -M_PI; r < M_PI; r=r+step)
        {
            n=y+yd*sin(r)/2;
            m=x+xd*cos(r)/2;
            p[m+n*width]=0xFFFFFFFF;

        }
    }

    //*****
    // waiting for finishing
    void line(int start_x, int start_y, int end_x, int end_y, uint32_t color) {
        if (abs(end_y - start_y) > abs(end_x - start_x)) {
            swap(start_x, start_y);
            swap(end_x, end_y);
        }
        if (start_x > end_x) {
            swap(start_x, end_x);
            swap(start_y, end_y);
        }
        int deltax = end_x - start_x;
        int deltay = abs(end_y - start_y);
        int error = deltax / 2;
        int ystep;
        int y = start_y;
        if (start_y < end_y) {
            ystep = 1;
        } else {
            ystep = -1;
        }
        for (int i = start_x; i <= end_x; i++) {
            if (abs(end_y - start_y) > abs(end_x - start_x)) {
                p[y * width + i] = color;
                error = error - deltay;
            } else {
                p[i * width + y] = color;
                error = error - deltay;
            }

            if (error < 0) {
                y = y + ystep;
                error = error + deltax;
            }
        }
    }

    void drawRect(int x, int y, int w, int h, uint32_t color) {
        for (int i = y; i <= y + h; i = i + h) {
            for (int j = x; j <= x + w; j ++) {
                p[i * width + j] = color;
            }
            for (int j = x; j <= x + w; j = j + w) {
                for (int i = y; i <= y + h; i ++) {
                    p[i * width + j] = color;
                }
            }
        }
    }
    void fillRect(int topleft_x, int topleft_y, int W, int H, uint32_t color) {
        for (uint32_t i = topleft_y; i <= topleft_y + H; i ++) {
            for (uint32_t j = topleft_x; j <= topleft_x + W; j ++) {
                p[i * width + j] = color;
            }
        }
    }

    void save(const char filename[]){
        stbi_write_png(filename, width, height, 4, p, width*4);
    }

};
int main() {
    // FIRST PART (ADD COLORS HERE)
    constexpr uint32_t BLACK = 0xFF000000; // black opaque
    constexpr uint32_t RED = 0xFF0000FF; // red opaque
    constexpr uint32_t YELLOW =  0xFF00FFFF;//yellow
    constexpr uint32_t BLUE =  0xFFFF0000;//blue
    constexpr uint32_t WHITE =  0xFFFFFFFF;//white

    // SECOND PART (DO NOT EDIT)
    int xcenter = 100;
    int ycenter = 100;
    int xdiameter = 200;
    int ydiameter = 100;

    DynamicBitmap b(1024, 1024, BLACK); // Potentially dynamic size (Now: 1024 x 1024 pixels)

    b.horizLine(0, 500, 200, RED); // horizontal line from x=0 to x=500, @y = 200
    b.vertLine(0, 399, 300, RED); // y=0 to y=399 @ x= 300, red vertical line

    b.drawRect(200,200, 100,50, BLUE); // blue rectangle, top-left=200,200 w=100 h=50
    b.fillRect(201,201, 98,48, WHITE); // same but filled

    b.line(400,0, 550,300, YELLOW); // draw a line https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

    b.ellipse(xcenter, ycenter, xdiameter, ydiameter);
    //##these are testing not request...
    //DynamicBitmap c(b); //test copy constructor...
    //c.horizLine(0,500,500,YELLOW);
    //DynamicBitmap a(1024,1024,YELLOW);
    //c.horizLine(0,500,200,RED);
    //a = b;
    //DynamicBitmap e(&a);
    //swap(a,c);
    //a.save("testa.png");
    //c.save("testc.png");
    b.save("bitmap.png");
}

