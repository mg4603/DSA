#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>

class Opstrings4
{
public:
    static std::string diag2Sym(const std::string &s);
    static std::string rot90Counter(const std::string &s);
    static std::string selfieDiag2Counterclock(const std::string &s);
    template<typename Func>
    static std::string oper(Func fct, const std::string &s);
};

std::string Opstrings4::diag2Sym(const std::string &s)
{   
    std::string new_s(s.begin(), s.end());
    size_t n = sqrt(new_s.size());
    for(size_t i(0); i < n; i++)
    {
        for(size_t j(0); j < n - i; j++)
        {
            std::swap(new_s[(i * (n + 1)) + j], new_s[((n - j - 1) * (n + 1)) + (n - i - 1)]);
        }
    }
    return new_s;
}

std::string Opstrings4::rot90Counter(const std::string &s)
{
    std::string new_s;
    size_t n = sqrt(s.size());
    for(size_t i(0); i < n; i++)
    {
        for(size_t j(0); j < n; j++)
        {
            new_s += s[j * (n + 1) + (n - i - 1)];
        }
        new_s += '\n';
    }
    if(new_s.back() == '\n')
    {
        new_s.pop_back();
    }
    return new_s;
}

std::string Opstrings4::selfieDiag2Counterclock(const std::string &s)
{
    std::string new_s;
    size_t n(sqrt(s.size()));
    for(size_t i(0); i < n; i++)
    {
        std::string selfie;
        std::string diag;
        std::string counterClock;
        for(size_t j(0); j < n; j++)
        {
            selfie += s[(n + 1) * i + j];
            diag += s[(n + 1) * (n - j - 1) + (n - i - 1)];
            counterClock += s[j * (n + 1) + (n - i - 1)];
        }
        new_s += selfie + "|" + diag + "|" + counterClock + "\n";
    }
    if(new_s.back() == '\n')
    {
        new_s.pop_back();
    }
    return new_s;

}

template<typename Func>
std::string Opstrings4::oper(Func fct, const std::string &s)
{
    return fct(s);
}

void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}
template<typename Func>
static void dotest(Func func, std::string s, std::string expected)
{
    testequal(Opstrings4::oper(func, s), expected);
}

void tests_rot90Counter()
{
    std::cout << "Fixed Tests rot90Counter" << std::endl;
    dotest(Opstrings4::rot90Counter, "EcGcXJ\naaygcA\nNgIshN\nyOrCZE\neBEqpm\nNkxCgw",
                "JANEmw\nXchZpg\ncgsCqC\nGyIrEx\ncagOBk\nEaNyeN");
}
void tests_diag2Sym()
{
    std::cout << "Fixed Tests diag2Sym" << std::endl;
    dotest(Opstrings4::diag2Sym, "LmvLyg\nDKELBm\nylJhui\nXRXqHD\nzlisCT\nhPqxYb",
                "bTDimg\nYCHuBy\nxsqhLL\nqiXJEv\nPlRlKm\nhzXyDL");
}
void tests_selfieDiag2Counterclock()
{
    std::cout << "Fixed Tests selfieDiag2Counterclock" << std::endl;
    dotest(Opstrings4::selfieDiag2Counterclock, "NJVGhr\nMObsvw\ntPhCtl\nsoEnhi\nrtQRLK\nzjliWg",
                "NJVGhr|gKilwr|rwliKg\nMObsvw|WLhtvh|hvthLW\ntPhCtl|iRnCsG|GsCnRi\nsoEnhi|lQEhbV|VbhEQl\nrtQRLK|jtoPOJ|JOPotj\nzjliWg|zrstMN|NMtsrz");
}

int main()
{
    tests_diag2Sym();
    tests_rot90Counter();
    tests_selfieDiag2Counterclock();
    return 0;
}