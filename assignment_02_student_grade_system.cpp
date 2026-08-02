// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
// TASK: Student Grade System
//
// Read a student score from 0 to 100 and convert it to a letter grade:
// A (80–100), B (70–79), C (60–69), D (50–59), or F (below 50).
// Implement the conversion in getGrade(). Invalid scores must display an error.
// =============================================================================

#include <iostream>
using namespace std;

char getGrade(int score)
{
    if (score < 0 || score > 100)
    {
        return '\0';
    }
    else if (score >= 80)
    {
        return 'A';
    }
    else if (score >= 70)
    {
        return 'B';
    }
    else if (score >= 60)
    {
        return 'C';
    }
    else if (score >= 50)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}


int main()
{
    int score;

    cout << "Enter student score (0-100): ";
    if (!(cin >> score)) {
        cout << "Error: Please enter a whole-number score." << endl;
        return 1;
    }

    char grade = getGrade(score);

    if (grade == '\0')
    {
        cout << "Error: Score must be between 0 and 100." << endl;
    }
    else
    {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}
