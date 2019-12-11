//
// Created by MWB20 on 9/11/2019.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int round1(double r)
{
    return(r>0.0)?floor(r + 0.5) : ceil(r - 0.5);
}
int main(){
    int WS[] ={5,10,15,20,25,30,35,40,45,50,55,60};
    int TE[] ={40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40,-45};
    double WC;
    int WC1;
    int n1=5;

    cout<<"    "<<"40  35  30  25  20  15  10   5   0  -5 -10 -15 -20 -25 -30 -35 -40 -45"<<endl;


    for(int i= 0;i<=11;i++){
        if(n1==5){
            cout<<n1<<" "<<setw(1);
        }else{
            cout<<n1<<setw(4);
        }

        for(int j=0;j<=17;j++){

            WC =35.74 + 0.6215*TE[j]-35.75*(pow(WS[i],0.16))+0.4275*TE[j]*(pow(WS[i],0.16));
            WC1 = round1(WC);

            cout<<setw(4)<<WC1;


        }
        n1=n1+5;
        cout<<endl;

    }

    return 0;
}