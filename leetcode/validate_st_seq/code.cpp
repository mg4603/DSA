#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, 
                                std::vector<int>& popped) {
        int n = pushed.size();
        std::vector<int> st;
        int j = 0;
        for(int i = 0; i < n; i++){
            st.push_back(pushed[i]);
            while(!st.empty() && st.back() == popped[j]) {
                j++;
                st.pop_back();
            }
        }
        return st.size() == 0;        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> pushed = {1,2,3,4,5};
        std::vector<int> popped = {4,5,3,2,1};
        bool res = true;
        assert(sol.validateStackSequences(pushed, popped) == res);
    }
    return 0;
}