//
// Created by MWB20 on 9/20/2019.
// version 0.6
//
#include <iostream>
#include <vector>
#include<fstream>
#include<sstream>

using namespace std;
double rowsum=0.0,colsum=0.0,tempsum=0.0;
vector<vector<int>>mtr;
string str;
double col[100] = {0};
void rowSum(){
    for(int i = 1; i < mtr.size(); ++i)
    {
        for(int j = 0; j < mtr[i].size(); ++j)
        {
            rowsum+=mtr[i][j];
            col[j]+=mtr[i][j];

            cout << mtr[i][j] << "\t";
        }

        cout<<"rowsum = "<<rowsum - tempsum;
        tempsum = rowsum;

        cout << endl;

    }
}
void colSum(){
    for(int i = 0; i < mtr[1].size(); ++i){
        cout<<col[i]<<"\t";
        colsum += col[i];
    }
    cout <<"totalsum = "<<colsum;

}
int main(){
    ifstream file;
    file.open("C:\\Users\\MWB20\\CLionProjects\\untitled3\\3C.dat");
    if(!file)
    {
        cout<<"file can not open"<<endl;
        abort();
    }
    while(getline(file,str)){
        istringstream input(str);
        vector<int> tmp;
        int a;
        while(input >> a)
            tmp.push_back(a);

        mtr.push_back(tmp);
    }
    rowSum();
    cout<<"---------------------------------------------"<<endl;
    colSum();
}
