class Solution:
    def combine(self, n, k):
        result = []
        self.backtracking(n, k, 1, [], result)
        return result
    def backtracking(self, n, k, startindex, path, result):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(startindex, n - (k - len(path)) + 2):
            path.append(i)
            self.backtracking(n, k, i + 1, path, result)
            path.pop()

if __name__ == '__main__':
    n = int(input())
    k = int(input())
    print(Solution().combine(n, k))

