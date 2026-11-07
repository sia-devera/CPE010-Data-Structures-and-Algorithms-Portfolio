#include <iostream>
#include "queueLL.h"

int main(){
    qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;

    enqueue (1, &front, &back);
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;
    enqueue(2, &front, &back);
    enqueue(3, &front, &back);
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;

    display(front);
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);
    display(front);

    return 0;
}