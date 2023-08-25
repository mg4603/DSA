#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int i(a.size() - 1), j(b.size() - 1);
        std::string res;
        int carry(0);
        while(i >= 0 && j >= 0)
        {
            int temp1(a[i--] - '0');
            int temp2(b[j--] - '0');
            int temp3 = temp1 + temp2 + carry;
            carry = temp3 / 2;
            res = std::to_string(temp3 % 2) + res;
        }
        while(i >= 0)
        {
            int temp(a[i--] - '0');
            temp += carry;
            carry = temp / 2;
            res = std::to_string(temp % 2) + res;
        }
        while(j >= 0)
        {
            int temp(b[j--] - '0');
            temp += carry;
            carry = temp / 2;
            res = std::to_string(temp % 2) + res;
        }
        if(carry > 0)
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
        assert(sol.addBinary("11", "1") == "100");
        assert(sol.addBinary("1010", "1011") == "10101");
    }
    return 0;
}