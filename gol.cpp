#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

class Gol {
public:
    void initBoard(vector<vector<char>> &b) {
        for (int i = 0; i <= 10; ++i) {
            vector<char> row;
            b.push_back(row);
        }
        for (int i = 0; i <= 10; ++i) {
            for (int j = 0; j <= 10; ++j) {
                b[i].push_back(' ');
            }
        }

        b[4][6] = '*';
        b[5][4] = '*';
        b[5][6] = '*';
        b[6][6] = '*';
        b[4][5] = '*';
        b[4][4] = '*';

    }

 void drawBoard(vector<vector<char>> &board) {
        for (vector<char> row : board) {
            for (char c : row) {
                cout << c << "    ";
            }
            cout << "\n";
        }
}

    int checkNeighbors(vector<vector<char>> &board, int i, int j, int max) {
        int neighbors = 0;
        if (i+1 <= max) {
            if (board[i+1][j] == '*') {
                neighbors++;
            }
        }
        if (j+1 <= max) {
            if (board[i][j+1] == '*') {
                neighbors++;
            }
        }
        if (i-1 >= 0) {
            if (board[i-1][j] == '*') {
                neighbors++;
            }
        }
        if (j-1 >= 0) {
            if (board[i][j-1] == '*') {
                neighbors++;
            }
        }
        if (i-1 >= 0 && j-1 >= 0) {
            if (board[i-1][j-1] == '*') {
                neighbors++;
            }
        }
        if (i+1 <= max && j+1 <= max) {
            if (board[i+1][j+1] == '*') {
                neighbors++;
            }
        }
        if (i-1 >= 0 && j+1 <= max) {
            if (board[i-1][j+1] == '*') {
                neighbors++;
            }
        }
        if (i+1 <= max && j-1 >= 0) {
            if (board[i+1][j-1] == '*') {
                neighbors++;
            }
        }

        return neighbors;
    }

    void update(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int neighbors = checkNeighbors(board, i, j, 9);
                if (board[i][j] == '*') {
                    if (neighbors < 2) {
                        board[i][j] = ' ';
                    }
                    if (neighbors > 3) {
                        board[i][j] = ' ';
                    }
                } else if (board[i][j] == ' ') {
                    if (neighbors == 3) {
                        board[i][j] = '*';
                    }
                }
            }
        }
     }
};

int main() {
    vector<vector<char>> board;
    Gol game;
    game.initBoard(board);
    while (true) {
        game.drawBoard(board);
        game.update(board);
        sleep(1);
    }

    return 0;
}
