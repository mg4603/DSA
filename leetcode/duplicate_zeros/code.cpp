#include <iostream>
#include <assert.h>

#include <vector>
#include <stack>

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int n(arr.size());
        std::stack<int> st;

        int i = 0;
        while(i < n && st.size() < n)
        {
            st.push(arr[i]);
            if(arr[i] == 0 && st.size() < n)
            {
                st.push(arr[i]);
            }
            i++;
        }
        n--;
        while(n >= 0)
        {
            arr[n--] = st.top();
            st.pop();
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,0,2,3,0,4,5,0};
        std::vector<int> res = {1,0,0,2,3,0,0,4};
        sol.duplicateZeros(arr);
        assert(arr == res);
    }
    {
        std::vector<int> arr = {1,2,3};
        std::vector<int> res = {1,2,3};
        sol.duplicateZeros(arr);
        assert(arr == res);
    }
    return 0;
}