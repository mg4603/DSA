#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<long long> maximumEvenSplit(long long finalSum) {
        std::ios::sync_with_stdio(0);
        if(finalSum % 2 == 1)return {};
        std::vector<long long> res;
        long long sum = 0;
        long long i = 2;
        while(sum < finalSum) {
            sum += i;
            res.push_back(i);
            i += 2;
        }
        if(sum > finalSum) {
            sum -= res.back();
            res.pop_back();
            res.back() += (finalSum - sum);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        int finalSum = 12;
        std::vector<long long> res = {2, 4, 6};
        assert(sol.maximumEvenSplit(finalSum) == res);
    }
    return 0;
}