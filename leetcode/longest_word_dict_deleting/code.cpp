#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::string findLongestWord(std::string s, 
                    std::vector<std::string>& dictionary) 
    {
        std::sort(dictionary.begin(), dictionary.end(), 
                [](std::string a, std::string b){
            if(a.length() == b.length())
            {
                return a > b;
            }
            return a.length() < b.length();
        });

        
        for(int i = dictionary.size() - 1; i >= 0; i--)
        {
            std::string temp = dictionary[i];
            int ptr1 = 0;
            int ptr2 = 0;
            while(ptr1 < s.length() && ptr2 < temp.length())
            {
                if(s[ptr1] == temp[ptr2])
                {
                    ptr1++;
                    ptr2++;
                }
                else
                {
                    ptr1++;
                }
            }
            if(ptr2 == temp.length())
            {
                return temp;
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abpcplea";
        std::vector<std::string> dictionary = {"ale","apple",
                                               "monkey","plea"};
        std::string res = "apple";
        assert(sol.findLongestWord(s,dictionary) == res);
    }
    return 0;
}