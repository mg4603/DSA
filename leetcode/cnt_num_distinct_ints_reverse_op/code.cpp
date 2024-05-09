#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
    int reverse(int num) {
        int n = 0;
        while(num) {
            n *= 10;
            n += num % 10;
            num /= 10;
        }
        return n;
    }
public:
    int countDistinctIntegers(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            st.insert(reverse(nums[i]));
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,13,10,12,31};
        int res = 6;
        assert(sol.countDistinctIntegers(nums) == res);
    }
    return 0;
}