// Level 2 - Task 2: Sorting and Searching Algorithms
// CodVeda Internship - C/C++ Development Track
// Author: Peace INGABIRE
// Implements: Bubble/Selection/Insertion Sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to fill an array with random numbers between 1 and 100
void fillRandom(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Bubble Sort: Simple comparison-based sort
// Time Complexity: 0(n^2) in worst and average case, 0(n) if already sorted
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Selection Sort: Finds the minimum element and puts it at the beginning
// Time Complexity: 0(n^2) always (no early exit possible)
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // Find the minimum element in unsorted part
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum with the first element
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void showSortMenu()
{
    cout << "\nChoose sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Back to main menu\n";
    cout << "Enter Choice: ";
}
int main()
{
    srand(time(0));

    cout << "Level 2 - Task 2: Sorting and Searching Algorithms\n";
    cout << "------------------------------------------------\n\n";

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Generate and sort array\n";
        cout << "2. Exit\n";
        cout << "Enter choice:";

        if (!(cin >> choice))
        {
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            int size;
            cout << "Enter array size (max 1000): ";

            if (!(cin >> size))
            {
                cout << "Invalid input!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (size <= 0 || size > 1000)
            {
                cout << "Size must be between 1 and 1000.\n";
                continue;
            }

            int arr[1000];
            fillRandom(arr, size);

            cout << "\nGenerated array (before sorting):\n";
            printArray(arr, size);

            // Sub-menu for sorting choice
            int sortChoice;
            showSortMenu();
            if (!(cin >> sortChoice))
            {
                cout << "Invalid Choice!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (sortChoice == 1)
            {
                bubbleSort(arr, size);
                cout << "\nSorted with Bubble Sort:\n";
                printArray(arr, size);
                cout << "\nBubble Sort was used --> Easy to understand, but gets slow with large lists.\n";
            }

            else if (sortChoice == 2)
            {
                selectionSort(arr, size);
                cout << "\nSorted with Selection Sort:\n";
                printArray(arr, size);
                cout << "\nSelection Sort was used --> Always checks the whole remaining list, so it's steady but still slow for big data.\n";
            }
            else if (sortChoice == 3)
            {
                cout << "Back to main menu.\n";
            }
            else
            {
                cout << "Invalid sort choice.\n";
            }
        }
        else if (choice == 2)
        {
            cout << "Goodbye! Thanks for using our system, Come back again.\n";
        }
        else
        {
            cout << "Invalid main menu choice.\n";
        }
    } while (choice != 2);

    return 0;
}