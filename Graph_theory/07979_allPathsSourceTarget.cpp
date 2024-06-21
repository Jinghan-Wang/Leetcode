#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph, 0, graph.size() - 1, path, result);
        return result;
    }

private:
    void dfs(vector<vector<int>>& graph, int curr, int target, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(curr); // 将当前结点加入路径
        if (curr == target) {
            result.push_back(path); // 如果当前结点是终点，将路径加入结果
        }
        else {
            for (int next : graph[curr]) {
                dfs(graph, next, target, path, result); // 递归探索下一个结点
            }
        }
        path.pop_back(); // 回溯，移除当前结点，尝试其他路径
    }
};


// 测试函数
int main() {
    Solution sol;
    vector<vector<int>> graph1 = { {1,2},{3},{3},{} };
    vector<vector<int>> result1 = sol.allPathsSourceTarget(graph1);
    cout << "Graph 1 results:" << endl;
    for (auto path : result1) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    vector<vector<int>> graph2 = { {4,3,1},{3,2,4},{3},{4},{} };
    vector<vector<int>> result2 = sol.allPathsSourceTarget(graph2);
    cout << "Graph 2 results:" << endl;
    for (auto path : result2) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

