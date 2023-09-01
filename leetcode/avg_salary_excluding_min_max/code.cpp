#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    double average(std::vector<int>& salary) {
        std::sort(salary.begin(), salary.end());
        double avg(0);
        for(int i(1); i < salary.size() - 1; i++)
        {
            avg += salary[i];
        }
        return avg / static_cast<double>(salary.size() - 2);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> salary = {4000,3000,1000,2000};
        assert(sol.average(salary) == 2500.00000);
    }
    {
        std::vector<int> salary = {1000,2000,3000};
        assert(sol.average(salary) == 2000.00000);
    }
    return 0;
}