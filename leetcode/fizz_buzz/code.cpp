#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> res;
        for(int i(1); i <= n; i++)
        {
            if(i % 15 == 0)
            {
                res.push_back("FizzBuzz");
            }
            else if(i % 3 == 0)
            {
                res.push_back("Fizz");
            }
            else if(i % 5 == 0)
            {
                res.push_back("Buzz");
            }
            else
            {
                res.push_back(std::to_string(i));
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.fizzBuzz(3) == std::vector<std::string>({
            "1","2","Fizz"
        }));
    }
    {
        assert(sol.fizzBuzz(5) == std::vector<std::string>({
            "1","2","Fizz","4","Buzz"
        }));
    }
    {
        assert(sol.fizzBuzz(15) == std::vector<std::string>({
            "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz",
            "11","Fizz","13","14","FizzBuzz"
        }));
    }
    return 0;
}