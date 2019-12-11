//
// Created by MWB20 on 9/2/2019.
//

#include <iostream>
#include <math.h>
#include<iomanip>
#include "stdlib.h"
using namespace std;
 int main(){
    int n ;
     std::cout<<"Please enter a positive integer:\n";
     std::cin>>n;

     float sum1;
     for(int j=1;j<=n;j++){
         sum1 += 1.0/(j*j);
     }
    //cout<<sum1<<endl;
     float result1;
     result1 = sqrt(6*sum1);
     cout<<"result1 = "<<setprecision(7)<<result1<<endl;


     std::cout<<"Please enter a larger positive integer(over 3 digit):\n";
     std::cin>>n;

     float sum2;
     for(int j=1;j<=n;j++){
         sum2 += 1.0/(j*j);
     }
    // cout<<sum2<<endl;
     float result2;
     result2 = sqrt(6*sum2);
     cout<<"result2 = "<<setprecision(7)<<result2<<endl;


     float sum3;
     for(int j=n;j>=1;j--){
         sum3 += 1.0/(j*j);
     }
     //cout<<sum3<<endl;
     float result3;
     result3 = sqrt(6*sum3);
     cout<<"result3 = "<<setprecision(7)<<result3<<endl;


     return 0;
}
