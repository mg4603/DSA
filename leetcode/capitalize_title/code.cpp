#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    std::string capitalizeTitle(std::string title) 
    {
        std::ios_base::sync_with_stdio(0);
        std::stringstream ss(title);
        std::string temp;

        title = "";

        while(ss >> temp)
        {
            int n = temp.length();
            if(n <= 2)    
            {
                for(int i = 0; i < n; i++)
                {
                    temp[i] = std::tolower(temp[i]);
                }
            }
            else
            {
                temp[0] = std::toupper(temp[0]);
                for(int i = 1; i < n; i++)
                {
                    temp[i] = std::tolower(temp[i]);
                }
            }
            title += temp;
            title += ' ';
        }
        if(title != "")
        {
            title.pop_back();
        }
        return title;
    }
};

int main()
{
    Solution sol;
    {
        std::string title = "capiTalIze tHe titLe";
        std::string res = "Capitalize The Title";
        assert(sol.capitalizeTitle(title) == res);
    }
    {
        std::string title = "First leTTeR of EACH Word";
        std::string res = "First Letter of Each Word";
        assert(sol.capitalizeTitle(title) == res);
    }
    {
        std::string title = "i lOve leetcode";
        std::string res = "i Love Leetcode";
        assert(sol.capitalizeTitle(title) == res);
    }
    return 0;
}