#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string interpret(std::string command) {
        int n = command.length();
        std::string res;
        int i = 0;
        while(i < n)
        {
            if(command[i] == 'G')
            {
                res += 'G';
                i++;
            }
            else if(i + 1 < n &&  command[i] == '(' && command[i + 1] == ')')
            {
                res += 'o';
                i += 2;
            }
            else if(i + 3 < n && command.substr(i, 4) == "(al)")
            {
                res += "al";
                i += 4;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string command = "G()(al)";
        std::string res = "Goal";
        assert(sol.interpret(command) == res);
    }
    {
        std::string command = "G()()()()(al)";
        std::string res = "Gooooal";
        assert(sol.interpret(command) == res);
    }
    {
        std::string command = "(al)G(al)()()G";
        std::string res = "alGalooG";
        assert(sol.interpret(command) == res);
    }
    return 0;
}