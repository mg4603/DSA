#include <iostream>
#include <assert.h>

#include <map>

class Solution {
    int digitsSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        std::map<int, int> m;
        int largest = 0;
        for(int i = 1; i <= n; i++)
        {
            int temp = ++m[digitsSum(i)];
            if(temp > largest)
            {
                largest = temp;
            }
        }

        int res = 0;
        for(auto it: m)
        {
            if(it.second == largest)
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 13;
        int res = 4;
        assert(sol.countLargestGroup(n) == res);
    }
    {
        int n = 2;
        int res = 2;
        assert(sol.countLargestGroup(n) == res);
    }

    return 0;
}