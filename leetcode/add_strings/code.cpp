#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int i(num1.size() - 1);
        int j(num2.size() - 1);
        int carry(0);
        std::string res;

        while(i >= 0 && j >= 0)
        {
            int temp ((num1[i--] - '0') + (num2[j--] - '0') + carry);
            carry = temp / 10;
            temp %= 10;
            res = std::to_string(temp) + res;
        }

        while(i >= 0)
        {
            int temp ((num1[i--] - '0') + carry);
            carry = temp / 10;
            temp %= 10;
            res = std::to_string(temp) + res;
        }

        while(j >= 0)
        {
            int temp ((num2[j--] - '0') + carry);
            carry = temp / 10;
            temp %= 10;
            res = std::to_string(temp) + res;
        }

        if(carry)
        {
            res = std::to_string(carry) + res;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.addStrings("11", "123") == "134");
        assert(sol.addStrings("456", "77") == "533");
        assert(sol.addStrings("0", "0") == "0");
    }
    return 0;
}