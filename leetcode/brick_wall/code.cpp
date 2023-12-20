#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int leastBricks(std::vector<std::vector<int>>& wall) 
    {
        int n = wall.size();
        int untouched = 0;
        std::unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            int end = 0;
            for(int j = 0; j < wall[i].size() - 1; j++)
            {
                end += wall[i][j];
                int temp = ++mp[end];
                if(temp > untouched)
                {
                    untouched = temp;
                }
            }
        }    
        return n - untouched;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> wall = {{1,2,2,1},{3,1,2},
                                              {1,3,2},{2,4},
                                              {3,1,2},{1,3,1,1}};
        int res = 2;
        assert(sol.leastBricks(wall) == res);
    }
    {
        std::vector<std::vector<int>> wall = {{1},{1},{1}};
        int res = 3;
        assert(sol.leastBricks(wall) == res);
    }
    return 0;
}