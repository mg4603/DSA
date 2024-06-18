#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        std::vector<int> fib {1, 1};
        int n = 2;
        while(fib[n - 2] + fib[n - 1] <= k) {
            fib.push_back(fib[n - 1] + fib[n - 2]);
            n++;
        }

        int res = 0;
        while(k > 0 & n > 1) {
            k -= fib[n - 1];
            while(fib[n - 1] > k && n > 1) {
                n--;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int k = 7;
        int res = 2;
        assert(sol.findMinFibonacciNumbers(k) == res);
    }
    return 0;
}