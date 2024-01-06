#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    std::vector<int> intToVec(int num, int size)
    {
        std::vector<int> n(size);
        while(num)
        {
            n[size-1] = num % 10;
            num /= 10;
            size--;
        }
        return n;
    }

    int vecToInt(std::vector<int> &vec)
    {
        int num = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            num *= 10;
            num += vec[i];
        }
        return num;
    }
public:
    int maximumSwap(int num) {
        int size = std::log10(num) + 1;
        std::vector<int> n = intToVec(num, size);
        
        int res = num;
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                std::swap(n[i], n[j]);
                res = std::max(res, vecToInt(n));
                std::swap(n[i], n[j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int num = 2736;
        int res = 7236;
        assert(sol.maximumSwap(num) == res);
    }
    {
        int num = 9973;
        int res = 9973;
        assert(sol.maximumSwap(num) == res);
    }
    return 0;
}