#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string res;

        int thousands = num / 1000;
        if(thousands > 0)
        {
            res += std::string(thousands, 'M');
        }

        num %= 1000;

        int hundreds = num / 100;

        switch(hundreds)
        {
            case 1:
            case 2:
            case 3:
                res += std::string(hundreds, 'C');
                break;
            case 4:
                res += "CD";
                break;
            case 5:
                res += 'D';
                break;
            case 6:
            case 7:
            case 8:
                res += 'D';
                res += std::string(hundreds - 5, 'C');
                break;
            case 9:
                res += "CM";
                break;
        }

        num %= 100;

        int tens = num / 10;

        switch(tens)
        {
            case 1:
            case 2:
            case 3:
                res += std::string(tens, 'X');
                break;
            case 4:
                res += "XL";
                break;
            case 5:
                res += 'L';
                break;
            case 6:
            case 7:
            case 8:
                res += 'L';
                res += std::string(tens - 5, 'X');
                break;
            case 9:
                res += "XC";
                break;
        }

        num %= 10;

        switch(num)
        {
            case 1:
            case 2:
            case 3:
                res += std::string(num, 'I');
                break;
            case 4:
                res += "IV";
                break;
            case 5:
                res += 'V';
                break;
            case 6:
            case 7:
            case 8:
                res += 'V';
                res += std::string(num - 5, 'I');
                break;
            case 9:
                res += "IX";
                break;
        }


        return res;
    }
};

int main()
{
    Solution sol;
    {
        int num = 3;
        std::string res = "III";
        assert(sol.intToRoman(num) == res);
    }
    {
        int num = 58;
        std::string res = "LVIII";
        assert(sol.intToRoman(num) == res);
    }
    {
        int num = 1994;
        std::string res = "MCMXCIV";
        assert(sol.intToRoman(num) == res);
    }
    return 0;
}