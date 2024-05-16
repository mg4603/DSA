#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        std::string res; std::string stack;
        for(int i = 0; i <= pattern.size(); i++) {
            stack.push_back(i + '1');
            while(!stack.empty() && (i == pattern.length() 
                    || pattern[i] == 'I')){
                res.push_back(stack.back());
                stack.pop_back();
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string pattern = "IIIDIDDD";
        std::string res = "123549876";
        assert(sol.smallestNumber(pattern) == res);
    }
    return 0;
}