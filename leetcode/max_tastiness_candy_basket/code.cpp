#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumTastiness(std::vector<int>& price, int k) {
        std::ios::sync_with_stdio(0);
        
        std::sort(price.begin(), price.end());
        int n = price.size();
        int l = 0;
        int h = price[n - 1];

        while(l < h) {
            int i = (l + h)  / 2;
            int cnt = 1;
            int prev = price[0];

            for(int j = 1; j < n; j++) {
                if(price[j] >= prev + i) {
                    cnt++;
                    prev = price[j];
                }
            }
            
            if(cnt < k) {
                h = i;
            }else{
                l = i + 1;
            }
        }
        return l - 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> price = {13,5,1,8,21,2};
        int k = 3, res = 8;
        assert(sol.maximumTastiness(price, k) == res);
    }
    return 0;
}