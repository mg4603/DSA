#include <iostream>
#include <assert.h>

class Solution {
public:
    int convertTime(std::string current, std::string correct) 
    {
        int current_hr = std::stoi(current);
        int correct_hr = std::stoi(correct);
        int current_min = std::stoi(current.substr(3));
        int correct_min = std::stoi(correct.substr(3));

        int res = std::abs(current_hr - correct_hr);
        int min_diff = correct_min - current_min;

        if(min_diff < 0)
        {
            res--;
            min_diff = 60 + min_diff;
        }

        res += (min_diff / 15);
        min_diff %= 15;


        res += (min_diff / 5);
        min_diff %= 5;


        res += min_diff;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string current = "02:30";
        std::string correct = "04:35";
        int res = 3;
        assert(sol.convertTime(current, correct) == res);
    }
    {
        std::string current = "11:00";
        std::string correct = "11:01";
        int res = 1;
        assert(sol.convertTime(current, correct) == res);
    }
    return 0;
}