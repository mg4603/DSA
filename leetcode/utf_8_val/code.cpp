#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool validUtf8(std::vector<int>& data) 
    {
        int num_bytes = 0;
        int n = data.size();

        for(int i = 0; i < n; i++)
        {
            int temp = data[i];
            if(!num_bytes)
            {
                if(!(temp >> 7 & 1))
                {
                    continue;
                }

                for(int j = 6; j >= 0; j--)
                {
                    if(temp >> j & 1)
                    {
                        num_bytes++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(num_bytes == 0 || num_bytes >= 4)
                {
                    return false;
                }
            }
            else
            {
                if(!((temp >> 7 & 1) && !(temp >> 6 & 1)))
                {
                    return false;
                }
                num_bytes--;
            }

            
        }
        return (num_bytes == 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> data = {197,130,1};
        bool res = true;
        assert(sol.validUtf8(data) == res);
    }
    {
        std::vector<int> data = {235,140,4};
        bool res = false;
        assert(sol.validUtf8(data) == res);
    }
    return 0;
}