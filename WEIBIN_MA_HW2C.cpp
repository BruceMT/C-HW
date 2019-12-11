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
    int a ,b,i;
    bool r;
   cout<<"Please enter a positive integer as the minimum:"<<endl;
   cin>>a;
   cout<<"Please enter a positive integer as the maximum:"<<endl;
   cin>>b;
   int count=0;

    for(i=a;i<=b;i++){
        r = is_prime(i);
        if(r ==true){
            count=count+1;
        }
    }
    cout<<"There are "<<count<<" primes in the range ["<<a<<", "<<b<<"]"<<endl;






}