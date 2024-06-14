#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(
                        std::vector<int>& temperatures) {
        std::ios::sync_with_stdio(0);
        std::vector<std::pair<int, int>> st;
        int n = temperatures.size();
        std::vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && 
                    st.back().first < temperatures[i]) {
                auto [_, pos] = st.back();
                st.pop_back();
                res[pos] = i - pos;
            }
            st.push_back({temperatures[i], i});
        }
        
        while(!st.empty()) {
                auto [_, pos] = st.back();
                st.pop_back();
                res[pos] = 0;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
        std::vector<int> res = {1,1,4,2,1,1,0,0};

        assert(sol.dailyTemperatures(temperatures) == res);
    }
    return 0;
}