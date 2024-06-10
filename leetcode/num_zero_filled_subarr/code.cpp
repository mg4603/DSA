#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::vector<int> sizes;

        int len = 0;
        int largest = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                len++;
            } else {
                if(len) {
                    largest = std::max(largest, len);
                    sizes.push_back(len);
                }
                len = 0;
            }
        }

        if(len){
            sizes.push_back(len);
            largest = std::max(len, largest);
        }
        
        if(largest == 0) {
            return 0;
        }


        long long res = 0;
        std::vector<long long> table(largest + 1);
        table[1] = 1;

        for(int i = 2; i <= largest; i++) {
            table[i] = i + table[i - 1];
        }

        for(int i = 0; i < sizes.size(); i++) {
            res += table[sizes[i]];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,0,0,2,0,0,4};
        int res = 6;
        assert(sol.zeroFilledSubarray(nums) == res);
    }
    return 0;
}