#include <iostream>
#include "BinaryTree.h"

int main(){

    BinaryTree<char>* root = new BinaryTree<char>('A');
    root -> insertChildLeft('B');
    root -> insertChildRight('C');

    root ->getLeftChild() -> insertChildLeft('D');
    root ->getLeftChild() -> insertChildRight('E');
    root ->getLeftChild() -> insertChildLeft('F');

    std::cout << "The root is element: " << root -> getRootVal()<< std::endl;
    std::cout << "The left child of root 'A' is: " << root -> getLeftChild() -> getRootVal() << std::endl;
    std::cout << "The left child of 'node B' is: " << root -> getLeftChild() -> getLeftChild() -> getRootVal() << std::endl;
    std::cout << "The left child of 'node F' is: " << root->getLeftChild()->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "The right child of 'node B' is: " << root -> getLeftChild() -> getRightChild() -> getRootVal() << std::endl;
    std::cout << "The right child of 'root A' is: " << root -> getRightChild() -> getRootVal() << std::endl;
    std::cout << "The right child of 'node C' is: " << root -> getRightChild() -> getRightChild() -> getRootVal() << std::endl;

    root -> getRightChild() -> setRootVal('S');
    std::cout << "The NEW Right Child of 'root A' is: " << root->getRightChild()->getRootVal() << std::endl;
    std::cout << "The right child of 'node S' is: " << root->getRightChild()->getRightChild()->getRootVal() << std::endl;

    return 0;
}