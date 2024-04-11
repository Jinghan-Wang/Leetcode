#include <iostream>
#include <vector>
using namespace std;

#define N 9

bool isVaild(vector<vector<char>>& board, int row, int col, char num) {
    // 检查行
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    //检查列
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    //检查3*3的格子
    int startrow = row - row % 3;
    int startcol = col - col % 3;
    for (int i = 0; i< 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startrow][j + startcol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isVaild(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSudoku(vector<vector<char>>& board) {
    for (int i= 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (solveSudoku(board)) {
        cout << "数独已解决：" << endl;
        printSudoku(board);
    } else {
        cout << "无解" << endl;
    }

    return 0;
}
