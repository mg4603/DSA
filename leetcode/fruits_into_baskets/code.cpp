#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int i = 0;
        int j = 0;
        std::unordered_map<int, int> cnt;
        int res = 0;
        int n = fruits.size();
        while(j < n)
        {
            cnt[fruits[j]]++;
            if(cnt.size() <= 2)
            {
                res = std::max(res, j - i + 1);
            }
            else
            {
                int temp = --cnt[fruits[i]];
                if(temp == 0)cnt.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> fruits = {1,2,1};
        int res = 3;
        assert(sol.totalFruit(fruits) == res);
    }
    return 0;
}