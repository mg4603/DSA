#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, 
                                        int n) 
    {
        std::vector<std::string> res;
        int cnt = 0;
        for(int i = 1; i <= target.back(); i++)
        {
            if(target[cnt] == i)
            {
                res.push_back("Push");
                cnt++;
            }
            else
            {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> target = {1,3};
        int n = 3;
        std::vector<std::string> res = {"Push","Push","Pop","Push"};
        assert(sol.buildArray(target, n) == res);
    }
    {
        std::vector<int> target = {1,2,3};
        int n = 3;
        std::vector<std::string> res = {"Push","Push","Push"};
        assert(sol.buildArray(target, n) == res);
    }
    {
        std::vector<int> target = {1,2};
        int n = 4;
        std::vector<std::string> res = {"Push","Push"};
        assert(sol.buildArray(target, n) == res);
    }
    return 0;
}