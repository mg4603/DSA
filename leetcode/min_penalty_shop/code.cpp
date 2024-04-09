#include <iostream>
#include <assert.h>

#include <numeric>

class Solution {
public:
    int bestClosingTime(std::string customers) {
        std::ios::sync_with_stdio(0);
        int n = customers.length();
        int res = 0;

        int points = std::accumulate(customers.begin(), customers.end(), 
                            0, [](int a, char ch){ return a + (ch == 'Y');});

        int min_penalty = points;
        for(int i = 0; i < n; i++)
        {
            if(customers[i] == 'Y')points--;
            else points++;

            if(points < min_penalty)
            {
                min_penalty = points;
                res = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string customers = "YYNY";
        int res = 2;
        assert(sol.bestClosingTime(customers) == res);
    }
    return 0;
}