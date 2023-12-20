#include <iostream>
#include <assert.h>

class Solution {
    std::pair<int, int> parseComplex(std::string num)
    {
        
        int r = std::stoi(num);
        int c = std::stoi(num.substr(num.find('+') + 1));


        return std::make_pair(r, c);
    }
public:
    std::string complexNumberMultiply(std::string num1, 
                                      std::string num2) 
    {
        std::pair<int, int> first = parseComplex(num1);
        std::pair<int, int> second = parseComplex(num2);
        int r = first.first * second.first - 
                    first.second * second.second;

        int c = first.second * second.first + 
                    first.first * second.second;


        return std::to_string(r) + "+" + std::to_string(c) + "i";
    }
};

int main()
{
    Solution sol;
    {
        std::string num1 = "1+1i";
        std::string num2 = "1+1i";
        std::string res = "0+2i";
        assert(sol.complexNumberMultiply(num1, num2) 
                == res);
    }
    {
        std::string num1 = "1+-1i";
        std::string num2 = "1+-1i";
        std::string res = "0+-2i";
        assert(sol.complexNumberMultiply(num1, num2) 
                == res);
    }
    return 0;
}