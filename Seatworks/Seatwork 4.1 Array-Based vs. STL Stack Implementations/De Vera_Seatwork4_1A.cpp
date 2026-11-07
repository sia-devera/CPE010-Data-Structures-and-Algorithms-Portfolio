#include <iostream>
#include <stack>

int main (){
    // Create an object:
    std::stack <char> stack1;

    // Stacks: Push, Pop, isEmpty, isFull, Top 

    std::cout << "Is the stack empty? " <<stack1.empty() << std::endl;
    stack1.push('S');
    std::cout << "The current top of the stack is " <<stack1.top() << std::endl;
    stack1.push('O');
    std::cout << "The current top of the stack is " << stack1.top() << std::endl;
    stack1.push('P');
    std::cout << "The current top of the stack is " << stack1.top() << std::endl;
    stack1.push('H');
    std::cout << "The current top of the stack is " <<stack1.top() << std::endl;
    stack1.push('I');
    std::cout << "The current top of the stack is " <<stack1.top() << std::endl;
    stack1.push('A');

    return 0;

}