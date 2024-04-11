def search(nums, target):
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if nums[mid] < target:
            l = mid + 1
        elif nums[mid] > target:
            r = mid - 1
        else:
            return mid
    return -1


#n = int(input())
nums = list(map(int, input().split()))

target = int(input())
result = search(nums, target)
print(result)
