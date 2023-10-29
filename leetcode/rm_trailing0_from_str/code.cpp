#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeTrailingZeros(std::string num) 
    {
        int j = num.length() - 1;
        while(num[j] == '0')
        {
            j--;
        }
        num.resize(j + 1);
        return num;
    }
};

int main()
{
    Solution sol;
    {
        std::string num = "51230100";
        std::string res = "512301";
        assert(sol.removeTrailingZeros(num) == res);
    }
    {
        std::string num = "123";
        std::string res = "123";
        assert(sol.removeTrailingZeros(num) == res);
    }
    return 0;
}