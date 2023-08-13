#include <iostream>
#include <assert.h>

class Solution {
public:
    int romanToInt(std::string s) {
        int num(0);
        for(int i(0); i < s.length(); i++)
        {
            switch(s[i])
            {
                case 'M':
                    num += 1000;
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'C':
                    if(i + 1 < s.length() && (s[i + 1] == 'M' || s[i + 1] == 'D') )
                    {
                        num -= 100;
                    }
                    else
                    {
                        num += 100;
                    }
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'X':
                    if(i + 1 < s.length() && (s[i + 1] == 'L' || s[i + 1] == 'C') )
                    {
                        num -= 10;
                    }
                    else
                    {
                        num += 10;
                    }
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'I':
                    if(i + 1 < s.length() && (s[i + 1] == 'V' || s[i + 1] == 'X') )
                    {
                        num -= 1;
                    }
                    else
                    {
                        num += 1;
                    }
                    break;
            }
        }
        return num;
    }
};

int main()
{
    Solution sol;

    assert(sol.romanToInt("III") == 3);
    assert(sol.romanToInt("LVIII") == 58);
    assert(sol.romanToInt("MCMXCIV") == 1994);
    return 0;
}