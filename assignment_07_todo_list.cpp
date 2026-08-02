// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
// TASK: Console-Based To-Do List Application
//
// Use a vector<string> and a menu loop to add, view, and delete tasks.
// Each feature must be a separate function; invalid choices must not crash
// the program.
// =============================================================================

#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty.\n";
        return;
    }
    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) cout << i + 1 << ". " << tasks[i] << '\n';
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin >> ws, task);
    if (task.empty()) {
        cout << "Error: a task cannot be empty.\n";
        return;
    }
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"\n";
}

void deleteTask(vector<string>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    int number;
    cout << "Enter task number to delete: ";
    if (!(cin >> number)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: enter a valid task number.\n";
        return;
    }
    if (number < 1 || number > static_cast<int>(tasks.size())) {
        cout << "Error: invalid task number.\n";
        return;
    }
    cout << "Task \"" << tasks[number - 1] << "\" has been removed.\n";
    tasks.erase(tasks.begin() + number - 1);
}

int main() {
    vector<string> tasks;
    int choice;
    do {
        cout << "\n1. Add task\n2. View tasks\n3. Delete task\n4. Quit\nEnter your choice (1-4): ";
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: enter a number from 1 to 4.\n"; continue;
        }
        if (choice == 1) addTask(tasks);
        else if (choice == 2) viewTasks(tasks);
        else if (choice == 3) deleteTask(tasks);
        else if (choice != 4) cout << "Error: invalid menu choice.\n";
    } while (choice != 4);
    cout << "Goodbye!\n";
    return 0;
}
