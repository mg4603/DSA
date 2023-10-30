#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    std::string categorizeBox(int length, int width, int height, int mass) 
    {
        int bulky = 0;
        int heavy = (mass >= 100);

        length = std::log10(length) + 1;
        width = std::log10(width) + 1;
        height = std::log10(height) + 1;

        if(length >= 5 || width >= 5 ||
           height >= 5 || length + width + height >= 11)
        {
            bulky = 1;
        }
        if(bulky && heavy)
        {
            return "Both";
        }
        else if(bulky)
        {
            return "Bulky";
        }
        else if(heavy)
        {
            return "Heavy";
        }
        else
        {
            return "Neither";
        }

    }
};

int main()
{
    Solution sol;
    {
        int length = 1000;
        int width = 35;
        int height = 700;
        int mass = 300;
        std::string res = "Heavy";
        assert(sol.categorizeBox(length, width, height, mass) == res);
    }
    {
        int length = 200;
        int width = 50;
        int height = 800;
        int mass = 50;
        std::string res = "Neither";
        assert(sol.categorizeBox(length, width, height, mass) == res);
    }
    return 0;
}