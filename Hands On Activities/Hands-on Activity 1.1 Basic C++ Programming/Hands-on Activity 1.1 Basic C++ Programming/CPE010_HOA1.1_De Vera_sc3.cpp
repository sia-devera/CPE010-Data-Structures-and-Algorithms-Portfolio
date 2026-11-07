#include <iostream>
// still no using of namespace

void displaySum (
    int num1, 
    int num2
);

int main(){
    displaySum(1345, 218);

    return 0;
}

void displaySum (
    int num1, 
    int num2)
{
    std::cout << "The sum of the two numbers is: " << num1 + num2 << std::endl;
}