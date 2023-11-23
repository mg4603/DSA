#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, 
                   std::vector<std::vector<int>>& prerequisites) 
    {
        std::vector<int> indegree(numCourses);
        std::vector<std::vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        std::queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int res = 0;
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            res++;
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
        return res == numCourses;
    }
};

int main()
{
    Solution sol;
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0}};
        bool res = true;
        assert(sol.canFinish(numCourses, prerequisites) == res);
    }
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}};
        bool res = false;
        assert(sol.canFinish(numCourses, prerequisites) == res);
    }
    return 0;
}