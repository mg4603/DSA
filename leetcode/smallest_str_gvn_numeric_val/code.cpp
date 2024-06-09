#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string getSmallestString(int n, int k) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        std::string res(n, 'a');
        k -= n;
        for(int i = n - 1; i >= 0 && k > 0; i--) {
            res[i] += (k > 25 ? 25 : k);
            k -= 25;            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3, k = 27;
        std::string res = "aay";
        assert(sol.getSmallestString(n, k) == res);
    }
    return 0;
}