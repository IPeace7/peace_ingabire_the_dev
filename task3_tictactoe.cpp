// Level 3 - Task 3: Tic-Tac-Toe
// Author:Peace INGABIRE -CodeVeda Internship

// A classic two-player game played on 3*3 grid.
// Players take turns placing X or 0.
// The first to make a line of 3 wins.
// If no one wins and the board is full --> draw.

#include <iostream>
using namespace std;

const int SIZE = 3;

// Board: ' ' = empty, 'X' = player 1, 'O' = player 2
char board[SIZE][SIZE] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

// Print the board nicely
void printBoard()
{
    cout << "\n 0  1  2\n\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j];
            if (j < SIZE - 1)
                cout << "|";
        }
        cout << "\n";
        if (i < SIZE - 1)
            cout << "  ---+---+---\n";
    }
    cout << "\n";
}

// Returns 'X' if X wins, '0' if 0 wins, ' ' if nop winner yet, 'D' if draw
char checkWinner()
{
    // Check rows
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][2];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }

    // Check for draw (board full, no winner)
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return ' '; // still empty cells --> now inner yet
        }
    }
    return 'D';
}
int main()
{
    cout << "Tic-Tac-Toe Game\n";
    cout << "Player 1: X     Player 2: O\n\n";

    char currentPlayer = 'X'; // X starts
    int moves = 0;

    printBoard();

    while (moves < 9)
    {
        int row, col;
        cout << "Player" << (currentPlayer == 'X' ? "1 (X)" : "2 (O)") << " turn:\n";
        cout << "Enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Basic validation (later we make it better)
        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            cout << "Invalid position! Use 0-2 only.\n";
            continue;
        }

        if (board[row][col] != ' ')
        {
            cout << "Position already taken! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        // Show updated board
        printBoard();

        char winner = checkWinner();
        if (winner == 'X' || winner == 'O')
        {
            cout << "Player " << (winner == 'X' ? "1 (x)" : "2 (O)") << " WINS! 🎉\n";
            break;
        }
        else if (winner == 'D')
        {
            cout << "It's a DRAW!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Game over - board is full!\n";

    char playAgain;
    do
    {
        cout << "\nPlay Agin? (y/n): ";
        cin >> playAgain;
        cin.ignore(); // clear newline

        if (playAgain == 'y' || playAgain == 'Y')
        {
            // Reset board
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    board[i][j] = ' ';
            moves = 0;
            currentPlayer = 'X';
            printBoard();
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}