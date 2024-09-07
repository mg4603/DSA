#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    double averageWaitingTime(
                std::vector<std::vector<int>>& customers) {
        std::ios::sync_with_stdio(0);
        int start = 0;
        double wait = 0.0;
        for(int i = 0; i < customers.size(); i++) {
            if(i > 0) {
                if(customers[i][0] < start) {
                    wait += start - customers[i][0];
                }
            }
            wait += customers[i][1];
            start = std::max(start, customers[i][0] ) + 
                        customers[i][1];
        }
        return wait / customers.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> customers = {{1,2},{2,5},{4,3}};
        double res = 5.00000;
        assert(sol.averageWaitingTime(customers) == res);
    }
    return 0;
}