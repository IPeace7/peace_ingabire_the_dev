// String Manipulation - level 1 Task 3
// Writen by Peace INGABIRE
// This program reverses a string, counts vowels, and checks if it's a palindrome

#include <iostream>
#include <cstring> // For strlen() and strcpy() - we'll use these for char arrays
#include <cctype>  // For tolower()
using namespace std;

// Function to reverse the string
void reverseString(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// Function to count vowels (a, e, i, o, u - case insensitive)
int countVowels(const char s[])
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = tolower(s[i]); // Make lowercase
        if (c == 'a' || c == 'e' || c == 'o' || c == 'u')
        {
            count++;
        }
    }
    return count;
}

// Function to check if palindrome (ignore spaces, case, non-letters)
bool isPalindrome(const char s[])
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        // Skip non-letter characters on left
        while (left < right && !isalpha(s[left]))
        {
            left++;
        }
        // Skip non-letter characters on right
        while (left < right && !isalpha(s[right]))
        {
            right--;
        }

        // Compare letters (ignore case)
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false; // not palindrome
        }

        left++;
        right--;
    }

    return true; // is palindrome
}

int main()
{
    // Code will go here
    char str[100]; // Array to hold up to 99 characters + null terminator

    cout << "Enter a string (max 99 characters): ";
    cin.getline(str, 100); // Safe way to read string with spaces

    cout << "You entered: " << str << endl;

    // Make a copy because we will modify str
    char reversed[100];
    strcpy(reversed, str);

    // Call the function to reverse
    reverseString(reversed);

    cout << "Reversed string: " << reversed << endl;

    // Call the function
    int vowels = countVowels(str);
    cout << "Number of vowels: " << vowels << endl;

    // Call the function
    if (isPalindrome(str))
    {
        cout << "Yes, it is a palindrome!" << endl;
    }
    else
    {
        cout << "No, it is not a palindrome." << endl;
    }
    return 0;
}