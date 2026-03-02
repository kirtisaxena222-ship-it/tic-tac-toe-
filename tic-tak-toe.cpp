#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

int main() {
    int choice;
    char currentPlayer = 'X';
    int moves = 0;

    while(true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        if(checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " Wins! 🎉\n";
            break;
        }

        if(moves == 9) {
            displayBoard();
            cout << "It's a Draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
