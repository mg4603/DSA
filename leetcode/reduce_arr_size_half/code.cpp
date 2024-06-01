#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minSetSize(std::vector<int>& arr) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<int, int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        std::vector<int> freq;
        for(auto &it: mp) {
            freq.push_back(it.second);
        }
        std::sort(freq.begin(), freq.end(), std::greater<int>());
        int cnt = 0;
        for(int i = 0; i < freq.size(); i++) {
            cnt += freq[i];
            if(cnt >= n / 2) {
                return i + 1;
            }
        }
        return n;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
        int res = 2;
        assert(sol.minSetSize(arr) == res);
    }
    return 0;
}