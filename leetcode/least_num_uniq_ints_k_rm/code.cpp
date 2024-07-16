#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::ios::sync_with_stdio(0);
        std::map<int, int> freq;
        for(int num: arr) {
            freq[num]++;
        }
        std::vector<int> counts;
        for(auto &[_, count]: freq) {
            counts.push_back(count);
        }

        std::sort(counts.begin(), counts.end());
        for(int i = 0; i < counts.size(); i++) {
            if(k < counts[i])return counts.size() - i;
            k -= counts[i];
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {5,5,4};
        int k = 1;
        int res = 1;
        assert(sol.findLeastNumOfUniqueInts(arr, k) == res);
    }
    return 0;
}