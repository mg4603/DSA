#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        
        for(int i = 1; i < triangle.size(); i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if(j < triangle[i].size() - 1)
                {
                    triangle[i][j] += std::min(triangle[i - 1][j - 1],
                                               triangle[i - 1][j]);
                }
                else
                {
                    triangle[i][j] += triangle[i-1][j-1];
                }
            }
        }

        return *min_element(triangle.back().begin(), 
                            triangle.back().end());
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> triangle = {{2},{3,4},
                                                  {6,5,7},
                                                  {4,1,8,3}};
        int res = 11;
        assert(sol.minimumTotal(triangle) == res);
    }
    {
        std::vector<std::vector<int>> triangle = {{-10}};
        int res = -10;
        assert(sol.minimumTotal(triangle) == res);
    }
    return 0;
}