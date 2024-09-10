#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void dfs(std::vector<std::vector<int>> &graph, 
            std::vector<std::vector<int>> &res, 
            std::vector<int> &path, int curr) {
        path.push_back(curr);
        if(curr == graph.size() - 1) {
            res.push_back(path);
        }else {
            for(int i = 0; i < graph[curr].size(); i++) {
                dfs(graph, res, path, graph[curr][i]);
            }
        }
        path.pop_back();
    }
public:
    std::vector<std::vector<int>> allPathsSourceTarget(
                        std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        dfs(graph, res, path, 0);
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> graph = {{1,2},{3},{3},{}};
        std::vector<std::vector<int>> res = {{0,1,3},{0,2,3}};
        assert(sol.allPathsSourceTarget(graph) == res);
    }
    return 0;
}