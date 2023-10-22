#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) 
    {
        int n = code.size();
        std::vector<int> res(n, 0);
        if(k == 0)
        {
            return res;
        }
        else if(k > 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(k + i >= n)
                {
                    res[i] = std::accumulate(code.begin() + i + 1, 
                                        code.end(), 0);
                    res[i] += std::accumulate(code.begin(), 
                                        code.begin() + (k + i + 1) % n, 0);
                }
                else
                {
                    res[i] = std::accumulate(code.begin() + i + 1, 
                                        code.begin() + i + k + 1, 0);

                }
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(k + i < 0)
                {
                    res[i] = std::accumulate(code.begin(), 
                                        code.begin() + i, 0);
                    res[i] += std::accumulate(code.end() + (k + i), 
                                        code.end(), 0);
                }
                else
                {
                    res[i] = std::accumulate(code.begin() + i + k, 
                                        code.begin() + i, 0);

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
        std::vector<int> code = {5,7,1,4};
        int k = 3;
        std::vector<int> res = {12,10,16,13};
        assert(sol.decrypt(code, k) == res);
    }
    {
        std::vector<int> code = {1,2,3,4};
        int k = 0;
        std::vector<int> res = {0,0,0,0};
        assert(sol.decrypt(code, k) == res);
    }
    {
        std::vector<int> code = {2,4,9,3};
        int k = -2;
        std::vector<int> res = {12,5,6,13};
        assert(sol.decrypt(code, k) == res);
    }
    return 0;
}