#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for(int i(0); i < s.size() / 2; i++)
        {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<char> vec = {'h','e','l','l','o'};
        std::vector<char> res = {'o','l','l','e','h'};
        sol.reverseString(vec);
        assert(vec == res);
    }
    {
        std::vector<char> vec = {'H','a','n','n','a','h'};
        std::vector<char> res = {'h','a','n','n','a','H'};
        sol.reverseString(vec);
        assert(vec == res);
    }
    return 0;
}