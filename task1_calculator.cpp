// Basic Calculator - Level 1 Task 1
// Peace INGABIRE - Codeveda C/C++ Internship
// Description: Simple console calculator with +, -, *, / and division-by-zero protection
// Features: Menu loop for multiple calculations, input validation basics, clear output

#include <iostream>

using namespace std;

int main()
{
    char choice; // new variable to ask "again?"

    do
    { // start of loop

        double num1, num2;
        char op;

        cout << "Welcome to Peace INGABIRE's simple calculator!" << endl;
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operator (+ - * /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Result: ";
        switch (op)
        {
        case '+':
            cout << num1 + num2 << endl;
            break;

        case '-':
            cout << num1 - num2 << endl;
            break;

        case '*':
            cout << num1 * num2 << endl;
            break;

        case '/':
            if (num2 == 0)
            {
                cout << "Error Cannot divide by zero!" << endl;
            }
            else
            {
                cout << num1 / num2 << endl;
            }
            break;

        default:

            cout << "Error: Invalid operator! Use +, -, * or / only." << endl;
            break;
        }

        // Ask if user wants to calculate again
        cout << "\nDo you want to calculate again? (Yes/No): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // loop if y or Y

    cout << "Thank you for using the calculator! Goodbye." << endl;

    return 0;
}