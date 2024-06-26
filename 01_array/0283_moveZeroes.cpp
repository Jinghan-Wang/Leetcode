/*
283
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。


示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
 

提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
进阶：你能尽量减少完成的操作次数吗？
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 双指针写法
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,0,2,0,3};
    solution.moveZeroes(nums);
    for (int num : nums) {
        cout << num << endl;
    }
    return 0;
}



