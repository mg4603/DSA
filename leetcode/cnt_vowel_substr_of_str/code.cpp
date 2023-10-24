#include <iostream>
#include <assert.h>

#include <unordered_set>

class Solution {
public:
    int countVowelSubstrings(std::string word) {
        std::string vowels = "aeiou";
        int n = word.length();
        std::unordered_set<char> st;

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(vowels.find(word[j]) != std::string::npos)
                {
                    st.insert(word[j]);
                }
                else
                {
                    break;
                }
                if(st.size() == 5)res++;
            }
            st.clear();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "aeiouu";
        int res = 2;
        assert(sol.countVowelSubstrings(word) == res);
    }
    {
        std::string word = "unicornarihan";
        int res = 0;
        assert(sol.countVowelSubstrings(word) == res);
    }
    {
        std::string word = "cuaieuouac";
        int res = 7;
        assert(sol.countVowelSubstrings(word) == res);
    }
    return 0;
}