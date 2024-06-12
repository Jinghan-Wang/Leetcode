class Solution:
    def fib1(self, N: int) -> int:
        if N <= 1:
            return N
        dp = [0] * (N + 1)
        dp[0] = 0
        dp[1] = 1
        for i in range(2, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[N]
        
    def fib2(self, N: int) -> int:
        if N <= 1:
            return N
        a, b = 0, 1
        for _ in range(2, N + 1):
            a, b = b, a + b
        return b

def main():
    sol = Solution()
    N = int(input("Enter a number: "))
    result = sol.fib2(N)
    print(f"The {N}-th Fibonacci number is: {result}")

if __name__ == "__main__":
    main()
