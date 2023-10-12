#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
    bool isLeap(int year)
    {
        if(year % 100 == 0)
        {
            return year % 400 == 0;
        }
        return year % 4 == 0;
    }
public:
    int dayOfYear(std::string date) {
        std::ios_base::sync_with_stdio(0);
        int year = std::stoi(date);
        int month = std::stoi(date.substr(5));
        int day = std::stoi(date.substr(8));

        std::vector<int> days_in_month{
            0, 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int res = std::accumulate(days_in_month.begin(), days_in_month.begin() + month, 0);
        res += day;

        if(isLeap(year) && month > 2)
        {
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string date = "2019-01-09";
        int res = 9;
        assert(sol.dayOfYear(date) == res);
    }
    {
        std::string date = "2019-02-10";
        int res = 41;
        assert(sol.dayOfYear(date) == res);
    }
    return 0;
}