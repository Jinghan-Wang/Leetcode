/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
};


void printVector(const std::vector<int>& nums, int newSize) {
    for (int i = 0; i < newSize; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    
    int newSize = solution.removeElement(nums, val);
    
    std::cout << "New size of the array: " << newSize << std::endl;
    std::cout << "Modified array: ";
    printVector(nums, newSize);
    
    return 0;
}
