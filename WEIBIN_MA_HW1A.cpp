//
// Created by MWB20 on 9/2/2019.
//

#include <iostream>
 int main(){
    int number1 = 0;
    std::cout<<"Please enter a positive integer:\n";
    std::cin>>number1;
    std::cout<<number1<<" ";
    for(int n=1;n<number1;) {
        if (number1 % 2 == 1) {
            number1 = number1 * 3 + 1;
            std::cout << number1<<" ";

        } else {
            number1 = number1 / 2;
            std::cout << number1<<" ";
        }
    }
    return 0;
}
