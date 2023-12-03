#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
    bool isNum(std::string num)
    {
        for(int i = 0; i < num.length(); i++)
        {
            if(!isdigit(num[i]))
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSerialization(std::string preorder) 
    {
        std::string temp;
        std::stringstream ss(preorder);

        int diff = 1;
        while(getline(ss, temp, ','))
        {
            if(temp != "#" && !isNum(temp))
            {
                return false;
            }
            if(--diff < 0)return false;
            if(temp != "#")diff += 2;
        }
        
        return diff == 0;
    }
};

int main()
{
    Solution sol;
    {
        std::string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
        bool res = true;
        assert(sol.isValidSerialization(preorder) == res);
    }
    {
        std::string preorder = "1,#";
        bool res = false;
        assert(sol.isValidSerialization(preorder) == res);
    }
    {
        std::string preorder = "9,#,#,1";
        bool res = false;
        assert(sol.isValidSerialization(preorder) == res);
    }
    return 0;
}