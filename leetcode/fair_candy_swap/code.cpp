#include <iostream>
#include <assert.h>

#include <numeric>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
        std::map<int, int> mp;
        int sum_bob(0);
        int sum_alice(0);
        for(int size: bobSizes)
        {
            mp[size]++;
            sum_bob += size;
        }
        sum_alice = std::accumulate(aliceSizes.begin(), aliceSizes.end(), sum_alice);


        std::vector<int> res;
        for(int size: aliceSizes)
        {
            int temp((sum_bob - sum_alice)/2 + size);
            if(mp.find(temp) != mp.end())
            {
                res.push_back(size);
                res.push_back(temp);
                return res;
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> aliceSizes = {1,1};
        std::vector<int> bobSizes = {2,2};
        std::vector<int> res = {1,2};
        assert(sol.fairCandySwap(aliceSizes, bobSizes) == res);
    }
    {
        std::vector<int> aliceSizes = {2};
        std::vector<int> bobSizes = {1,3};
        std::vector<int> res = {2,3};
        assert(sol.fairCandySwap(aliceSizes, bobSizes) == res);
    }
    return 0;
}