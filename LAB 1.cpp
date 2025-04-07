#include <iostream>

using namespace std;

struct Product
{
    string sNumber;
    string name;
    double price;
};

int main()
{
    Product products[20] = {
        {"Psnn1", "Yoyos", 1.5},
        {"Psnn2", "Fanta", 2.5},
        {"Psnn3", "Mojo", 6.5},
        {"Psnn4", "Papas", 7.0},
        {"Psnn5", "Cookie", 9.5},
        {"Psnn6", "Milk", 10},
        {"Psnn7", "Brothers", 10.5},
        {"Psnn8", "Milkit", 11.0},
        {"Psnn9", "Munch", 13.0},
        {"Psnn10", "Fruity", 15.0},
        {"Psnn11", "Guava", 16.5},
        {"Psnn12", "Apples", 18.0},
        {"Psnn13", "Pot", 20.99},
        {"Psnn14", "Flask", 23.0},
        {"Psnn15", "Mat", 24.0},
        {"Psnn16", "Bag", 25.99},
        {"Psnn17", "Bulb", 26.0},
        {"Psnn18", "Spray", 36.0},
        {"Psnn19", "Broom", 45.99},
        {"Psnn20", "Board", 50.0}
    };

    int quantity[5] = {0}; // Quantity for each transaction
    string serial[5];      // Serial number for each transaction
    double totals[5] = {0}; // Total for each transaction
    double grandTotal = 0.0;

    cout << "\t\t\tWelcome to Snack Shack" << endl << endl;
    for (int i = 0; i < 5;) // Increment when we find a product
    {
        cout << "\t\tEnter the product's serial number: ";
        cin >> serial[i];

        bool found = false;

        for (int j = 0; j < 20; j++)
        {
            if (serial[i] == products[j].sNumber)
            {
                cout << "\t\tEnter the product's quantity: ";
                cin >> quantity[i]; // Store quantity at transaction index

                if (quantity[i] < 0) // Basic input validation
                {
                    cout << "\t\tInvalid quantity. Try again." << endl;
                    continue;
                }

                totals[i] = products[j].price * quantity[i]; // Use product index j for price
                grandTotal += totals[i];
                found = true;
                i++; // Move to the next transaction
                break;
            }
        }

        if (!found)
        {
            cout << "\t\tInvalid serial number. Try again" << endl;
        }
    }

    // Output
    cout << endl << "#\tName\t\tQuantity\tUnit Price\tTotal" << endl;
    cout << "===============================================================" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (serial[i] == products[j].sNumber) // Match serial to product
            {
                cout << i + 1 << "\t" << products[j].name << "\t\t" << quantity[i] << "\t\t"
                     << products[j].price << "\t\t" << totals[i] << endl;
                break;
            }
        }
    }
    cout << "===============================================================" << endl;
    cout << "\nGrand Total: ZMK" << grandTotal << "\n";

    return 0;
}
