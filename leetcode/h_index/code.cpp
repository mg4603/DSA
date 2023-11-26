#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) 
    {
        int n = citations.size();
        std::sort(citations.begin(), citations.end(), 
                    std::greater<int>());

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(i + 1 <= citations[i])
            {
                res = i + 1;
            }
        }

        return res; 
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> citations = {3,0,6,1,5};
        int res = 3;
        assert(sol.hIndex(citations) == res);
    }
    {
        std::vector<int> citations = {1,3,1};
        int res = 1;
        assert(sol.hIndex(citations) == res);
    }
    return 0;
}