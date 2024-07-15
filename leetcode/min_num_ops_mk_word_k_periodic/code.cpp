#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(std::string word, int k) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<std::string, int> freq;
        int max_freq = 0;
        int n = word.length();
        for(int i = 0; i < n - k + 1; i += k) {
            max_freq = std::max(max_freq, ++freq[word.substr(i, k)]);
        }
        
        return (n / k) - max_freq;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "leetcodeleet";
        int k = 4, res = 1;
        assert(sol.minimumOperationsToMakeKPeriodic(word, k) == res);
    }
    return 0;
}