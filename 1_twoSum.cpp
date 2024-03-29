
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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


