#include <iostream>
#include <assert.h>

#include <string>
#include <vector>
#include <cmath>
#include <map>

std::string getBitRep(unsigned char n)
{
    std::string res;
    while(n != 0)
    {
        res = std::to_string(n % 2) + res;
        n /= 2;
    }
    if(res.length() < 8)
    {
        res = std::string(8 - res.length(), '0') + res;
    }
    return res;
}

int bitStrToInt(std::string bitStr)
{
    int num(0);
    for(int i(bitStr.size() - 1); i >= 0; i--)
    {
        num += (pow(2, bitStr.size() - i - 1) * (bitStr[i] - '0'));
    }
    return num;
}

std::string bitLetter(const std::vector<unsigned char> n){
    std::string res;
    std::map<int, char> puncMp{
        {1, ' '}, {2, ','}, {3, '.'}
    };

    for(auto c: n)
    {
        std::string temp(getBitRep(c));
        int punc(bitStrToInt(temp.substr(0, 2)));
        int lCase(bitStrToInt(temp.substr(2, 1)));
        int idx(bitStrToInt(temp.substr(3)));
        if(punc == 1)
        {
            res += puncMp[punc];
        }

        char ch(idx + 'a');
        if(lCase == 1)
        {
            ch = toupper(ch);
        }
        res += ch;
        if(punc != 1 && punc != 0)
        {
            res += puncMp[punc];
        }
        
    }
    return res;
}

void testequal(std::string ans, std::string sol) 
{
    assert(ans == sol);
}

int main()
{
    testequal(bitLetter({ 39,4,11,11,142,86,14,17,11,195 }),"Hello, world.");
    return 0;
}