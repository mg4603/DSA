#include <iostream>
#include <assert.h>

#include <string>
#include <vector>

class ModSystem
{
private:
    static bool coprime(int a, int b);
    static int gcd(int a, int b);
public:
    static std::string fromNb2Str(int n, std::vector<int> &sys);
};

bool ModSystem::coprime(int a, int b)
{
    if(gcd(a, b) == 1)
    {
        return true;
    }
    return false;
}

int ModSystem::gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

std::string ModSystem::fromNb2Str(int n, std::vector<int> &sys)
{
    for(size_t i(0); i < sys.size(); i++)
    {
        for(size_t j(i + 1); j < sys.size(); j++)
        {
            if(!coprime(sys[i], sys[j]))
            {
                return "Not applicable";
            }
        }
    }

    std::string res;
    int prod(1);
    for(int num: sys)
    {
        res += "-" + std::to_string(n % num) + "-";
        prod *= num;
    }
    if(prod < n)
    {
        return "Not applicable";
    }
    return res;
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
static void dotest(int n, std::vector<int> &sys, std::string expected)
{
    testequal(ModSystem::fromNb2Str(n, sys), expected);
}

int main()
{
    std::vector<int> d = {8,7,5,3};
    dotest(779, d, "-3--2--4--2-");
    dotest(187, d, "-3--5--2--1-");
    dotest(259, d, "-3--0--4--1-");
    dotest(446, d, "-6--5--1--2-");
    return 0;
}