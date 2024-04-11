#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i <= n; i++) {
        // for (int i = startindex; i <= n - (k - path.size()) + 1; i++){    //优化该代码,优化的地方
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k){
        backtracking(n, k, 1);
        return result;
    }
};


int main(){
    Solution solution;
    int n;
    int k;
    cin >> n;
    cin >> k;
    vector<vector<int>> result = solution.combine(n, k);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

}
