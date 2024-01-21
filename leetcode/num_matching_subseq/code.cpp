#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int numMatchingSubseq(std::string s, 
                        std::vector<std::string>& words) {

        std::vector<std::vector<int>> letter_pos(26);
        for(int i = 0; i < s.length(); i++)
        {
            letter_pos[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for(std::string word: words)
        {
            bool found = true;
            int x = -1;

            for(char ch: word)
            {
                // iterator to first val in vec larger than x
                // or end if such a value is not found
                auto it = upper_bound(letter_pos[ch-'a'].begin(), 
                                        letter_pos[ch-'a'].end(), x);

                if(it == letter_pos[ch-'a'].end())
                {
                    found = false;
                    break;
                }
                x = *it;
            }
            if(found)res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcde";
        std::vector<std::string> words = {"a","bb","acd","ace"};
        int res = 3;
        assert(sol.numMatchingSubseq(s, words) == res);
    }
    return 0;
}