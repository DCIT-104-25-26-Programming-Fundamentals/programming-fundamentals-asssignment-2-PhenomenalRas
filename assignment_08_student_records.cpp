// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
// TASK: Student Record Management System
//
// Store Student records (name, unique ID, and assessment scores) in a vector.
// The menu must add and display students, and calculate an individual average
// to two decimal places while handling invalid choices and missing IDs.
// =============================================================================

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double averageScore(const Student& student) {
    if (student.scores.empty()) return 0.0;
    double total = 0.0;
    for (double score : student.scores) total += score;
    return total / student.scores.size();
}

void addStudent(vector<Student>& students) {
    Student student;
    cout << "Student name: ";
    getline(cin >> ws, student.name);
    cout << "Student ID: ";
    if (!(cin >> student.id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: student ID must be a number.\n";
        return;
    }
    for (const Student& existing : students) {
        if (existing.id == student.id) {
            cout << "Error: student ID already exists.\n";
            return;
        }
    }
    int scoreCount;
    cout << "How many scores? ";
    if (!(cin >> scoreCount) || scoreCount < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: the number of scores cannot be negative.\n";
        return;
    }
    for (int i = 0; i < scoreCount; ++i) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        if (!(cin >> score)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: score must be a number.\n";
            return;
        }
        student.scores.push_back(score);
    }
    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully.\n";
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records have been added.\n";
        return;
    }
    cout << fixed << setprecision(2);
    for (const Student& student : students) {
        cout << "Name: " << student.name << "\nID: " << student.id << "\nScores:";
        for (double score : student.scores) cout << ' ' << score;
        cout << "\nAverage: " << averageScore(student) << "\n\n";
    }
}

void showStudentAverage(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: student ID must be a number.\n";
        return;
    }
    for (const Student& student : students) {
        if (student.id == id) {
            cout << fixed << setprecision(2) << student.name
                 << "'s average score: " << averageScore(student) << '\n';
            return;
        }
    }
    cout << "Error: student ID not found.\n";
}

int main() {
    vector<Student> students;
    int choice;
    do {
        cout << "\n1. Add student\n2. Display all students\n3. Calculate average score\n4. Quit\nEnter your choice (1-4): ";
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: enter a number from 1 to 4.\n"; continue;
        }
        if (choice == 1) addStudent(students);
        else if (choice == 2) displayStudents(students);
        else if (choice == 3) showStudentAverage(students);
        else if (choice != 4) cout << "Error: invalid menu choice.\n";
    } while (choice != 4);
    cout << "Goodbye!\n";
    return 0;
}
