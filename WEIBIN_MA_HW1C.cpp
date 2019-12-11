//
// Created by MWB20 on 9/2/2019.
//

#include <iostream>
#include <math.h>
 int main(){
     int sum1 = 0;
     int sum2 = 0;
     int n;
     sum1 = 100*(100+1)/2;
     std::cout<<"Gauss Results: "<<sum1<<"\n";
     for(n =1;n<=100;n++){
         sum2+=n;
     }
     std::cout<<"Loop Result: "<<sum2<<"\n";
     if(sum1==sum2){
        std::cout<<"Both results are the same.";
     }







    return 0;
}
