// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
// TASK: Console-Based Simple Calculator
//
// Repeatedly let the user add, subtract, multiply, divide, find a modulus, or
// calculate an exponent. Each operation has its own function. Results display
// to two decimal places and division/modulus by zero must be handled safely.
// =============================================================================

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
long long modulus(long long a, long long b) { return a % b; }
double power(double base, double exponent) { return pow(base, exponent); }

int main() {
    int choice;
    do {
        cout << "\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Exponentiation\n7. Quit\nSelect an operation (1-7): ";
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: enter a number from 1 to 7.\n"; continue;
        }
        if (choice == 7) break;
        if (choice < 1 || choice > 6) { cout << "Error: invalid menu choice.\n"; continue; }

        double first, second;
        cout << "Enter first number: ";
        if (!(cin >> first)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter valid numbers.\n"; continue;
        }
        cout << "Enter second number: ";
        if (!(cin >> second)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter valid numbers.\n"; continue;
        }
        cout << fixed << setprecision(2);
        if ((choice == 4 || choice == 5) && second == 0) {
            cout << "Error: Cannot divide by zero.\n";
        } else if (choice == 1) cout << "Result: " << add(first, second) << '\n';
        else if (choice == 2) cout << "Result: " << subtract(first, second) << '\n';
        else if (choice == 3) cout << "Result: " << multiply(first, second) << '\n';
        else if (choice == 4) cout << "Result: " << divide(first, second) << '\n';
        else if (choice == 5) {
            const double minInteger = static_cast<double>(numeric_limits<long long>::min());
            const double maxInteger = static_cast<double>(numeric_limits<long long>::max());
            if (first < minInteger || first > maxInteger || second < minInteger || second > maxInteger ||
                first != trunc(first) || second != trunc(second))
                cout << "Error: modulus requires whole numbers.\n";
            else
                cout << "Result: " << modulus(static_cast<long long>(first), static_cast<long long>(second)) << '\n';
        }
        else cout << "Result: " << power(first, second) << '\n';
    } while (true);
    cout << "Goodbye!\n";
    return 0;
}
