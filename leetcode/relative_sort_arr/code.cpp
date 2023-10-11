#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1,
                                        std::vector<int>& arr2) 
    {
        std::vector<int> count(1001, 0);
        for(int i = 0; i < arr1.size(); i++)
        {
            count[arr1[i]]++;
        }

        int pos = 0;

        for(int i = 0; i < arr2.size(); i++)
        {
            while(count[arr2[i]]-- > 0)
            {
                arr1[pos++] = arr2[i];
            }
        }

        for(int i = 0; i < 1001; i++)
        {
            while(count[i]-- > 0)
            {
                arr1[pos++] = i;
            }
        }
        return arr1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
        std::vector<int> arr2 = {2,1,4,3,9,6};
        std::vector<int> res = {2,2,2,1,4,3,3,9,6,7,19};
        assert(sol.relativeSortArray(arr1, arr2) == res);
    }
    {
        std::vector<int>arr1 = {28,6,22,8,44,17};
        std::vector<int>arr2 = {22,28,8,6};
        std::vector<int> res = {22,28,8,6,17,44};
        assert(sol.relativeSortArray(arr1, arr2) == res);
    }
    
    return 0;
}