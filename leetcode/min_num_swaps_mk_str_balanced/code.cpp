#include <iostream>
#include <assert.h>

class Solution {
public:
    int minSwaps(std::string s) {
        int hanging_open = 0;
        for(char &c: s) {
            if(c == '[') {
                hanging_open++;
            } else {
                if(hanging_open > 0) hanging_open--;
            }
        }
        return (hanging_open + 1) / 2;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "][][";
        int res = 1;
        assert(sol.minSwaps(s) == res);
    }
    return 0;
}