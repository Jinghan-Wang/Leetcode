class Solution:
    def moveZeroes(self, nums):
        n = len(nums)
        left = 0
        right = 0
        while right < n:
            if nums[right]:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1

if __name__ == "__main__":
    solution = Solution()
    nums = [1, 0, 2, 0, 3]
    solution.moveZeroes(nums)
    for num in nums:
        print(num)
