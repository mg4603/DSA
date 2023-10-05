#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        std::ios_base::sync_with_stdio(0);
        int res(0);
        for(int j = 0; j < strs[0].length(); j++)
        {
            for(int i = 1; i < strs.size(); i++)
            {
                if(strs[i - 1][j] > strs[i][j])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> strs = {"cba","daf","ghi"};
        int output = 1;
        assert(sol.minDeletionSize(strs) == output);
    }
    {
        std::vector<std::string> strs = {
            "a","b"
        };
        int output = 0;
        assert(sol.minDeletionSize(strs) == output);
    }
    {
        std::vector<std::string> strs = {
            "zyx","wvu","tsr"
        };
        int output = 3;
        assert(sol.minDeletionSize(strs) == output);
    }
    return 0;
}