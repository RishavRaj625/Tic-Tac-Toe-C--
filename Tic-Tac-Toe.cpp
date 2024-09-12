#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row i is filled with player's mark
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column i is filled with player's mark
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Top-left to bottom-right diagonal is filled with player's mark
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Top-right to bottom-left diagonal is filled with player's mark
    }

    return false; // No winning pattern found
}

// Function to check if the board is full (tie game)
bool checkTie(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There's an empty cell, game is not tied
            }
        }
    }
    return true; // All cells are filled, game is tied
}

// Function to handle a player's move
void playerMove(vector<vector<char>>& board, char player) {
    int row, col;
    cout << "Player " << player << "'s turn. Enter the row (1-3) : ";
    cin >> row;
    cout<< "Enter the column (1-3) : ";
    cin >> col;


    // Convert 1-based index to 0-based index
    --row;
    --col;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player; // Place player's mark on the board
    } else {
        cout << "Invalid move. Please try again." << endl;
        playerMove(board, player); // Retry move
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board with empty cells
    char currentPlayer = 'X'; // Player 'X' starts the game

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    displayBoard(board);

    while (true) {
        playerMove(board, currentPlayer);
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        }

        if (checkTie(board)) {
            cout << "It's a tie! Game over." << endl;
            break;
        }

        // Switch players one to next
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
