#include <iostream>
#include <stack>

#define MAX 100

class StackArray{
    // Declaring array to store stacks
    char arr[MAX];

    // Tracks the top element
    int top;
public:
    StackArray(){ 
        top = -1; 
    }

    // Pushing FUnction
    void push(char c){ 
        if(top < MAX-1) arr[++top] = c; 
    }

    // Poppong Function
    char pop(){
    if (top >= 0){
        char value = arr[top];
        top--;
        return value;
    } else{
        return '\0';
    }
}

    // isEmpty Function
    bool isEmpty(){
        return top == -1; 
    }
};

// Node Structure
struct Node{
    char data;
    Node* next;
};

class StackList{
    Node* top; //pointins the top node,

public:
    StackList(){
        top = nullptr;
    }

    void push(char c){
        Node* temp = new Node;
        temp->data = c;
        temp->next = top;
        top = temp;
    }

    // Popping Function
    char pop() {
        if (top == nullptr){
            return '\0';
        }

        char value = top->data;

        Node* temp = top;
        top = top->next;

        delete temp;
        return value;
    }

    // Error Catching
    bool isEmpty(){
        if (top == nullptr){
            return true;
        } else {
            return false;
        }
    }
};


bool isMatching(char open, char close){
    if (open == '(' && close == ')'){
        return true;
    }

    if (open == '{' && close == '}'){
        return true;
    }

    if (open == '[' && close == ']'){
        return true;
    }

    return false;
}

template <typename Stack>
bool checkBalanced(std::string expr, Stack &stack){
    for(char c : expr){
        if(c == '(' || c == '{' || c == '['){
            stack.push(c);
        } else if(c == ')' || c == '}' || c == ']'){
            if(stack.isEmpty()) return false;
            char top = stack.pop();
            if(!isMatching(top, c)) return false;
        }
    }
    return stack.isEmpty();
}


int main(){
    std::string expressions[] = {
        "(A + B) + (C - D)",
        "((A + B) + (C - D)",
        "((A +B ) + ( C- D))",
        "(A + B] + (C - D})"
    };

    std::cout << std::endl;
    std::cout << "   Using Array Stack   " << std::endl;
    for(std::string expr : expressions){
        StackArray s;
        std::cout << expr << " -> " << (checkBalanced(expr, s) ? "Valid" : "Invalid") << std::endl;
    }

    std::cout << std::endl;
    std::cout << "  Using Linked List Stack " << std::endl;
    for(std::string expr : expressions) {
        StackList s;
        std::cout << expr << " -> " << (checkBalanced(expr, s) ? "Valid" : "Invalid") << std::endl;
    }

    std::cout << std::endl;
    std::cout << "  Using STL Stack " << std::endl;
    for(std::string expr : expressions){
        std::stack<char> s;
        std::cout << expr << " -> ";
        bool valid = true;
        for(char c : expr){
            if(c == '(' || c == '{' || c == '['){
                s.push(c);
            } else if(c == ')' || c == '}' || c == ']'){
                if(s.empty()) { valid = false; break; }
                char top = s.top(); s.pop();
                if(!isMatching(top, c)) { valid = false; break; }
            }
        }
        if(!s.empty()) valid = false;
        std::cout << (valid ? "Valid" : "Invalid") << std::endl;
    }

    return 0;
}