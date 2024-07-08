#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minCharacters(std::string a, std::string b) {
        std::ios::sync_with_stdio(0);
        int n = a.size();
        int m = b.size();
        std::vector<int> cnt1(26, 0);
        std::vector<int> cnt2(26, 0);

        for(int i = 0; i < n; i++){
            cnt1[a[i] - 'a']++;
        }

        for(int i = 0; i < m; i++){
            cnt2[b[i] - 'a']++;
        }

        int res = m + n;

        for(int i = 0; i < 26; i++){
            res = std::min(res, m + n - cnt1[i] - cnt2[i]);

            if(i > 0){
                cnt1[i] += cnt1[i - 1];
                cnt2[i] += cnt2[i - 1];
            }
            if(i < 25){
                res = std::min(res, n - cnt1[i] + cnt2[i]);
                res = std::min(res, m - cnt2[i] + cnt1[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string a = "aba";
        std::string b = "caa";
        int res = 2;
        assert(sol.minCharacters(a, b) == res);
    }
    return 0;
}