// Simple Student Management System - Level 2 Task 1
// Written by Peace INGABIRE
// For CodVeda Internship
// This program let's you add, delete, display, and update student records
// Uses structs, file handling, menu

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Student
{
    string name;
    int id;
    float grade;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

const string FILENAME = "students.txt";

void showMenu()
{
    cout << "\n--- Student Management Menu ---\n";
    cout << "1. Add a new student\n";
    cout << "2. View all students\n";
    cout << "3. Update a student\n";
    cout << "4. Delete a student\n";
    cout << "5. Save and Exit\n";
    cout << "Enter your choice (1-5): ";
}

void loadStudents()
{
    ifstream inFile(FILENAME);
    if (!inFile)
    {
        cout << "No previous data found. Starting fresh. \n";
        studentCount = 0;
        return;
    }

    if (!(inFile >> studentCount))
    {
        cout << "Error reading number of students → starting empty.\n";
        studentCount = 0;
        inFile.close();
        return;
    }

    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    int loaded = 0;
    for (int i = 0; i < studentCount && i < MAX_STUDENTS; i++)
    {
        if (!getline(inFile, students[i].name, ','))
            break;
        if (!(inFile >> students[i].id))
            break;
        inFile.ignore(numeric_limits<streamsize>::max(), ',');
        if (!(inFile >> students[i].grade))
            break;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        loaded++;
    }

    /*outFile << studentCount << '\n';

    for (int i = 0; i < studentCount; ++i) {
        outFile << students[i].name << ','
                << students[i].id << ','
                << students[i].grade << '\n';
    }

    outFile.close();
    cout << "Saved " << studentCount << " students.\n";
}*/

    studentCount = loaded;
    inFile.close();

    if (studentCount == 0)
    {
        cout << "No valid students loaded.\n";
    }
    else
    {
        cout << "Loaded " << studentCount << " students.\n";
    }
}

void saveStudents()
{
    ofstream outFile(FILENAME);
    if (!outFile)
    {
        cout << "Error: Cannot open file for saving!\n";
        return;
    }

    outFile << studentCount << '\n';

    for (int i = 0; i < studentCount; i++)
    {
        outFile << students[i].name << ','
                << students[i].id << ','
                << students[i].grade << '\n';
    }

    outFile.close();
    cout << "Saved " << studentCount << " students.\n";
}

int main()
{
    loadStudents();

    int choice;

    do
    {
        showMenu();

        if (!(cin >> choice))
        {
            cout << "Invalid input - please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Debug: choice = " << choice << "\n"; // ← add this temporarily !!!

        if (choice == 1)
        {
            if (studentCount >= MAX_STUDENTS)
            {
                cout << "Sorry, maximum number of students reached!" << endl;
                continue;
            }

            cout << "Enter student name: ";
            getline(cin, students[studentCount].name);

            cout << "Enter student ID: ";
            if (!(cin >> students[studentCount].id))
            {
                cout << "Invalid ID - not added.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter student grade (0-100): ";
            float g;
            if (!(cin >> g) || g < 0 || g > 100)
            {
                cout << "Invalid grade - not added.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            students[studentCount].grade = g;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            studentCount++;
            cout << "Student added successfully! Total students now: " << studentCount << endl;
        }
        else if (choice == 2)
        {
            if (studentCount == 0)
            {
                cout << "No students added yet. \n"
                     << endl;
            }
            else
            {
                cout << "\n--- List of Students ---\n"
                     << endl;
                for (int i = 0; i < studentCount; i++)
                {
                    cout << i + 1 << ". " << students[i].name
                         << " (ID: " << students[i].id << ", Grade: " << students[i].grade << ")\n"
                         << endl;
                }
            }
        }
        else if (choice == 5)
        {
            saveStudents();
            cout << "Goodbye! (save not implemented yet)\n";
            break;
        }
        else
        {
            cout << "Invalid choice, try again.\n";
        }

    } while (true);

    return 0;
}