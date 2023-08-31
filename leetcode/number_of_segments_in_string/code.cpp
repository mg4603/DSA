#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    int countSegments(std::string s) {
        std::stringstream ss(s);
        int count(0);
        std::string temp;
        while(ss >> temp)
        {
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.countSegments("Hello, my name is John") == 5);
        assert(sol.countSegments("Hello") == 1);
    }
    return 0;
}