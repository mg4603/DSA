#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool digitCount(std::string num) 
    {
        std::vector<int> freq(10, 0);
        for(int i = 0; i < num.length(); i++)
        {
            freq[num[i] - '0']++;
        }
        for(int i = 0; i < num.length(); i++)
        {
            if(freq[i] != num[i] - '0')
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string num = "1210";
        bool res = 1;
        assert(sol.digitCount(num) == res);
    }
    {
        std::string num = "030";
        bool res = 0;
        assert(sol.digitCount(num) == res);
    }
    return 0;
}