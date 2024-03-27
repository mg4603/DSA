#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    long long mod = 1000000007;
public:
    std::vector<int> productQueries(int n, 
                std::vector<std::vector<int>>& queries) {

        std::vector<int> pows;
        for(int i = 0; i < 32; i++)
        {
            if(n & (1 << i))
            {
                pows.push_back(1 << i);
            }
            
        }

        int m = queries.size();
        std::vector<int> res(m, 1);
        for(int i = 0; i < m; i++)
        {
            for(int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                res[i] = ((res[i] % mod) * (pows[j] % mod)) % mod;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 15;
        std::vector<std::vector<int>> queries = {{0,1},{2,2},{0,3}};
        std::vector<int> res = {2,4,64};
        assert(sol.productQueries(n, queries) == res);
    }
    return 0;
}