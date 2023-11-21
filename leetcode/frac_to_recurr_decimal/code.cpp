#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    std::string fractionToDecimal(int n, int d) 
    {
        if(n == 0)
        {
            return "0";
        }
        long a = std::abs(n);
        long b = std::abs(d);

        std::string res;

        if((n < 0) ^ (d < 0))
        {
            res += "-";
        }

        res += std::to_string(a / b);

        long r = a % b;
        if(r == 0)return res;
        res += ".";

        std::unordered_map<int, int> mp;

        mp[r] = res.length();

        while(r != 0)
        {
            r *= 10;
            res += std::to_string(r / b);
            r %= b;

            if(mp.find(r) != mp.end())
            {
                res.insert(res.begin() + mp[r], '(');
                res += ')';
                return res;
            }
            mp[r] = res.length();
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int numerator = 1;
        int denominator = 2;
        std::string res = "0.5";
        assert(sol.fractionToDecimal(numerator, denominator) == res);
    }
    {
        int numerator = 2;
        int denominator = 1;
        std::string res = "2";
        assert(sol.fractionToDecimal(numerator, denominator) == res);
    }
    {
        int numerator = 4;
        int denominator = 333;
        std::string res = "0.(012)";
        assert(sol.fractionToDecimal(numerator, denominator) == res);
    }
    return 0;
}