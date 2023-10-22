#include <iostream>
#include <assert.h>

class Solution {
public:
    bool squareIsWhite(std::string coordinates) {
        int x = coordinates[0] - 'a';
        int y = coordinates[1] - '1';
        return (x + y) % 2;
    }
};

int main()
{
    Solution sol;
    {
        std::string coordinates = "a1";
        bool res = false;
        assert(sol.squareIsWhite(coordinates) == res);
    }
    {
        std::string coordinates = "h3";
        bool res = true;
        assert(sol.squareIsWhite(coordinates) == res);
    }
    {
        std::string coordinates = "c7";
        bool res = false;
        assert(sol.squareIsWhite(coordinates) == res);
    }
    return 0;
}