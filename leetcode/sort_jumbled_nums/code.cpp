#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
    int convert(std::vector<int> &mp, int num) {
        int res = 0;
        while(num) {
            res *= 10;
            res += (mp[num % 10]);
            num /= 10;
        }
        return res;
    }
public:
    std::vector<int> sortJumbled(std::vector<int>& mp, 
                            std::vector<int>& nums) {

        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            return convert(mp, a) < convert(mp, b);
        });
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
        std::vector<int> nums = {991,338,38};
        std::vector<int> res = {338,38,991};
        assert(sol.sortJumbled(mapping, nums) == res);
    }
    return 0;
}