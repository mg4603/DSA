#include <iostream>
#include <assert.h>

#include <numeric>
#include <vector>
#define ull unsigned long long

class Diagonal
{
public:
    static ull diagonal(int n, int p);
};

ull Diagonal::diagonal(int n, int p)
{
    std::vector<ull> diag(n + 1, 1);
    for(int i(0); i < p; i++)
    {
        std::vector<ull> temp;
        temp.push_back(1);
        for(size_t j(1); j < diag.size() - 1; j++)
        {
            temp.push_back(temp.back() + diag[j]);
        }
        diag = temp;
    }
    ull res(0);
    for(auto num:diag)
    {
        res += num;
    }
    return res;
}

void testequal(ull ans, ull sol)
{
    assert(ans == sol);
}
void dotest(int n, int k, ull expected)
{
    testequal(Diagonal::diagonal(n, k), expected);
}
int main()
{   
    dotest(7, 0 , 8);
    dotest(7, 1, 28);
    dotest(7, 2, 56);
    dotest(7, 8, 1);
    dotest(100, 10, 158940114100040);
    dotest(41, 10, 4280561376);
    dotest(20, 3, 5985);
    dotest(20, 4, 20349);
    dotest(20, 5, 54264);
    dotest(20, 15, 20349);
    return 0;
}