/*
给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。

示例 1：

输入：nums = [1,2,3]
输出：3
解释：
只需要3次操作（注意每次操作会增加两个元素的值）：
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
"""
*/
/*
数学的方法：因为只需要找出让数组所有元素相等的最小操作次数，
所以我们不需要考虑数组中各个元素的绝对大小，
即不需要真正算出数组中所有元素相等时的元素值，
只需要考虑数组中元素相对大小的变化即可。
因此，每次操作既可以理解为使n−1个元素增加1，也可以理解使1个元素减少1。显然，后者更利于我们的计算。
我们可以逐个累加每个元素与数组中元素最小值的差
假设最少需要k次，并最终n个数的最终值是target。关键参数min(nums)
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums) {
            result += num - minNum;
        }
        return result;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    int result = solution.minMoves(nums);
    cout << result << endl;
    return 0;
}



