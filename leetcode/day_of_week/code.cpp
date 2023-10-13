#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string dayOfTheWeek(int day, int month, int year) {
        

        std::vector<int> t{ 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 }; 
        year -= month < 3;

        int day_of_week = 
                        (year + year / 4 - year / 100 + year / 400 + 
                            t[month - 1] + day) % 7;
        std::vector<std::string> res {"Sunday", "Monday", 
                        "Tuesday", "Wednesday", "Thursday", 
                        "Friday", "Saturday"};
        return res[day_of_week];
    }
};

int main()
{
    Solution sol;
    {
        int day = 31;
        int month = 8;
        int year = 2019;
        std::string res = "Saturday";
        assert(sol.dayOfTheWeek(day, month, year) == res);
    }
    {
        int day = 18;
        int month = 7;
        int year = 1999;
        std::string res = "Sunday";
        assert(sol.dayOfTheWeek(day, month, year) == res);
    }
    {
        int day = 15;
        int month = 8;
        int year = 1993;
        std::string res = "Sunday";
        assert(sol.dayOfTheWeek(day, month, year) == res);
    }
    return 0;
}