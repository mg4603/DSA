#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int captureForts(std::vector<int>& forts) {
        int left, right;
        int res = 0;
        int n = forts.size();

        for(int i = 0; i < n; i++)
        {
            if(forts[i] == 0 || forts[i] == -1)continue;
            left = i - 1;
            right = i + 1;
            while(left >= 0 && forts[left] == 0)
            {
                left--;
            }
            while(right < n && forts[right] == 0)
            {
                right++;
            }

            int capture_left = 0;
            if(left != -1 && forts[left] == -1)
            {
                capture_left = std::abs(i - left) - 1;
            }

            int capture_right = 0;
            if(right != n && forts[right] == -1)
            {
                capture_right = std::abs(i - right) - 1;
            }

            if(capture_left > res)
            {
                res = capture_left;
            }
            if(capture_right > res)
            {
                res = capture_right;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> forts = {1,0,0,-1,0,0,0,0,1};
        int res = 4;
        assert(sol.captureForts(forts) == res);
    }
    {
        std::vector<int> forts = {0,0,1,-1};
        int res = 0;
        assert(sol.captureForts(forts) == res);
    }
    return 0;
}