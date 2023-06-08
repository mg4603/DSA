#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

namespace Bud
{
    long long s(long long n)
    {
        long long sum(1);
        for(long long i(2); i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                sum += i;
                sum += (n/i);
            }
        }
        return sum;
    }

    std::string buddy(long long start, long long limit)
    {
        std::string res;
        for(long long i(start); i <= limit; i++)
        {   
            int prospectiveBuddy(s(i) - 1);
            if(s(prospectiveBuddy) - 1 == i && prospectiveBuddy >= start && i != prospectiveBuddy)
            {
                res += "(";
                res += std::to_string(i);
                res += " ";
                res += std::to_string(prospectiveBuddy);
                res += ")";
                break;
            }
        }

        if(res.size() == 0)
        {
            res = "Nothing";
        }
        return res;
    }
}


void testing(long long start, long long limit, std::string expected)
{
    std::cout << "Start " << start << " Limit " << limit << std::endl;
    std::string actual = Bud::buddy(start, limit);
    std::cout << "Actual " << actual << std::endl;
    std::cout << "Expect " << expected << std::endl << std::endl;
    assert(actual == expected);
}

int main()
{
    testing(1071625, 1103735, "(1081184 1331967)");
    testing(2382, 3679, "Nothing");
    testing(8983, 13355, "(9504 20735)");
    testing(2177, 4357, "Nothing");
    return 0;
};
