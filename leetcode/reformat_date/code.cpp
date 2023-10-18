#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    std::string reformatDate(std::string date) {
        int day = std::stoi(date);

        int pos = date.find(' ');
        std::string month = date.substr(pos + 1, 3);

        pos = date.find(' ', pos + 1);
        int year = std::stoi(date.substr(pos + 1));

        std::string res = std::to_string(year);
        res += '-';

        std::unordered_map<std::string, std::string> mp = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"},
        };

        res += mp[month];
        res += '-';

        res += day < 10? "0" + std::to_string( day) : std::to_string(day);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string date = "20th Oct 2052";
        std::string res = "2052-10-20";
        assert(sol.reformatDate(date) == res);
    }
    {
        std::string date = "6th Jun 1933";
        std::string res = "1933-06-06";
        assert(sol.reformatDate(date) == res);
    }
    {
        std::string date = "26th May 1960";
        std::string res = "1960-05-26";
        assert(sol.reformatDate(date) == res);
    }
    return 0;
}