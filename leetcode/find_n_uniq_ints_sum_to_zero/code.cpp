#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> sumZero(int n) {
        std::vector<int> res;
        if(n % 2 != 0)
        {
            res.push_back(0);
            n--;
        }
        for(int i = n/2; i > 0; i--)
        {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};


int main()
{
    Solution sol;
    {
        int n = 5;
        std::vector<int> res = sol.sumZero(n);
        assert(std::accumulate(res.begin(), res.end(), 0) == 0);
    }
    {
        int n = 3;
        std::vector<int> res = sol.sumZero(n);
        assert(std::accumulate(res.begin(), res.end(), 0) == 0);
    }
    {
        int n = 1;
        std::vector<int> res = sol.sumZero(n);
        assert(std::accumulate(res.begin(), res.end(), 0) == 0);
    }
    return 0;
}