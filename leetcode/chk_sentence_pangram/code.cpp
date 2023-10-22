#include <iostream>
#include <assert.h>

#include <set>

class Solution {
public:
    bool checkIfPangram(std::string sentence) 
    {
        std::set<char> st;
        for(int i = 0; i < sentence.length(); i++)
        {
            st.insert(sentence[i]);
        }
        return st.size() == 26;
    }
};

int main()
{
    Solution sol;
    {
        std::string sentence = "thequickbrownfoxjumpsoverthelazydog";
        bool res = true;
        assert(sol.checkIfPangram(sentence) == res);
    }
    {
        std::string sentence = "leetcode";
        bool res = false;
        assert(sol.checkIfPangram(sentence) == res);
    }
    return 0;
}