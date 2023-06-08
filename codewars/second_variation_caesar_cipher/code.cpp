#include <assert.h>
#include <iostream>

#include <string>
#include <vector>
#include <cmath>

class CaesarTwo
{
public:
    static std::vector<std::string> encodeStr(const std::string &s, int shift);
    static std::string decode(std::vector<std::string> &s);
};

std::vector<std::string> CaesarTwo::encodeStr(const std::string &s, int shift)
{
    std::string encodedStr;
    for(char c: s)
    {
        if(isalpha(c))
        {
            if(isupper(c))
            {
                encodedStr += (((c - 'A') + shift) % 26) + 'A';
            }
            else
            {
                encodedStr += (((c - 'a') + shift) % 26) + 'a';
            }
        }
        else
        {
            encodedStr += c;
        }
    }

    std::string key;
    key += tolower(s[0]);
    key += tolower(encodedStr[0]);
    
    encodedStr = key + encodedStr;

    std::vector<std::string> res;
    int partLen(ceil(encodedStr.size() / 5.0));
    
    for(int i(0); i < encodedStr.size(); i += partLen)
    {
        res.push_back(encodedStr.substr(i, partLen));
    }

    return res;
}

std::string CaesarTwo::decode(std::vector<std::string> &s)
{
    int shift(s[0][1] - s[0][0]);
    if(shift < 0)
    {
        shift += 26;
    }

    std::string msg(s[0].substr(2));
    for(int i(1); i < s.size(); i++)
    {
        msg += s[i];
    }
    
    for(char &c: msg)
    {
        if(isalpha(c))
        {
            if(isupper(c))
            {
                c = (((c - 'A') - shift) % 26) + 'A';
            }
            else
            {
                c = (((c - 'a') - shift) % 26) + 'a';
            }
        }
    }
    return msg;
}

void testequal1(std::vector<std::string> ans, std::vector<std::string> sol)
{
    assert(ans == sol);
}
static void dotest1(const std::string &s, int shift, std::vector<std::string> expected)
{
    testequal1(CaesarTwo::encodeStr(s, shift), expected);
}

void testequal2(std::string ans, std::string sol)
{
    assert(ans == sol);
}
static void dotest2(std::vector<std::string> &s, std::string expected)
{
    testequal2(CaesarTwo::decode(s), expected);
}

void encode_Tests1()
{
    std::string u = "I should have known that you would have a perfect answer for me!!!";
    std::vector<std::string> sol = {"ijJ tipvme ibw", "f lopxo uibu z", "pv xpvme ibwf ", "b qfsgfdu botx", "fs gps nf!!!"};
    dotest1(u, 1, sol);
}
void decode_Tests()
{
    std::string u = "I should have known that you would have a perfect answer for me!!!";
    std::vector<std::string> sol = {"ijJ tipvme ibw", "f lopxo uibu z", "pv xpvme ibwf ", "b qfsgfdu botx", "fs gps nf!!!"};
    dotest2(sol, u);

}
int main()
{
    encode_Tests1();
    decode_Tests();
    return 0;
}