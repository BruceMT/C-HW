//
// Created by MWB20 on 9/11/2019.
//
#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int number)
{
    if(number==1)
        return false;
    if(number==2)
        return true;
    for(int i=2;i*i<=number;i++)
        if(number%i==0)
            return false;
    return true;
}
int main(){
    int n = 0;
    bool n1;
    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;
    n1 = is_prime(n);
   if(n1==false){
       cout<<"  The number "<<n<<" is: NOT PRIME";
   }else{
       cout<<"  The number "<<n<<" is: PRIME";
   }


}