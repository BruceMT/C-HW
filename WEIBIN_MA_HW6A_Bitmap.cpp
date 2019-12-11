/*
 * author: weibin_ma
 * date: 30/10/2019
 * title: HW6A - Bitmap1
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "stb_image.h"

using namespace std;

class Bitmap{
private:
    constexpr static uint32_t w = 800, h = 600;

    uint32_t pixels[h][w];

public:
    Bitmap(uint32_t color){
        for (uint32_t i = 0; i < h; i++)
            for (uint32_t j = 0; j < w; j++) {
                pixels[i][j] = color;
            }
    }
    void horizLine(int x ,int y,int z, uint32_t color){
        line(x,z,y,z,color);
    }
    void vertLine(int x,int y,int z, uint32_t color){
        line(z,x,z,y,color);
    }
    void drawRect(int x,int y,int w,int h, uint32_t color){
        line(x,y,x+w,y,color);
        line(x+w,y,x+w,y+h,color);
        line(x,y+h,x+w,y+h,color);
        line(x,y,x,y+h,color);

    }
    void fillRect(int x,int y,int w,int h, uint32_t color){
        int x1 = x + w;
        int y1 = y + h;
        for(int i = x;i <= x1;i++){
            for(int j = y; j<= y1; j++){
                pixels[j][i] = color;
            }
        }
    }
 /* my won method
  * void line(int x,int y,int z,int a, uint32_t color){
        int temp = 0;
        double deltax = 0;
        double deltay = 0;
        double deltaerr = 0;


         if(x!=z){
            deltax =abs( z - x);
            deltay = abs(a - y);
            deltaerr = deltay / deltax;
            for (double i = x; i <= z; i=i+0.25) {
                pixels[int(y)][int(i)] = color;
                y += deltaerr*(i-x);

            }
        }else if(x==z){
            if(a<y){
                int temp;
                temp = y;
                 y = a;
                 a = temp;
                for (int i = y; i <= a; i++) {
                    pixels[i][x] = color;
                }

            }else{
                for (int i = y; i <= a; i++) {
                    pixels[i][x] = color;
                }
            }
         }
    }
*/
    void line(int x,int y,int z,int a, uint32_t color){
     bool steep = abs(a - y) > abs(z - x);
     if(steep) {
         //swap(x0, y0)
         int temp;
         temp = y;
         y = x;
         x = temp;
         //swap(x1, y1)
         temp = a;
         a = z;
         z = temp;
     }

     if (x > z){
     //swap(x0, x1)
         int temp;
         temp = x;
         x = z;
         z = temp;
     //swap(y0, y1)
         temp = y;
         y = a;
         a = temp;
     }
     int deltax = z - x;
     int deltay = abs(a - y);
     double error = deltax / 2;
     int ystep;
     int yc = y;
     if (y < a){
     ystep = 1;
     } else{
         ystep = -1;
     }
    // for x from x0 to x1
    for(int i = x; i<= z;i++) {
        if (steep) {
            pixels[i][yc] = color;
            error = error - deltay;
        }else{
            pixels[yc][i]=color;
            error = error - deltay;
        }

        // then plot(y,x) else plot(x,y)

        if( error < 0){
            yc = yc + ystep;
            error = error + deltax;
        }
        // yc = yc + ystep


    }
    }
    void ellipse(int x,int y,int xd,int yd){
        //double c = sqrt(xd*xd+yd*yd);
        int m,n;
        double p=0.01;
        for (double r = -M_PI; r < M_PI; r=r+p)
        {
            n=y+yd*sin(r)/2;
            m=x+xd*cos(r)/2;
            pixels[n][m]=0xFFFFFFFF;

        }
    }
    //OPTIONAL:
    //plot the pixel at (x, y) with brightness c (where 0 ≤ c ≤ 1)
    void plot(int x, int y, uint32_t color){
        pixels[x][y]=color;
    }
    // integer part of x
    int ipart(int x){ return floor(x);}

    double  round(int x){
    return ipart(x + 0.5);
    }
    // fractional part of x
    int fpart(int x) {
    return x - floor(x);}

    int rfpart(int x) {
    return 1 - fpart(x);}

 /*  void antialiasedLine(int x0,int y0, int x1,int y1, uint32_t color){
        bool steep = abs(y1 - y0) > abs(x1 - x0);

        if (steep) {
            // swap(x0, y0)
            int temp;
            temp = x0;
            x0 = y0;
            y0 = temp;
            //swap(x1, y1)
            temp = x1;
            x1= y1;
            y1 = temp;
        }
        if (x0 > x1){
               // swap(x0, x1)
                int temp;
                temp = x0;
                x0 = x1;
                x1 = temp;
                //swap(y0, y1)
                temp = y0;
                y0 = y1;
                y1 = temp;
        }
        int dx = x1 - x0;
        int dy = y1 - y0;
        double gradient = dy / dx;
        if (dx == 0.0){
            gradient = 1.0;
        }

        // handle first endpoint
        double xend = round(x0);
        double yend = y0 + gradient * (xend - x0);
        double xgap = rfpart(x0 + 0.5);
        double xpxl1 = xend; // this will be used in the main loop
        int ypxl1 = ipart(yend);
        if (steep){
            plot(ypxl1,   xpxl1, color);
            plot(ypxl1+1, xpxl1,  color);
        }else{
        plot(xpxl1, ypxl1  , color);
        plot(xpxl1, ypxl1+1,  color);
        }
        int intery = yend + gradient; // first y-intersection for the main loop

        // handle second endpoint
        double xend1 = round(x1);
        double yend1 = y1 + gradient * (xend1 - x1);
        double xgap1 = fpart(x1 + 0.5);
        double xpxl2 = xend1; //this will be used in the main loop
        double ypxl2 = ipart(yend);
        if (steep) {
            plot(ypxl2, xpxl2, color);
            plot(ypxl2 + 1, xpxl2, color);
        }else{
        plot(xpxl2, ypxl2,  color);
        plot(xpxl2, ypxl2+1, color);
        }
        // main loop
        if (steep){
            for (int i=xpxl1 + 1 ; i <= xpxl2 - 1 ;i++){
                plot(ipart(intery)  , i, color);
                plot(ipart(intery)+1, i, color);
                intery = intery + gradient;
            }
        }else{
            for (int i = xpxl1 + 1; i<= xpxl2 - 1;i++ ) {
                    plot(i, ipart(intery), color);
            plot(i, ipart(intery) + 1, color);
            intery = intery + gradient;
        }
        }

    }
*/

    void save(const char filename[]){
        stbi_write_png(filename, w, h, 4, pixels, w*4);
    }
};
int main() {
    // FIRST PART (ADD COLORS HERE)

    constexpr uint32_t BLACK = 0xFF000000; // black opaque
    constexpr uint32_t RED =  0xFF0000FF; // red opaque
    constexpr uint32_t YELLOW =  0xFF00FFFF;//yellow
    constexpr uint32_t BLUE =  0xFFFF0000;//blue
    constexpr uint32_t WHITE =  0xFFFFFFFF;//white

    // SECOND PART (DO NOT EDIT)
    int xcenter = 100;
    int ycenter = 100;
    int xdiameter = 200;
    int ydiameter = 100;

    Bitmap b(BLACK); // Hardcoded size (***800 x 600 pixels***)

    b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
    b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300

    b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
    b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color

    b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

    b.ellipse(xcenter, ycenter, xdiameter, ydiameter); //Ellipse using specs from above

    b.save("bitmap.png");


    // THIRD PART - OPTIONAL FUNCTION
    // 100pt bonus for properly implementing Wu's antialiasing
    //https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
    //b.antialiasedLine(400,0, 550,300, YELLOW);
}