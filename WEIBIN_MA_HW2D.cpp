//
// Created by MWB20 on 9/17/2019.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

string removeVowels(string n){
    string n1;

    for(int i=0;i<n.length();i++){
        if(n[i] == 'a' ||n[i] == 'e' ||n[i] == 'i' ||n[i] == 'o' ||n[i] == 'u'||n[i] == 'A'||n[i] == 'E'
        ||n[i] == 'I'||n[i] == 'O'||n[i] == 'U')continue;
        n1+=n[i];
    }
    cout<<"The string without vowels: "<<n1;
}
bool palindrome(string n){
    string s =n;
    if(s.length()<=1) return false;
    for(int i=0;i<s.length()/2;i++)
        if(s[i]!=s[s.length()-1-i])
            return false;
    return true;
    }
    void rev(string n){
    string s = n;
        char sh = s[s.length() - 1];
        s.push_back('\n');

        reverse(s.begin(),s.end()-1);
        cout <<"The string backwards is : "<< s<<endl;
}

int main(){
    string s;
    cout<<"Please type in a string:"<<endl;
    getline(cin, s, '\n');


    rev(s);
    if(palindrome(s)==true){
        cout <<"This string is a palindrome."<<endl;
    }else{
        cout <<"This string is NOT a palindrome."<<endl;
    }

    removeVowels(s);


    return 0;

}