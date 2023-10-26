#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::string> cellsInRange(std::string s) 
    {
        int col_start = s[0];
        int col_end = s[3];

        int row_start = s[1];
        int row_end = s[4];

        std::vector<std::string> res;

        for(int i = col_start; i <= col_end; i++)
        {
            for(int j = row_start; j <= row_end; j++)
            {
                std::string temp;
                temp += i;
                temp += j;
                res.push_back(temp);
            }
        }        
        return res;

    }
};

int main()
{
    Solution sol;
    {
        std::string s = "K1:L2";
        std::vector<std::string> res = {"K1","K2","L1","L2"};
        assert(sol.cellsInRange(s) == res);
    }
    {
        std::string s = "A1:F1";
        std::vector<std::string> res = {"A1","B1","C1","D1","E1","F1"};
        assert(sol.cellsInRange(s) == res);
    }
    return 0;
}