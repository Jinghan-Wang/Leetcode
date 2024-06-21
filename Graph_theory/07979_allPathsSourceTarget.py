from typing import List

class Solution:
    def __init__(self):
        self.result = []
        self.path = []

    def dfs(self, graph: List[List[int]], x: int) -> None:
        if x == len(graph) - 1:
            self.result.append(self.path[:])  # 注意这里要复制一份path，否则会被后续的pop影响
            return
        for next_node in graph[x]:
            self.path.append(next_node)
            self.dfs(graph, next_node)
            self.path.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.path.append(0)
        self.dfs(graph, 0)
        return self.result

# 测试函数
def main():
    sol = Solution()

    # Example 1: graph = [[1,2],[3],[3],[]]
    graph1 = [[1,2],[3],[3],[]]
    result1 = sol.allPathsSourceTarget(graph1)
    print("Example 1:")
    for path in result1:
        print(path)

    # Example 2: graph = [[4,3,1],[3,2,4],[3],[4],[]]
    graph2 = [[4,3,1],[3,2,4],[3],[4],[]]
    result2 = sol.allPathsSourceTarget(graph2)
    print("\nExample 2:")
    for path in result2:
        print(path)

if __name__ == "__main__":
    main()
