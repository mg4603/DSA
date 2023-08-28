#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if(numRows == 1)
        {
            return {{1}};
        }
        else if(numRows == 2)
        {
            return {{1}, {1, 1}};
        }
        std::vector<std::vector<int>> res = {{1}, {1, 1}};

        for(int i(2); i < numRows; i++)
        {
            std::vector<int> temp;
            temp.push_back(1);
            for(int j(0); j < res.back().size() - 1; j++)
            {
                temp.push_back(res.back()[j] + res.back()[j + 1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> res = 
                {{1}};
        assert(sol.generate(1) == res);
    }
    {
        std::vector<std::vector<int>> res = 
                {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
        assert(sol.generate(5) == res);
    }
    return 0;
}