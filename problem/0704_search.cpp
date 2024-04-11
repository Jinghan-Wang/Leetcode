#include<iostream>
#include<vector>
using namespace std;

int serch(vector<int> nums, int target) {
    int l = 0; 
    int r = nums.size();
    while (l < r) {
        int mid = l + ((r - l) / 2);
        if (nums[mid] > target) {
            r = mid;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}
#ACM输入
int main() {
    int n;
    vector<int> nums;
    int target;
    cin >> n;
    nums.resize(n);
    for (int i = 0;i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;
    int result = serch(nums, target);
    cout << result;

}

