//
// Created by MWB20 on 9/11/2019.
//
#include <iostream>
#include <cmath>
#include <fstream>
#include<stdio.h>

using namespace std;
double x =0.0 ,y=0.0;
float a1[64];
float a2[64];
int i = 0;
void  polar2Rect(double r,double theta,double dx,double dy){
    if(theta<0||r<0){
        cout<<"Robot has reached final destination."<<endl;
        cout<<"program terminates."<<endl;
        exit(0);
    }else{
    dx = dx + sin(M_PI*theta/180)*r;
    dy = dy + cos((M_PI/180)*theta)*r;
    x=dx;
    y=dy;
    cout<<"New robot position(X,Y):("<<to_string(dx)<<", "<<to_string(dy)<<")"<<endl;
        }
}
void readFile(){


    ifstream myfile("C:\\Users\\MWB20\\CLionProjects\\untitled1\\hw2e.dat.txt");
    if(!myfile){
        cout << "Unable to open myfile";
        exit(1); // terminate with error
    }
    else
    {
        char str[64] = {0};
        while (!myfile.eof())
        {
            myfile.getline (str, 64);
            sscanf(str, "%f %f", &a1[i], &a2[i]);
            i++;
        }
    }

    for(int j = 0; j < i; j++){
      //  cout << a1[j] << " " << a2[j] << endl;
        polar2Rect(a2[j],a1[j],x,y);
    }cout<<"Robot has reached final destination.";

}


int main(){
    readFile();



    return 0;

}