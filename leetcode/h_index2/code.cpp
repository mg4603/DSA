#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) 
    {
        int n = citations.size();
        int res = 0;
        int l = 0;
        int r = n - 1;

        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(n - mid <= citations[mid])
            {
                res = n - mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> citations = {0,1,3,5,6};
        int res = 3;
        assert(sol.hIndex(citations) == res);
    }
    {
        std::vector<int> citations = {1,2,100};
        int res = 2;
        assert(sol.hIndex(citations) == res);
    }
    return 0;
}