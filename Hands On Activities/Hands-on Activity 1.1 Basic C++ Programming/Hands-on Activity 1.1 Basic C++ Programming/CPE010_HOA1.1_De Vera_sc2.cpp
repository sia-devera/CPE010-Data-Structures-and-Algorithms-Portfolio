#include <iostream>
// no using namespace

bool isGreater(int numA, int numB);

int main(){
    if (isGreater(96, -1)){
        std::cout << "A is GREATER than B." << std::endl;}
    else{
        std::cout << "A is NOT GREATER than B." << std::endl;}

    return 0;
}

bool isGreater(int numA, int numB){
    return (numA > numB);
}