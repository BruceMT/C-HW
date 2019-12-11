
 // Created by MWB20 on 9/17/2019.
 // version : 0.1
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int i,datalen=0;
    double num[100];
    ifstream file("C:\\Users\\MWB20\\CLionProjects\\untitled1\\3B.dat.txt");
    while( ! file.eof() )
        file>>num[datalen++];
    double count =0.0;
    for(int i=0;i<datalen;i++)
    {
        count++;
    }
    cout<< fixed << setprecision(1)<<"Elements = "<<count<<endl;

    cout<< fixed << setprecision(1)<<"Max = "<< (*max_element(num, num + datalen))<<endl;
    cout<< fixed << setprecision(1)<<"Min = "<<(*min_element(num, num + datalen))<<endl;
    double sum=0;
    double ave=0;
    for(int i=0;i<datalen;i++)
    {
        sum=sum+num[i];
    }
    ave=sum/datalen;
    cout<< fixed << setprecision(1)<<"Mean = " <<ave<<endl;
    double sum1=0;
    for(int i=0;i<datalen;i++)
    {
        sum1+= pow((num[i] - ave),2) / datalen;
    }
    cout<< fixed << setprecision(1)<<"Var = " <<sum1<<endl;
    file.close();
    return 0;

}