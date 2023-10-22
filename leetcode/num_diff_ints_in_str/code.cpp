#include <iostream>
#include <assert.h>

#include <set>

class Solution {
    std::string removeLeadingZeros(std::string num)
    {
        int n = num.size();
        int leading_zeros = 0;
        for(int i = 0; i < n; i++)
        {
            if(num[i] != '0')
            {
                break;
            }
            leading_zeros++;
        }
        if(leading_zeros < n)
        {
            num = num.substr(leading_zeros);
        }
        else
        {
            num = "0";
        }
        return num;
    }
public:
    int numDifferentIntegers(std::string word) {
        std::set<std::string> st;
        std::string current;
        for(int i = 0; i < word.length(); i++)
        {
            if(std::isdigit(word[i]))
            {
                current += word[i];
            }
            else
            {
                if(current != "")
                {
                    current = removeLeadingZeros(current);
                    st.insert(current);
                    current = "";
                }
            }
        }
        if(current != "")
        {
            current = removeLeadingZeros(current);
            st.insert(current);
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "a123bc34d8ef34";
        int res = 3;
        assert(sol.numDifferentIntegers(word) == res);
    }
    {
        std::string word = "leet1234code234";
        int res = 2;
        assert(sol.numDifferentIntegers(word) == res);
    }
    {
        std::string word = "a1b01c001";
        int res = 1;
        assert(sol.numDifferentIntegers(word) == res);
    }
    return 0;
}