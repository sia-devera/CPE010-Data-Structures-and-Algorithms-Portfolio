// C++ code to illustrate Queue in the Standard Template Library (STL)

#include <iostream>
#include <queue>
#include <string>

void display(std::queue<std::string> q) {
    std::queue<std::string> c = q;

    while (!c.empty()) {
        std::cout << " " << c.front();
        c.pop();
    }

    std::cout << std::endl;
}

int main() {

    // Array of students' names
    std::string Nstudents[] = {
        "S",
        "O",
        "P",
        "H",
        "I",
        "A"
    };

    std::queue<std::string> a;

    // Insert students into the queue
    for (int i = 0; i < 6; i++) {
        a.push(Nstudents[i]);
    }

    std::cout << "The queue is: ";
    display(a);
    
    // Checking if the quueue is empty
    std::cout << "Is the queue empty?     " << a.empty() << std::endl;

    // Asking how many is in the queue
    std::cout << "How many is in the queue?     " << a.size() <<  std::endl;

    // The front letter
    std::cout << "What is the front letter?     " << a.front() <<  std::endl;

    // The las letter
    std::cout << "What is the last letter?     " << a.back() <<  std::endl;

    // Popping the letters
    std::cout << "Popping the front letters . . . " << std::endl;

    a.pop();
    a.pop();
    a.pop();

    std::cout << "Current queue in line is: ";
    display(a);

    // Inserting new element
    a.push(" ");
    a.push("C");
    a.push("P");
    a.push("E");

    std::cout << "The new queue a is: ";
    display(a);

    return 0;
}