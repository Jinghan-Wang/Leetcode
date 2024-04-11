#使用字典的方式进行解答
#map是一个迭代器 map(function, iterable);funtion是一个函数，iterable是一个可迭代对象
def twoSum(nums, target):
    num_map = {}
    for i, num in enumerate(nums):
      #遍历当前元素，并且在map中寻找是否有匹配的key
        tmp = target - num
        if tmp in num_map:
            return [num_map[tmp], i]
        num_map[num] = i #如果没找到匹配对，就把访问的元素和下标加入到map中

n = int(input())
nums = list(map(int, input().split()))
target = int(input())
result = twoSum(nums, target)
print(result)
