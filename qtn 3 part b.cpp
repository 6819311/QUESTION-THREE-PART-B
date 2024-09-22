#include <iostream>
#include <iomanip> 
using namespace std;

double calculateTotalCost(int units) {
    double cost = 0.0;

    if (units <= 10) {
        cost = units * 150; // Cost for first 10 units
    } else if (units <= 20) {
        cost = (10 * 150) + ((units - 10) * 175); // Cost for units 11-20
    } else {
        cost = (10 * 150) + (10 * 175) + ((units - 20) * 200); // Cost for units beyond 20
    }

    // Applying  15% surcharge
    cost += cost * 0.15;

    return cost; 
}

int main() {
    double accountBalance, totalCost, finalCost;
    int waterUnits;

    // Prompting user for input
    cout << "Enter the amount loaded onto your account (UGX): ";
    cin >> accountBalance;
    cout << "Enter the number of water units consumed: ";
    cin >> waterUnits;

    // Calculating total cost
    totalCost = calculateTotalCost(waterUnits);

    // calcutaing  18% VAT
    finalCost = totalCost + (totalCost * 0.18);

    // Checking if balance is sufficient
    if (accountBalance >= finalCost) {
        accountBalance -= finalCost; // Deduct the final cost from the balance
        cout << fixed << setprecision(2); // Format to 2 decimal places
        cout << "Transaction successful!" << endl;
        cout << "Remaining balance: " << accountBalance << " UGX" << endl;
    } else {
        cout << "Error: Insufficient balance." << endl;
        cout << "Remaining balance before usage: " << accountBalance << " UGX" << endl;
    }

    return 0;
}

