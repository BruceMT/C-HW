//
// Created by MWB20 on 9/2/2019.
//

#include <iostream>
#include <math.h>
 int main(){
     double r = 1;
     int n;
   //  double PI= 3.14;
    for(n=3;n<=1000000;n++){
        r =(r/cos( M_PI/n));
        for(int j =10;j<=1000000;j=j*10){
        if(n==j){
            std::cout<<n<<" "<<r<<'\n';
        }
        }
    }





    return 0;
}
