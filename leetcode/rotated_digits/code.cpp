#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int rotatedDigits(int n) {
        std::vector<int> vec{1, 1, 2, 0, 0, 2, 2, 0, 1, 2};
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int temp = i;
            int temp1 = 1;
            while(temp)
            {
                temp1 *= vec[temp % 10];
                temp /= 10;
            }
            if(temp1 >= 2)res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        int res = 4;
        assert(sol.rotatedDigits(n) == res);
    }
    return 0;
}