#include <iostream>
#include <assert.h>

#include <vector>
class Solution {
public:
    std::vector<int> grayCode(int n) 
    {
        n = 1 << n;
        std::vector<int> res(n);

        for(int i = 0; i < n; i++)
        {
            res[i] = (i ^ (i>>1));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        std::vector<int> res = {0,1,3,2};
        assert(sol.grayCode(n) == res);
    }
    {
        int n = 1;
        std::vector<int> res = {0,1};
        assert(sol.grayCode(n) == res);
    }
    return 0;
}