
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// unordered_map是C++标准中的哈希表实现的关联容器，用于存储键值对
// unordered_map是常见操作，插入元素 'insert(key, value)','emplace(key, value)',删除元素'erase(key)',查找元素'find(key)'

vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> numsmap;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numsmap.find(complement) != numsmap.end()) {
            result.push_back(numsmap[complement]);
            result.push_back(i);
            break;
        }
        numsmap[nums[i]] = i;
    }
    return result;
}

int main() {
    int n;
    vector<int> nums;
    int target;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cin >> target;
    vector<int> result = twoSum(nums, target);
    if (result.size() == 2) {
        cout << "output: {" << result[0] << " " << result[1] << "}" << endl; 
    }
    else {
        cout << "No vaild result found" << endl;
    }

    return 0;
}


