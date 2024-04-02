#include <iostream>
#include <assert.h>

class Solution {
public:
    // idea : 
    //  find longest substring of 'T's with atmost k 'F's
    //  find longest substring of 'F's with atmost k 'T's
    int maxConsecutiveAnswers(std::string s, int k) {
        int n = s.size();
        int res = 0;
        int left = 0;
        // longest substring of 'T's
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'F')
            {
                cnt++;
            }
            while(cnt > k)
            {
                if(s[left] == 'F')cnt--;
                left++;
            }
            res = std::max(res, i - left + 1);
        }

        cnt = 0;
        left = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'T')
            {
                cnt++;
            }
            while(cnt > k)
            {
                if(s[left] == 'T')cnt--;
                left++;
            }
            res = std::max(res, i - left + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string answerKey = "TTFF";
        int k = 2;
        int res = 4;
        assert(sol.maxConsecutiveAnswers(answerKey, k) == res);
    }
    return 0;
}