#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        std::unordered_set<int> st;
        for(int i = 0; i < arr.size(); i++)
        {
            int temp = arr[i];
            if(st.find(2 * temp) != st.end() || 
                (temp / 2.0 == temp / 2 && st.find(temp / 2) != st.end()))
            {
                return true;
            }
            st.insert(arr[i]);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {10,2,5,3};
        bool res = true;
        assert(sol.checkIfExist(arr) == res);
    }
    {
        std::vector<int> arr = {3,1,7,11};
        bool res = false;
        assert(sol.checkIfExist(arr) == res);
    }
    return 0;
}