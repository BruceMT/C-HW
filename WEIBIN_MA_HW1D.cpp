//
// Created by MWB20 on 9/2/2019.
//

#include <iostream>
#include <math.h>
#include<iomanip>
#include "stdlib.h"
using namespace std;
 int main(){
    int n;
    float sum1F;
    float sum2F;
    double sum1D;
    double sum2D;
    for(n=1;n<=100;n++){

        sum1F=sum1F+1.0/n;

    }
    std::cout<<setprecision(4)<<"sum1F = "<<sum1F<<", ";
     for(n=100;n>=1;n--){

         sum2F=sum2F+1.0/n;

     }
     std::cout<<setprecision(4)<<"sum2F = "<<sum2F<<"\n";
     for(n=1;n<=100;n++){

         sum1D=sum1D+1.0/n;

     }
     std::cout<<setprecision(4)<<"sum1D = "<<sum1D<<", ";
     for(n=100;n>=1;n--){

         sum2D=sum2D+1.0/n;

     }
     std::cout<<setprecision(4)<<"sum2D = "<<sum2D<<"\n";
     std::cout<<setprecision(3)<<"sum1F - sum2F = "<<sum1F-sum2F<<"\n";
     std::cout<<setprecision(3)<<"sum1D - sum2D = "<<sum1D-sum2D<<"\n";







    return 0;
}
