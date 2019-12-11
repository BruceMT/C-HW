//
// Created by MWB20 on 9/25/2019.
// remake
#include <iostream>
#include <cmath>
using namespace std;
int a ,b,i;
bool r;
int count=0;
bool is_prime(int number)//from HW2B
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
int countPrime(int a,int b){


    for(i=a;i<=b;i++) {
        r = is_prime(i);
        if (r == true) {
            count = count + 1;
        }
    }return count;
}

int main(){

    int result=0;
    cout<<"Please enter a positive integer as the minimum:"<<endl;
    cin>>a;
    cout<<"Please enter a positive integer as the maximum:"<<endl;
    cin>>b;

    result = countPrime(a,b);
    cout<<"There are "<<result<<" primes in the range ["<<a<<", "<<b<<"]"<<endl;




    return 0;

}