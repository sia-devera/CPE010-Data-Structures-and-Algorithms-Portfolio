#include <iostream>
#include <string>
using namespace std;

int main() 
{

    string groceries[6] = {
        "Pinoy Tasty", "Yakult", "Rebisco", "Soap", "Shampoo", "Sardines"};

    float prices[6] = {
        45.00, 48.50, 88.25, 72.20, 78.99, 23.00};

    string item;
    float total = 0, payment, change;
    bool found;

    cout << "\n";
    cout << "Billing Receipt"<< endl;
    cout << "Name of Product" << endl;
    cout << "Type 'total' when finished." << endl;
    cout << "\n";

    while (true) {
        cout << "Enter Product: ";
        getline(cin, item) ;

        if (item == "total")
            break;

        found = false;

        for (int i = 0; i < 6; i++) 
        {
            if (item == groceries[i]) 
            {
                cout << groceries[i] << " PHP " << prices[i] << endl;
                total += prices[i];
                found = true;
                break;
            }
        }

        if (!found) 
        {
            cout << "Product not found.\n";
        }
    }

    cout << "Total Amount: PHP " << total << endl;

    cout << "Payment: PHP ";
    cin >> payment;

    change = payment - total;

    cout << "Change: PHP " << change << endl;

    cout << "@DSA Grocery Shop.";

    return 0;
}