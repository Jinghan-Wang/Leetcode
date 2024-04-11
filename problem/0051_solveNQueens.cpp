#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
private:
    vector<vector<string>> result;
    void dfs(int n, int row, vector<string>& grid) {
        if (row == n) {
            result.push_back(grid);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isVaild(row, col, grid, n)) {
                grid[row][col] = 'Q';
                dfs(n, row + 1, grid);
                grid[row][col] = '.';
            }
        }
    }

    bool isVaild(int row, int col, vector<string>& grid, int n) {
        for (int i = 0; i < n; i++) {
            if (grid[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }
        return true;

    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        dfs(n, 0, grid);
        return result;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<vector<string>> result = solution.solveNQueens(n);
    for (const auto& row : result) {
        cout << "{" ;
        for (string col : row){
            cout << col << " ";
        }
        cout << "}";
        cout << endl;
    }
}
