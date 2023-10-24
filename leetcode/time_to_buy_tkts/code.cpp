#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) 
    {
        int res = 0;

        if(tickets[k] > 1)
        {
            for(int i = 0; i < tickets.size(); i++)
            {
                res += std::min(tickets[i], tickets[k] - 1);
            }
        }
        
        for(int i = 0; i <= k; i++)
        {
            if(tickets[i] >= tickets[k])
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
        std::vector<int> tickets = {2,3,2};
        int k = 2;
        int res = 6;
        assert(sol.timeRequiredToBuy(tickets, k) == res);
    }
    {
        std::vector<int> tickets = {5,1,1,1};
        int k = 0;
        int res = 8;
        assert(sol.timeRequiredToBuy(tickets, k) == res);
    }
    return 0;
}