#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) 
    {
        int res = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i].find('+') != std::string::npos)
            {
                res++;
            }
            else
            {
                res--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> operations = {"--X","X++","X++"};
        int res = 1;
        assert(sol.finalValueAfterOperations(operations) == res);
    }
    {
        std::vector<std::string> operations = {"++X","++X","X++"};
        int res = 3;
        assert(sol.finalValueAfterOperations(operations) == res);
    }
    {
        std::vector<std::string> operations = {"X++","++X","--X","X--"};
        int res = 0;
        assert(sol.finalValueAfterOperations(operations) == res);
    }
    return 0;
}