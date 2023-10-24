#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
    void getDigits(int n, std::unordered_map<int, int> &mp)
    {
        while(n)
        {
            mp[n%10]++;
            n/=10;
        }
    }
public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) 
    {
        std::unordered_map<int, int> mp;
        for(int i = 0; i < digits.size(); i++)
        {
            mp[digits[i]]++;
        }

        std::vector<int> res;
        std::unordered_map<int, int> dgt_mp;
        for(int i = 100; i < 999; i += 2)
        {
            getDigits(i, dgt_mp);
            int flag = 1;
            for(auto it: dgt_mp)
            {
                if(mp.count(it.first) == 0 || mp[it.first] < it.second)
                {
                    flag = 0;   
                }
            }
            if(flag)
            {
                res.push_back(i);
            }
            dgt_mp.clear();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> digits = {2,1,3,0};
        std::vector<int> res = {102,120,130,132,210,230,302,310,312,320};
        assert(sol.findEvenNumbers(digits) == res);
    }
    {
        std::vector<int> digits = {2,2,8,8,2};
        std::vector<int> res = {222,228,282,288,822,828,882};
        assert(sol.findEvenNumbers(digits) == res);
    }
    {
        std::vector<int> digits = {3,7,5};
        std::vector<int> res = {};
        assert(sol.findEvenNumbers(digits) == res);
    }    
    return 0;
}