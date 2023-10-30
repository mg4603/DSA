#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> circularGameLosers(int n, int k) 
    {
        std::unordered_set<int> st;
        int current = 0;
        int i = 1;
        while(!st.count(current + 1))
        {
            st.insert(current + 1);
            current += (i * k);
            i++;
            current %= (n);
        }

        std::vector<int> res;
        for(int i = 1; i <= n ; i++)
        {
            if(!st.count(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int k = 2;
        std::vector<int> res = {4, 5};
        assert(sol.circularGameLosers(n, k) == res);
    }
    {
        int n = 4;
        int k = 4;
        std::vector<int> res = {2, 3, 4};
        assert(sol.circularGameLosers(n, k) == res);
    }
    return 0;
}