#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) 
    {
        std::ios_base::sync_with_stdio(0);

        int res = 0;
        for(int i = 0; i < hours.size(); i++)
        {
            if(hours[i] >= target)
            {
                res++;
            }
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> hours = {0,1,2,3,4};
        int target = 2;
        int res = 3;
        assert(sol.numberOfEmployeesWhoMetTarget(hours, target) == res);
    }
    {
        std::vector<int> hours = {5,1,4,2,2};
        int target = 6;
        int res = 0;
        assert(sol.numberOfEmployeesWhoMetTarget(hours, target) == res);
    }
    return 0;
}