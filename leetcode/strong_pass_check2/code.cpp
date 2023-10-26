#include <iostream>
#include <assert.h>

class Solution {
public:
    bool strongPasswordCheckerII(std::string password) {
        int n = password.length();
        int lower = 0;
        int upper = 0;
        int digit = 0;
        std::string special_chars = "!@#$%^&*()-+";
        int special_char = 0;
        for(int i = 0; i < n; i++)
        {
            if(std::isalpha(password[i]))
            {
                if(!lower && std::islower(password[i]))
                {
                    lower = 1;
                }
                if(!upper && std::isupper(password[i]))
                {
                    upper = 1;
                }

            }
            else if(!digit && std::isdigit(password[i]))
            {
                digit = 1;
            }
            else if(!special_char && 
                    special_chars.find(password[i]) != std::string::npos)
            {
                special_char = 1;
            }
            if((i - 1 >= 0 && password[i - 1] == password[i]) ||
               (i + 1 < n && password[i + 1] == password[i]))
            {
                return false;
            }
        }

        return lower && upper && digit && special_char && n >= 8;
    }
};

int main()
{
    Solution sol;
    {
        std::string password = "IloveLe3tcode!";
        bool res = 1;
        assert(sol.strongPasswordCheckerII(password) == res);
    }
    {
        std::string password = "Me+You--IsMyDream";
        bool res = 0;
        assert(sol.strongPasswordCheckerII(password) == res);
    }
    {
        std::string password = "1aB!";
        bool res = 0;
        assert(sol.strongPasswordCheckerII(password) == res);
    }
    return 0;
}