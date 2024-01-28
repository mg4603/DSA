#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(n >= k + maxPts - 1)return 1.0;

        std::vector<double> p(k + maxPts);
        double single_elem_prob = 1.0 / maxPts;

        p[0] = 1.0;
        double prev = 0;
        for(int i = 1; i <= k; i++)
        {
            if(i - maxPts - 1 >= 0)
            {
                prev -= p[i - maxPts - 1];
            }
            prev += p[i-1];
            p[i] = prev * single_elem_prob;
        }
        
        double res = p[k];
        for(int i = k + 1; i <= n; i++)
        {
            if(i - maxPts - 1 >= 0)
            {
                prev -= p[i - maxPts - 1];
            }
            p[i] = prev * single_elem_prob;

            res += p[i];
        }   
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        int k = 1;
        int maxPts = 10;
        double res = 1.0;
        assert(sol.new21Game(n, k, maxPts) == res);
    }
    return 0;
}