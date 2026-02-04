// Group Members:
// Peace INGABIRE
// UWIMANIKUNDA Patrick
// NEZA SHIMWA Niel Ivan
#include <stdio.h>
#include <stdbool.h>
double add(float a, float b)
{
    return a + b;
}
double subtract(float a, float b)
{
    return a - b;
}
double multiply(float a, float b)
{
    return a * b;
}
double divide(float a, float b)
{
    return a / b;
}
int main()
{
    int choice;
    bool stopper = true;
    while (stopper)
    {

        double result;
        printf("Choose the preferred operation !\n");
        printf("1.Addition\n");
        printf("2.Subtraction\n");
        printf("3.Multiplication\n");
        printf("4.Division\n");
        printf("5.Exit \n");
        scanf("%d", &choice);
        double numbers[2];
        switch (choice)
        {
        case (1):
            printf("Enter two numbers: ");
            for (int i = 0; i < 2; i++)
            {
                scanf(" %lf", &numbers[i]);
            }
            result = add(numbers[0], numbers[1]);
            printf("The result is %.2f \n", result);
            break;
        case (2):
            printf("Enter two numbers: ");
            for (int i = 0; i < 2; i++)
            {
                scanf(" %lf", &numbers[i]);
            }
            result = subtract(numbers[0], numbers[1]);
            printf("The result is %.2f \n", result);
            break;
        case (3):
            printf("Enter two numbers: ");
            for (int i = 0; i < 2; i++)
            {
                scanf(" %lf", &numbers[i]);
            }
            result = (numbers[0], numbers[1]);
            printf("The result is %.2f \n", result);
            break;
        case (4):
            printf("Enter two numbers: ");
            for (int i = 0; i < 2; i++)
            {
                scanf(" %lf", &numbers[i]);
            }
            result = divide(numbers[0], numbers[1]);
            printf("The result is %.2f \n", result);
            break;
        default:
            stopper = false;
            printf("See you next time ! We are sorry to see you go \n");
            break;
        }
    }
}