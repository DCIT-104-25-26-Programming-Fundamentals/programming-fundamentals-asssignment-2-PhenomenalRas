// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
// TASK: Fibonacci Sequence Generator
//
// Part A: print the first N Fibonacci terms using a loop.
// Part B: determine whether a user-supplied number belongs to the sequence.
// N must be positive; use separate functions for both parts.
// =============================================================================

#include <iostream>
#include <limits>
using namespace std;

void printFibonacci(int terms) {
    if (terms <= 0) {
        cout << "Error: the number of terms must be positive.\n";
        return;
    }

    long long first = 0, second = 1;
    cout << "Fibonacci sequence:";
    for (int i = 0; i < terms; ++i) {
        cout << ' ' << first;
        long long next = first + second;
        first = second;
        second = next;
    }
    cout << '\n';
}

bool isFibonacci(long long number) {
    if (number < 0) return false;
    long long first = 0, second = 1;
    while (first < number && second <= numeric_limits<long long>::max() - first) {
        long long next = first + second;
        first = second;
        second = next;
    }
    return first == number;
}

int main() {
    int terms;
    cout << "How many terms? ";
    if (!(cin >> terms) || terms <= 0) {
        cout << "Error: the number of terms must be positive.\n";
        return 1;
    }
    printFibonacci(terms);

    long long number;
    cout << "Enter a number to check: ";
    if (!(cin >> number)) {
        cout << "Error: Please enter a whole number.\n";
        return 1;
    }
    cout << number << (isFibonacci(number) ? " is" : " is NOT")
         << " a Fibonacci number.\n";
    return 0;
}
