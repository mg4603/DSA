#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countSeniors(std::vector<std::string>& details) {
        int res = 0;
        for(int i = 0; i < details.size(); i++)
        {
            int age = 10 * (details[i][11] - '0') + (details[i][12] - '0');
            if(age > 60)
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
        std::vector<std::string> details = {
                                    "7868190130M7522",
                                    "5303914400F9211",
                                    "9273338290F4010"};
        int res = 2;
        assert(sol.countSeniors(details) == res);
    }
    {
        std::vector<std::string> details = {
                                    "1313579440F2036",
                                    "2921522980M5644"};
        int res = 0;
        assert(sol.countSeniors(details) == res);
    }
    return 0;
}