#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, 
                        std::vector<std::vector<int>>& prerequisites) 
    {
        std::vector<int> indegree(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }    

        std::queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int visited = 0;
        std::vector<int> res;

        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            visited++;
            res.push_back(c);
            for(int i = 0; i < adj[c].size(); i++)
            {
                int neighbor = adj[c][i];
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
                
            }
        }

        if(visited == numCourses)
        {
            return res;
        }
        return {};
    }
};

int main()
{
    Solution sol;
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0}};
        std::vector<int> res = {0,1};
        assert(sol.findOrder(numCourses, prerequisites) == res);
    }
    {
        int numCourses = 4;
        std::vector<std::vector<int>> prerequisites = {
                                            {1,0},{2,0},{3,1},{3,2}};
        std::vector<int> res = {0,1,2,3};
        assert(sol.findOrder(numCourses, prerequisites) == res);
    }
    {
        int numCourses = 1;
        std::vector<std::vector<int>> prerequisites = {};
        std::vector<int> res = {0};
        assert(sol.findOrder(numCourses, prerequisites) == res);
    }
    return 0;
}