#include <iostream>
#include <string>
#include <cmath>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "imagelib/stb_image_write.h"

#define constexpr const

using namespace std;



class Bitmap
{
private:
	constexpr static uint32_t w = 800, h = 600;
	uint32_t pixels[h][w];


public:
	Bitmap(uint32_t color) {
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				pixels[j][i]=color;
			}
		}
	}
	~Bitmap() {}

	void horizLine(int xl, int xr, int y, uint32_t color){
		line(xl,y,xr,y,color);
	}

	void vertLine(int yu,int yd,int x, uint32_t	color){
		line(x,yu,x,yd,color);
	}

	void drawRect(int x,int y, int width,int hight, uint32_t color){
		line(x,y,x,y+hight,color);
		line(x,y+hight,x+width,y+hight,color);
		line(x,y,x+width,y,color);
		line(x+width,y,x+width,y+hight,color);
	}

	void fillRect(int x,int y, int width,int hight, uint32_t color){
		for (int i = x; i < x+width; i++)
		{
			for (int j = y; j < y+hight; j++)
			{
				pixels[j][i]=color;
			}
		}
	}

	void line(int xl,int yl, int xr,int yr, uint32_t color,bool anti=false){
		float a=0;
		if(xl!=xr) a=(yr-yl)/(double)(xr-xl);
		
		if(abs(a)<1&&xl!=xr){
			if(xr<xl)swap(xr,xl);
			for (int i = xl; i <= xr; i++)
			{	
				if(anti&&a){
				}
				else{
					pixels[(int)(yl+a*(i-xl))][i]=color;
					if((int)a!=0){pixels[(int)(yl+a*(i-xl))+1][i]=mix(color-0x80000000,pixels[(int)(yl+a*(i-xl))+1][i]);
					pixels[(int)(yl+a*(i-xl))-1][i]=mix(color-0x80000000,pixels[(int)(yl+a*(i-xl))-1][i]);}}
			}
		}
		else if(xl!=xr)
		{	
			if(anti&&xl!=xr){
				uint32_t mtx[(int)abs(a)][2]; 
			}
			if(yr<yl)swap(yl,yr);
			for (int i = yl; i <= yr; i++)
			{
				pixels[i][(int)(xl+(i-yl)/a)]=color;
				pixels[i+1][(int)(xl+(i-yl)/a)]=mix(color-0x80000000,pixels[i+1][(int)(xl+(i-yl)/a)]);
				pixels[i-1][(int)(xl+(i-yl)/a)]=mix(color-0x80000000,pixels[i-1][(int)(xl+(i-yl)/a)]);
			}
		}
		else{
			if(yr<yl)swap(yl,yr);
			for (int i = yl; i <= yr; i++)
			{
				pixels[i][xl]=color;
			}
		}
	}

	void ellipse(int xc, int yc, int dx, int dy){
		int x,y;
		int b=min(dx/2.0,dy/2.0);
		int a=max(dx/2.0,dy/2.0);
		double l=M_PI*2*b+4*abs(a-b);
		double step=4/l;
		for (double r = -M_PI; r < M_PI; r+=step)
		{	
			y=yc+dy*sin(r)/2;
			x=xc+dx*cos(r)/2;
			if(x>=0&&y>=0&&x<w&&y<h){
				pixels[y][x]=0xFF00FF00;
			}
		}
	}

	uint32_t mix(uint32_t c1,uint32_t c2){
		uint8_t A1=c1>>24;
		uint8_t R=((c1&0xff)*A1/255.0-(c2&0xff)*(1-A1/255.0));
		uint8_t G=(((c1>>8)&0xff)*A1/255.0-((c2>>8)&0xff)*(1-A1/255.0));
		uint8_t B=(((c1>>16)&0xff)*A1/255.0-((c2>>16)&0xff)*(1-A1/255.0));
		uint32_t c=0xff000000+R+(((uint32_t)G)<<8)+(((uint32_t)B)<<16);
		return c;
	}


	void save(const char filename[]) {
    	stbi_write_png(filename, w, h, 4, pixels, w*4);
  	}
};


int main() {
	// FIRST PART (ADD COLORS HERE)
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED =   0xFF0000FF; // red opaque
	constexpr uint32_t GREEN = 0xFF00FF00;
	constexpr uint32_t BLUE =	0xFFFF0000;
	constexpr uint32_t YELLOW = GREEN|RED;
	constexpr uint32_t WHITE =	RED|GREEN|BLUE;


	// SECOND PART (DO NOT EDIT)
	int xcenter = 100;
	int ycenter = 100;
	int xdiameter = 200;
	int ydiameter = 100;
	Bitmap b(BLACK); // Hardcoded size (600 x 400 pixels)
	
    b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
	b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
	
	b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
	b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color
	
	b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	b.ellipse(xcenter, ycenter, xdiameter, ydiameter); //Ellipse using specs from above
		
	// THIRD PART - OPTIONAL FUNCTION
	// 100pt bonus for properly implementing Wu's antialiasing
	//https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	//b.antialiasedLine(599,0, 550,300, 0xeeffddbb);  

	b.save("bitmap.png");
  
}

