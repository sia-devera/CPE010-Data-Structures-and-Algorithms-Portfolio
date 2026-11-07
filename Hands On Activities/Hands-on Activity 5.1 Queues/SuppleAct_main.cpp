#include <iostream>
#include "SPA_QLL.h"

int main() {

    qNode* front = nullptr;
    qNode* back = nullptr;

    Printing p1(1, "Sophia", 5);
    Printing p2(2, "Anna", 10);
    Printing p3(3, "Elsa", 3);
    Printing p4(4, "Cinderella", 8);
    Printing p5(5, "Spider-Man", 12);

    std::cout << "          PENDING PRINTING DOCUMENTS        " << std::endl;
    std::cout << std::endl;

    enqueue(p1, &front, &back);
    enqueue(p2, &front, &back);
    enqueue(p3, &front, &back);
    enqueue(p4, &front, &back);
    enqueue(p5, &front, &back);

    std::cout << "          PENDING PRINTING JOBS          " << std::endl;

    display(front);
    std::cout << "          PROCESSING JOBS         " << std::endl;

    while (front != nullptr) {
        std::cout << "Now printing . . . " << std::endl;
        front->data.display();
        std::cout << "You may now get your document(s)." << std::endl;
        std::cout << std::endl;

        dequeue(&front, &back);
    }

    std::cout << "          No more doucments to print. On standby.          " << std::endl;

    return 0;
}