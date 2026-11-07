#include <iostream>
#include "stackList.h"

int main(){

    std::cout << "      Pushing 'C' 'P' 'E' onto the stack:     " << std::endl;
    //pushing function
    push('C');
    push('P');
    push('E'); // the current top since FILO

    //displaying the current top
    Top<char>();
    displayAll<char>();
    std::cout << "      Popping all the elements:     " << std::endl;

    while(!isEmpty<char>()){
        std::cout << " Popped: " << pop<char>() << std::endl;
    }

    std::cout << "      Testing the Enderflow:     " << std::endl;
    pop<char>();

    return 0;
    
}