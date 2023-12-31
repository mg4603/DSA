#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    int lcm(int a, int b)
    {
        return (a * b) / gcd(a, b);
    }
public:
    std::string fractionAddition(std::string s) 
    {
        std::vector<std::vector<int>> fracs;
        std::string symbols = "+-";

        while(s.length())
        {
            int a = std::stoi(s);
            int pos = s.find('/');
            if(pos == std::string::npos)
            {
                fracs.push_back({a, 1});
                break;
            }
            s = s.substr(pos + 1);

            int b = std::stoi(s);
            pos = s.find_first_of(symbols);
            fracs.push_back({a, b});

            if(pos == std::string::npos)break;
            s = s.substr(pos);
        }

        int denominator = 1;
        for(std::vector<int> frac: fracs)
        {
            denominator = lcm(denominator, frac[1]);
        }

        int numerator = 0;

        for(std::vector<int> frac: fracs)
        {
            int mul = denominator / frac[1];
            mul = std::abs(mul);
            numerator += (mul * frac[0]);
        }

        int red = gcd(numerator, denominator);
        red = std::abs(red);
        numerator /= red;
        denominator /= red;

        if(numerator == 0)
        {
            denominator = 1;
        }
        std::string res;
        res = std::to_string(numerator) + "/" + std::to_string(denominator);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string expression = "-1/2+1/2";
        std::string res = "0/1";
        assert(sol.fractionAddition(expression) == res);
    }
    {
        std::string expression = "-1/2+1/2+1/3";
        std::string res = "1/3";
        assert(sol.fractionAddition(expression) == res);
    }
    {
        std::string expression = "1/3-1/2";
        std::string res = "-1/6";
        assert(sol.fractionAddition(expression) == res);
    }
    return 0;
}