#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestValsFromLabels(std::vector<int>& values, 
                        std::vector<int>& labels, int numWanted, 
                        int useLimit) {

        std::ios::sync_with_stdio(0);
        std::vector<std::pair<int, int>> pairs;
        int n = values.size();
        for(int i = 0; i < n; i++) {
            pairs.push_back({values[i], labels[i]});
        }
        std::sort(pairs.begin(), pairs.end(), 
                    std::greater<std::pair<int, int>>());
        std::unordered_map<int, int> mp;
        int res = 0;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(mp[pairs[i].second] < useLimit) {
                mp[pairs[i].second]++;
                res += pairs[i].first;
                cnt++;
                if(cnt == numWanted)break;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> values = {5,4,3,2,1};
        std::vector<int> labels = {1,1,2,2,3};
        int numWanted = 3, useLimit = 1, res = 9;
        assert(sol.largestValsFromLabels(values, labels, 
                        numWanted, useLimit) == res);
    }
    return 0;
}