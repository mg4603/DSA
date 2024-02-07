#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(
                std::vector<int>& arr, int k) 
    {
        int n = arr.size();
        double l = 0.0, r = 1.0;

        while(l < r)
        {
            double mid = (l + r) / 2;
            int total = 0;
            int p = 0;
            int q = 0;
            int j = 1;
            double max_f = 0.0;

            for(int i = 0; i < n; i++)
            {
                while(j < n && arr[i] > mid * arr[j])j++;

                total += (n - j);
                if(j == n)break;

                double f = static_cast<double>(arr[i]) / arr[j];

                if(f > max_f)
                {
                    p = i;
                    q = j;
                    max_f = f;
                }
            }

            if(total == k)
            {
                return {arr[p], arr[q]};
            }
            else if(total < k)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
            
        }
        return {};
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,3,5};
        int k = 3;
        std::vector<int> res = {2, 5};
        assert(sol.kthSmallestPrimeFraction(arr, k) == res);
    }
    return 0;
}