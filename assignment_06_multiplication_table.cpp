// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
// TASK: Multiplication Table Generator
//
// Part A prints a multiplication table from 1 to 12 for one number.
// Part B prints all tables from 1 through N, with a separator between tables.
// Use a separate function for each part and reject invalid N values.
// =============================================================================

#include <iostream>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":\n";
    for (int multiplier = 1; multiplier <= 12; ++multiplier) {
        cout << number << " x " << multiplier << " = "
             << number * multiplier << '\n';
    }
}

void printTablesUpTo(int limit) {
    if (limit <= 0) {
        cout << "Error: N must be a positive integer.\n";
        return;
    }
    for (int number = 1; number <= limit; ++number) {
        printTable(number);
        if (number < limit) cout << "---------------------------\n";
    }
}

int main() {
    int number, limit;
    cout << "Enter a number for its multiplication table: ";
    if (!(cin >> number)) {
        cout << "Error: Please enter a whole number.\n";
        return 1;
    }
    printTable(number);

    cout << "Enter N to print tables from 1 to N: ";
    if (!(cin >> limit) || limit <= 0) {
        cout << "Error: N must be a positive integer.\n";
        return 1;
    }
    printTablesUpTo(limit);
    return 0;
}
