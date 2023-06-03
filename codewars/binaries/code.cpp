#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>

namespace coding
{
    std::string toBinStr(char c)
    {
        if(c == '0')
        {
            return "0";
        }
        int n(c - '0');
        std::string res;
        while(n)
        {
            res = std::to_string(n % 2) + res;
            n /= 2;
        }
        return res;
    }

    std::string code(const std::string &strng)
    {
        std::string res;
        for(const char c: strng)
        {
            std::string bin(toBinStr(c));
            res += std::string(bin.length() - 1, '0');
            res += '1';
            res += bin;
        }
        return res;
    }
    char binStrToInt(std::string n)
    {
        int res(0);
        for(int i(0); i < n.size(); i++)
        {
            res += (n[n.size() - i - 1] - '0') * pow(2, i);
        }
        return res + '0';
    }
    std::string decode(const std::string &str)
    {
        std::string res;
        long long idx(0);
        while(idx < static_cast<long long>(str.size()))
        {
            long long pos(str.find_first_of("1", idx));
            long long len(pos - idx + 1);
            std::string bin(str.substr(pos + 1, len));
            res += binStrToInt(bin);
            idx  = pos + 1 + len;
        }
        return res;
    }
}


void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void testing_code(const std::string strng, std::string expect)
{
    testequal(coding::code(strng), expect);
}
void testing_decode(const std::string strng, std::string expect)
{
    testequal(coding::decode(strng), expect);
}



void testCode()
{
    testing_code("62", "0011100110");
    testing_code("55337700", "001101001101011101110011110011111010");
    testing_code("1119441933000055", "1111110001100100110000110011000110010111011110101010001101001101");
    testing_code("69", "00111000011001");
    testing_code("86", "00011000001110");

}

void testDecode()
{
    testing_decode("10001111", "07");
    testing_decode("001100001100001100001110001110001110011101110111001110001110001110001111001111001111001100001100001100", "444666333666777444");
    testing_decode("01110111110001100100011000000110000011110011110111011100110000110001100110", "33198877334422");
    testing_decode("0011010011010011011010101111110011000011000011000011100011100011100011100011100011100001100100011001000110011100011001001111001111001111001111001111001111", "55500011144466666699919777777");
    testing_decode("01110111011111000110010011110011110011110011110011110011110111011101110110011001100110011001101111111010101100011001000110000001100000011000", "3331977777733322222211100019888");

}

int main()
{
    testCode();
    testDecode();
    return 0;
}