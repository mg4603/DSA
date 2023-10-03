#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isLongPressedName(std::string name, std::string typed) {
        int i(0);
        int j(0);
        while(i < name.size() && j < typed.size())
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if(i - 1 >= 0 && name[i - 1] == typed[j])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        while(i == name.size() && name.back() == typed[j])
        {
            j++;
        }
        return i == name.size() && j == typed.size();;
    }
};

int main()
{
    Solution sol;
    {
        std::string name = "alex";
        std::string typed = "aaleex";
        bool output = true;
        assert(sol.isLongPressedName(name, typed) == output);
    }
    {
        std::string name = "saeed";
        std::string typed = "ssaaedd";
        bool output = false;
        assert(sol.isLongPressedName(name, typed) == output);
    }
    return 0;
}