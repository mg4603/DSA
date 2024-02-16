#include <iostream>
#include <assert.h>

#include <limits>

class Solution {
    long gcd(long a, long b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    long lcm(long a, long b)
    {
        return a * b / gcd(a, b);
    }
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        int l = 1;
        int r = std::numeric_limits<int>::max();

        long a = (long)A;
        long b = (long)B;
        long c = (long)C;

        long ab = lcm(a, b);
        long bc = lcm(c, b);
        long ac = lcm(a, c);
        long abc = lcm(a, bc);

        while(l < r)
        {
            int mid = l + ((r - l) / 2);
            int cnt = (mid / a) + (mid / b) + 
                        (mid / c) - (mid / ab) - 
                        (mid / bc) - (mid / ac) + 
                        (mid / abc);
            if(cnt < n)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int a = 2;
        int b = 3;
        int c = 5;
        int res = 4;
        assert(sol.nthUglyNumber(n, a, b , c) == res);
    }
    return 0;
}