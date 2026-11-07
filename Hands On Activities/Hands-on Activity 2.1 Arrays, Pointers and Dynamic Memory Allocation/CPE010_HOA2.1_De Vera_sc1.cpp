#include <iostream>
#include <string>

class Groceries {
private:
    std::string name;
    int price;
    int quantity;

public:
    // Constructor
    Groceries(std::string item = "", int php = 0, int quant = 0) {
        name = item;
        price = php;
        quantity = quant;
        std::cout << "Constructor was called." << std::endl;
    }

    // Destructor
    ~Groceries() {
        std::cout << "Destructor was called." << std::endl;
    }

    // Copy Constructor
    Groceries(const Groceries &copyItem) {
        std::cout << "Copy Constructor was called." << std::endl;
        name = copyItem.name;
        price = copyItem.price;
        quantity = copyItem.quantity;
    }

    // Display Attributes
    void printOutput() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Subtotal: PHP " << calculateSum() << std::endl;
        std::cout << std::endl;
    }

    // Copy Assignment Operator
    Groceries& operator=(const Groceries &copyItem) {
        std::cout << "Copy Assignment Operator was called" << std::endl;

        if (this != &copyItem) {
            name = copyItem.name;
            price = copyItem.price;
            quantity = copyItem.quantity;
        }
        return *this;
    }

    int calculateSum() {
        return price * quantity;
    }
};

// Fruit Class
class Fruit: public Groceries {
public:
    Fruit(std::string item = " ", int php = 0, int quant = 0)
        : Groceries(item, php, quant) {}

    ~Fruit() {}

    Fruit(const Fruit& copyItem)
        : Groceries(copyItem) {}

    Fruit& operator=(const Fruit& copyItem) {
        Groceries::operator=(copyItem);
        return *this;
    }

    void printOutput() {
        std::cout << "Fruit" << std::endl;
        Groceries::printOutput();
        std::cout << std::endl;
    }
};

// Vegetable Class
class Vegetable: public Groceries {
public:
    Vegetable(std::string item = " ", int php = 0, int quant = 0)
        : Groceries(item, php, quant) {}

    ~Vegetable() {}

    Vegetable(const Vegetable& copyItem)
        : Groceries(copyItem) {}

    Vegetable& operator=(const Vegetable& copyItem) {
        Groceries::operator=(copyItem);
        return *this;
    }

    void display() {
        std::cout << "Vegetable" << std::endl;
        Groceries::printOutput();
        std::cout << std::endl;
    }
};

// Total Sum 
int TotalSum(Groceries* list[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        if (list[i] != nullptr) {
            total += list[i]->calculateSum();
        }
    }

    return total;
}

int main() {

    Groceries* GroceryList[4];

    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    std::cout << std<< endl<< "Jenna Grocery List: " << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        GroceryList[i]->printOutput();
    }

    std::cout << "Total Amount: PHP "
              << TotalSum(GroceryList, 4)
              << std::endl;

    std::cout << "Delete Lettuce from the list.";

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    std::cout << "Final Total Amount is PHP "
              << TotalSum(GroceryList, 4)
              << std::endl;

    for (int i = 0; i < 3; i++) {
        delete GroceryList[i];
    }

    return 0;
}