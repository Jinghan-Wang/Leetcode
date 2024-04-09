
class Solution:
    def solveNQueens(self, n):
        result = []
        grid = ['.' * n for _ in range(n)]
        self.backtracking(n, 0, grid, result)
        return result

    def backtracking(self, n, row, grid, result):
        if row == n:
            result.append(grid[:])
            return
        for col in range(n):
            if self.isVaild(row, col, grid):
                grid[row] = grid[row][:col] + 'Q' + grid[row][col+1:]
                self.backtracking(n, row + 1, grid, result)
                grid[row] = grid[row][:col] + '.' + grid[row][col+1:]

    def isVaild(self, row, col, grid):
        for i in range(row):
            if grid[i][col] == 'Q':
                return False
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if grid[i][j] == 'Q':
                return False
            i -= 1
            j -= 1
        
        i, j = row - 1, col + 1
        while i >= 0 and j < len(grid):
            if grid[i][j] == 'Q':
                return False
            i -= 1
            j += 1
        return True

if __name__ == '__main__':
    n = int(input())
    print(Solution().solveNQueens(n))

