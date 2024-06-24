#include <iostream>
#include <assert.h>

class Solution {
public:
    int minimumSwap(std::string s1, std::string s2) {
        int x_y = 0;
        int y_x = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] == 'x' && s2[i] == 'y')x_y++;
            if(s1[i] == 'y' && s2[i] == 'x')y_x++;
        }

        int res = x_y / 2;
        res += y_x / 2;
        x_y %= 2;
        y_x %= 2;
        if(x_y != y_x)return - 1;
        return res + (x_y == 1 ? 2: 0);
    }
};

int main()
{
    Solution sol;
    {
        std::string s1 = "xx";
        std::string s2 = "yy";
        int res = 1;
        assert(sol.minimumSwap(s1, s2) == res);
    }
    return 0;
}