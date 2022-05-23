// Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void drawBoard(vector<vector<char>> board) {
    cout << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "   |   |   " << endl;
    cout << "-----------" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "   |   |   " << endl;
    cout << "-----------" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
    cout << endl;
}

bool isValidMove(vector<vector<char>> board, int x, int y) {
    if (board[x][y] == ' ') {
        return true;
    }
    else {
        return false;
    }
}

vector<vector<char>> makePlayerMove(vector<vector<char>> board) {
    int x, y;

    cout << "TYPE WHERE YOU WOULD LIKE TO PLACE AN X" << endl;
    do {
        cout << "Row(1-3): ";
        cin >> x;
        cout << "Column(1-3): ";
        cin >> y;

        x--;
        y--;

        if (!isValidMove(board, x, y)) {
            cout << "TRY AGAIN" << endl;
        }

    } while (!isValidMove(board, x, y));

    board[x][y] = 'X';

    return board;

}

vector<vector<char>> makeCompMove(vector<vector<char>> board) {
    int x, y;

    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (!isValidMove(board, x, y));

    board[x][y] = 'O';

    return board;
}

int gameOver(vector<vector<char>> board) {
    vector<int> columnsPers(3, 0), columnsComp(3, 0), rowsPers(3, 0), rowsComp(3, 0);
    vector<int> diagPers1(3, 0), diagComp1(3, 0), diagPers2(3, 0), diagComp2(3, 0);
    int winner = 0;
    int diagPers1Sum = 0;
    int diagPers2Sum = 0;
    int diagComp1Sum = 0;
    int diagComp2Sum = 0;
    int blanks = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                columnsPers[j]++;
                rowsPers[i]++;
                if ((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 2)) {
                    diagPers1[j]++;
                }
                if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) {
                    diagPers2[j]++;
                }
            }
            if (board[i][j] == 'O') {
                columnsComp[j]++;
                rowsComp[i]++;
                if ((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 2)) {
                    diagComp1[j]++;
                }
                if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) {
                    diagComp2[j]++;
                }
            }
            if (board[i][j] == ' ') {
                blanks++;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        if (columnsPers[k] == 3 || rowsPers[k] == 3) {
            winner = 1;
        }
        if (columnsComp[k] == 3 || rowsComp[k] == 3) {
            winner = 2;
        }
        diagPers1Sum += diagPers1[k];
        diagPers2Sum += diagPers2[k];
        diagComp1Sum += diagComp1[k];
        diagComp2Sum += diagComp2[k];
    }

    if (winner != 0) {
        return winner;
    }
    else if (diagPers1Sum == 3 || diagPers2Sum == 3) {
        winner = 1;
        return winner;
    }
    else if (diagComp1Sum == 3 || diagComp2Sum == 3) {
        winner = 2;
        return winner;
    }
    else if (blanks == 0) {
        winner = 3;
        return winner;
    }

    return winner;
}

int main()
{
    vector<vector<char>> board
    {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };
    bool done = false;

    cout << "WELCOME TO TIC TAC TOE" << endl;
    cout << "FIRST PLAYER TO GET 3 IN A ROW WINS!" << endl;

    drawBoard(board);

    do {
        cout << "YOUR TURN!!!" << endl;

        board = makePlayerMove(board);

        if (gameOver(board) != 0) {
            drawBoard(board);
            break;
        }

        cout << "GREAT JOB!!! COMPUTERS TURN!!!" << endl;

        board = makeCompMove(board);

        drawBoard(board);
    } while (gameOver(board) == 0);

    cout << "GAME OVER" << endl;

    int winner = gameOver(board);

    if (winner == 1) {
        cout << "YOU WIN!" << endl;
    }
    else if (winner == 2) {
        cout << "COMPUTER WINS!" << endl;
    }
    else if (winner == 3) {
        cout << "IT'S A TIE!" << endl;
    }

    return 0;
}

// Functions to add:
 /*void drawBoard(vector<vector<char>> board)
 vector<vector<char>> makePlayerMove(vector<vector<char>> board)
 vector<vector<char>> makeCompMove(vector<vector<char>> board)
 bool isValidMove(vector<vector<char>> board, int x, int y)
 int gameOver(vector<vector<char>> board)*/
//