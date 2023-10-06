#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
        std::ios::sync_with_stdio(0);
        std::reverse(num.begin(), num.end());
        
        int carry = 0;
        int i= 0;

        while(i < num.size() && k > 0)
        {
            num[i] += ((k % 10) + carry);
            carry = num[i] / 10;
            num[i] %= 10;
            k /= 10;
            i++;
        }

        while(i < num.size())
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            i++;
        }

        while(k)
        {
            int temp = (k % 10) + carry;
            num.push_back(temp % 10);
            carry = temp / 10;
            k /= 10;
        }
        if(carry)
        {
            num.push_back(carry);
        }

        std::reverse(num.begin(), num.end());
        return num;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> num = {1,2,0,0};
        int k = 34;
        std::vector<int> res = {1,2,3,4};
        assert(sol.addToArrayForm(num, k) == res);
    }
    {
        std::vector<int> num = {2,7,4};
        int k = 181;
        std::vector<int> res = {4,5,5};
        assert(sol.addToArrayForm(num, k) == res);
    }
    {
        std::vector<int> num = {2,1,5};
        int k = 806;
        std::vector<int> res = {1,0,2,1};
        assert(sol.addToArrayForm(num, k) == res);
    }
    return 0;
}