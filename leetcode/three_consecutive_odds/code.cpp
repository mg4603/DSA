#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        for(int i = 0; i < static_cast<int>(arr.size()) - 2; i++)
        {
            if(arr[i] % 2 == 1)
            {
                int count = 1;
                for(int j = 1; j < 3; j++)
                {
                    if(arr[++i] % 2 == 1)
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(count == 3)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,6,4,1};
        bool res = false;
        assert(sol.threeConsecutiveOdds(arr) == res);
    }
    {
        std::vector<int> arr = {1,2,34,3,4,5,7,23,12};
        bool res = true;
        assert(sol.threeConsecutiveOdds(arr) == res);
    }    
    return 0;
}