#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    int numOnes(int n)
    {
        int ones = 0;
        while(n)
        {
            if(n % 2 == 1)
            {
                ones++;
            }
            n /= 2;
        }
        return ones;
    }
public:
    std::vector<int> sortByBits(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        int n = arr.size();
        std::vector<std::pair<int, int>> temp(n);
        for(int i = 0; i < n; i++)
        {
            temp[i] = std::make_pair(numOnes(arr[i]), arr[i]);
        }
        
        std::vector<int> res(n, 0);
        std::sort(temp.begin(), temp.end(), [](
                    std::pair<int, int> one, std::pair<int, int> two)
        {
            if(one.first == two.first)
            {
                return one.second < two.second;
            }
            return one.first < two.first;
        });

        for(int i = 0; i < n; i++)
        {
            res[i] = temp[i].second;
        }

        // std::sort(arr.begin(), arr.end(), [&](int num1, int num2)
        // {
            // if(numOnes(num1) == numOnes(num2))
            // {
                // return num1 < num2;
            // }
            // return numOnes(num1) < numOnes(num2);
        // });
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {0,1,2,3,4,5,6,7,8};
        std::vector<int> res = {0,1,2,4,8,3,5,6,7};
        assert(sol.sortByBits(arr) == res);
    }
    {
        std::vector<int> arr = {1024,512,256,128,64,32,16,8,4,2,1};
        std::vector<int> res = {1,2,4,8,16,32,64,128,256,512,1024};
        assert(sol.sortByBits(arr) == res);
    }
    return 0;
}