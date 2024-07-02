'''
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20
'''

class Solution:
    def generateMatrix(self, n: int):
        res = [[0] * n for _ in range(n)]  # Define a 2D array using list comprehension
        startx, starty = 0, 0  # Define the starting position for each loop
        loop = n // 2  # Number of loops, e.g., if n is odd (3), loop = 1, only one loop, the middle value needs to be handled separately
        mid = n // 2  # The middle position of the matrix, e.g., if n is 3, the middle position is (1, 1), if n is 5, the middle position is (2, 2)
        count = 1  # Used to assign values to each empty slot in the matrix
        offset = 1  # Controls the length of each side's traversal, each loop the right boundary shrinks by one

        while loop:
            i, j = startx, starty

            # Simulate the four steps of a loop
            # Fill the top row from left to right (left-closed, right-open)
            for j in range(starty, n - offset):
                res[i][j] = count
                count += 1

            # Fill the right column from top to bottom (left-closed, right-open)
            for i in range(startx, n - offset):
                res[i][j] = count
                count += 1

            # Fill the bottom row from right to left (left-closed, right-open)
            for j in range(n - offset, starty, -1):
                res[i][j] = count
                count += 1

            # Fill the left column from bottom to top (left-closed, right-open)
            for i in range(n - offset, startx, -1):
                res[i][j] = count
                count += 1

            # Move to the next loop's starting position
            startx += 1
            starty += 1
            offset += 1
            loop -= 1

        # If n is odd, handle the middle value separately
        if n % 2:
            res[mid][mid] = count

        return res


# Testing the Solution
if __name__ == "__main__":
    n = 3
    solution = Solution()
    matrix = solution.generateMatrix(n)
    for row in matrix:
        print(" ".join(map(str, row)))

