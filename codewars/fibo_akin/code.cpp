#include <iostream>
#include <assert.h>

#include <vector>

class Fibkind
{
public:
    static std::vector<int> getSeqU(int n);
    static int lengthSupUK(int n, int k);
    static int comp(int n);
};

std::vector<int> Fibkind::getSeqU(int n)
{
    std::vector<int> u(n, 0);
    u[0] = 1;
    u[1] = 1;
    for(int i(2); i < n; i++)
    {
        u[i] = u[i - u[i - 1]] + u[i - u[i - 2]];
    }
    return u;
}

int Fibkind::lengthSupUK(int n, int k)
{
    std::vector<int> u(n, 0);
    u[0] = 1;
    u[1] = 1;

    int cnt(0);
    
    if(k <= 1)
    {
        cnt += 2;
    }
    for(int i(2); i < n; i++)
    {
        u[i] = u[i - u[i - 1]] + u[i - u[i - 2]];
        if(u[i] >= k)
            cnt++;
    }
    return cnt;
}

int Fibkind::comp(int n)
{
    std::vector<int> u(n, 0);
    u[0] = 1;
    u[1] = 1;

    int cnt(0);
    
    for(int i(2); i < n; i++)
    {
        u[i] = u[i - u[i - 1]] + u[i - u[i - 2]];
        if(u[i] < u[i - 1])
            cnt++;
    }
    return cnt;
}

void testequal(int ans, int sol)
{
    assert(ans == sol);
}
static void dotest1(int n, int k, int expected)
{
    testequal(Fibkind::lengthSupUK(n, k), expected);
}
static void dotest2(int n, int expected) {
    testequal(Fibkind::comp(n), expected);
}
static void test1()
{
    dotest1(50, 25, 2);
    dotest1(3332, 973, 1391);
    dotest1(2941, 862, 1246);
    dotest1(3177, 573, 2047);
    dotest1(1745, 645, 474);
}

static void test2()
{
    dotest2(74626, 37128);
    dotest2(71749, 35692);
    dotest2(56890, 28281);
    dotest2(60441, 30054);
    dotest2(21361, 10581);
}

void fixed_Tests_1()
{
    std::cout << "Fibkind::lengthSupUK" << std::endl;
    test1();
}
void fixed_Tests_2()
{
    std::cout << "Fibkind::comp" << std::endl;
    test2();
}

int main()
{
    fixed_Tests_1();
    fixed_Tests_2();
    return 0;
}