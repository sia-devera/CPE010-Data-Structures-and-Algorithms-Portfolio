#include <iostream>

// Global Variables:
#define maxSize 10
int stackArr [maxSize];
int top = -1, newData;

/* Function Prototypes: 
    1. Top
    2. Push
    3. Pop
    4. isEmpty
    5. isFull
*/

bool isEmpty();
bool isFull();
void Top();

// Transformer Operators:
void Push();
void Pop();

int main(){
    int choice;
    while(true){
        std::cout << "=========================\n";
        std::cout << "Stack operations: " << std::endl;
        std::cout << "[1] Push [2] Pop [3] isEmpty [4] isFull [5] Top" << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choice;
        std::cout << "=========================\n";
        switch(choice){
            case 1: Push();
            break;
            case 2: Pop();
            break;
            case 3: std::cout << "Is the stack empty? " << isEmpty() << std::endl;
            break;
            case 4: std::cout << "Is the stack full? " << isFull() << std::endl;
            break;
            case 5: Top();
            break;
            default: std::cout << "Invalid Choice! " << std::endl;
            break;
        }
    }
    return 0;
}

bool isEmpty(){
    return(top == -1);
}

bool isFull(){
    return(top == maxSize -1);
}

void Top(){
    // Error Catching:
    if(isEmpty()){
        std::cout << "Stack is underflowing." << std::endl;
        return;
    }
    // Printing the top element:
    std::cout << "The top element is: " << stackArr[top] << std::endl;
}

void Push(){
    // Error Catching:
    if(isFull()){
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    // Asking the user what they want to insert: 
    std::cout << "What number do you want to push? " << std::endl;
    std::cin >> newData;

    stackArr [++top] = newData;
}

void Pop(){
    // Error Catching
    if(isEmpty()){
        std::cout << "Stack is underflowing." << std::endl;
        return;
    }

    // Display the item to the top
    std::cout << "Popping the top stack: " << stackArr[top] << std::endl;

    // Remove the top element
    top--;
}

// Display stack following LIFO principle
void displayAll() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    std::cout << "Stack elements: " << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << std::endl;
    }
}