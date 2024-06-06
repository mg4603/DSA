#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>

class Solution {
public:
    int mctFromLeafValues(std::vector<int>& arr) {
        std::vector<int> st;
        int res = 0;
        st.push_back(INT_MAX);
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && st.back() <= arr[i]) {
                int back = st.back();
                st.pop_back();
                res += std::min(arr[i], st.back()) * back;
            }
            st.push_back(arr[i]);
        }
        for(int i = 2; i < st.size(); i++) {
            res += st[i] * st[i - 1];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {6,2,4};
        int res = 32;
        assert(sol.mctFromLeafValues(arr) == res);
    }
    return 0;
}