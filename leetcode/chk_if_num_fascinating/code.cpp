#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isFascinating(int n) {
        std::string temp = std::to_string(n);
        temp += std::to_string(2 * n);
        temp += std::to_string(3 * n);

        std::vector<int> digits(10, 0);
        int temp_len = temp.length();

        if(temp_len > 9)
        {
            return false;
        }
        for(int i = 1; i < temp_len; i++)
        {
            int freq = ++digits[temp[i] - '0'];
            if(freq != 1)
            {
                return false;
            }
            if(temp[i] == '0')
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
        int n = 192;
        bool res = true;
        assert(sol.isFascinating(n) == res);
    }
    {
        int n = 100;
        bool res = false;
        assert(sol.isFascinating(n) == res);
    }
    return 0;
}