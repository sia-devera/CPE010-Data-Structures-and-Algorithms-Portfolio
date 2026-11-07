#include <iostream>
#include "queueLL.h"
#include "queueARR.h"

int main(){
    queueArr<int> q(6); 

    // Enqueuing
    q.Enqueue(1);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Enqueue(2);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Enqueue(3);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Enqueue(4);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Enqueue(5);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Enqueue(6);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;    
    q.Enqueue(7);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    
    // Dequeuing
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl; 

    return 0;
}