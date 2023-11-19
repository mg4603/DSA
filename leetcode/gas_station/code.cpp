#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, 
                           std::vector<int>& cost) 
    {
        int n = cost.size();
        
        int total_gas = 0;
        int total_cost = 0;

        int res = 0;

        int curr_gas = 0;

        for(int i = 0; i < n; i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];

            curr_gas += gas[i] - cost[i];
            if(curr_gas < 0)
            {
                res = i + 1;
                curr_gas = 0;
            }
        }

        return (total_gas < total_cost) ? -1 : res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> gas = {1,2,3,4,5};
        std::vector<int> cost = {3,4,5,1,2};
        int res = 3;
        assert(sol.canCompleteCircuit(gas, cost) == res);
    }
    {
        std::vector<int> gas = {2,3,4};
        std::vector<int> cost = {3,4,3};
        int res = -1;
        assert(sol.canCompleteCircuit(gas, cost) == res);
    }
    return 0;
}