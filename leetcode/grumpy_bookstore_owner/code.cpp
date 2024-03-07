#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, 
                     std::vector<int>& grumpy, 
                     int minutes) 
    {
        int satisfied = 0;
        int maxMadeSatisfied = 0;
        int madeSatisfied = 0;
        int n = customers.size();

        for(int i = 0; i < n; i++)
        {
            if(!grumpy[i])satisfied += customers[i];
            else
            {
                madeSatisfied += customers[i];
            }
            if(i >= minutes)
            {
                madeSatisfied -= customers[i - minutes] * 
                                grumpy[i - minutes];
            }
            maxMadeSatisfied = std::max(maxMadeSatisfied, madeSatisfied);
        }
        return satisfied + maxMadeSatisfied;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> customers = {1,0,1,2,1,1,7,5};
        std::vector<int> grumpy = {0,1,0,1,0,1,0,1};
        int minutes = 3;
        int res = 16;
        assert(sol.maxSatisfied(customers, grumpy, minutes) == res);
    }
    return 0;
}