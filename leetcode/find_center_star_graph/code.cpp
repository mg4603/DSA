#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) 
    {
        int n = edges.size();
        std::vector<int> v(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            int temp1 = ++v[edges[i][0]-1];
            int temp2 = ++v[edges[i][1]-1];
            if(temp1 > 1)
            {
                return edges[i][0];
            }
            else if(temp2 > 1)
            {
                return edges[i][1];
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> edges = {
            {1,2},{2,3},{4,2}};
        int res = 2;
        assert(sol.findCenter(edges) == res);
    }
    {
        std::vector<std::vector<int>> edges = {
            {1,2},{5,1},{1,3},{1,4}};
        int res = 1;
        assert(sol.findCenter(edges) == res);
    }
    return 0;
}