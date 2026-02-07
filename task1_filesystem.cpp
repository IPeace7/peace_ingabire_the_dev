// Level 3 - Task 1: Simple File System Simulation
// CodeVeda Internship - C/C++ Development Track
// Author: Peace INGABIRE
// Simulates basic file operations: create, delete, read, write

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>

using namespace std;

void showMenu()
{
    cout << "\n--- File System Simulation ---\n";
    cout << "1. Create a new file\n";
    cout << "2. Delete a file\n";
    cout << "3. Read (display) file content\n";
    cout << "4. Write/Append to a file\n";
    cout << "5. List all files in the current directory\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-5): ";
}
void listFiles()
{
    namespace fs = std::filesystem;

    cout << "\nFiles in current directory:\n";
    cout << "-----------------------------\n";

    bool hasFiles = false;
    for (const auto &entry : fs::directory_iterator("."))
    {
        if (entry.is_regular_file())
        {
            cout << entry.path().filename().string() << "\n";
            hasFiles = true;
        }
    }
    if (!hasFiles)
    {
        cout << "(No regular files found in current directory)\n";
    }
}

int main()
{
    int choice;
    string filename;

    do
    {
        showMenu();

        if (!(cin >> choice))
        {
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            cout << "Enter filename to create (e.g. note.txt): ";
            getline(cin, filename);

            ofstream file(filename); // create or overwrite the file
            if (file.is_open())
            {
                cout << "File created successfully: " << filename << "\n";
                file.close();
            }
            else
            {
                cout << "Error: Could not create file " << filename << "\n";
            }
            break;
        }
        case 2:
        {
            cout << "Enter filename to delete: ";
            getline(cin, filename);

            if (remove(filename.c_str()) == 0)
            {
                cout << "File deleted successfully: " << filename << "\n";
            }
            else
            {
                cout << "Error: Cannot delete file '" << filename << "'(file may not exist or no permission)\n";
            }
            break;
        }
        case 3:
        {
            cout << "Enter filename to read: ";
            getline(cin, filename);

            ifstream file(filename);
            if (!file.is_open())
            {
                cout << "Error: Cannot open file " << filename << " (maybe it doesn't exist?)\n";
                break;
            }

            cout << "\nContent of " << filename << ":\n";
            cout << "-------------------------------\n";

            string line;
            bool hasContent = false;
            while (getline(file, line))
            {
                cout << line << "\n";
                hasContent = true;
            }

            file.close();

            if (!hasContent)
            {
                cout << "(File is empty)\n";
            }
            cout << "--------------------------------\n";
            break;
        }
        case 4:
        {
            cout << "Enter filename to write/append: ";
            getline(cin, filename);

            cout << "Enter text to write (press Enter twice to finish):\n";

            ofstream file(filename, ios::app);
            if (!file.is_open())
            {
                cout << "Error: Cannot open file '" << filename << "' for writing.\n";
                break;
            }

            string line;
            while (getline(cin, line))
            {
                if (line.empty())
                    break;
                file << line << "\n";
            }

            file.close();
            cout << "Text appended successfully to " << filename << "\n";

            cout << "Quick preview of the file content:\n";
            ifstream preview(filename);
            string content;
            while (getline(preview, content))
            {
                cout << content << "\n";
            }
            preview.close();
            break;
        }
        case 5:
        {
            listFiles();
            break;
        }
        case 6:
        {
            cout << "Goodbye! Thank you for using our File System Simulation! See you next time.\n";
            break;
        }
        default:
        {
            cout << "Invalid choice. Try again.\n";
        }
        }
    } while (choice != 5);

    return 0;
}