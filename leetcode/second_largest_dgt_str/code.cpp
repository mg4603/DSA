#include <iostream>
#include <assert.h>

#include <set>

class Solution {
public:
    int secondHighest(std::string s) {
        std::set<int> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                st.insert(s[i] - '0');
            }
        }
        if(st.size() < 2)
        {
            return -1;
        }
        auto it = st.end();
        it--;
        it--;

        return *it;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "dfa12321afd";
        int res = 2;
        assert(sol.secondHighest(s) == res);
    }
    {
        std::string s = "abc1111";
        int res = -1;
        assert(sol.secondHighest(s) == res);
    }
    return 0;
}