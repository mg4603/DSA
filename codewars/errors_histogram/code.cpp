#include <iostream>
#include <assert.h>


#include <string>
#include <map>

std::string hist(const std::string &s)
{
    std::map<char, int> err_mp{
        {'u', 0},
        {'w', 0},
        {'x', 0},
        {'z', 0}
    };
    for(const char c: s)
    {
        if(err_mp.count(c))
        {
            err_mp[c]++;
        }
    }
    std::string res;
    for(auto err: err_mp)
    {
        if(err.second == 0)continue;

        res += err.first;
        res += "  ";
        res += std::to_string(err.second);
        res += std::string(6 - std::to_string(err.second).length(), ' ');
        res += std::string(err.second, '*');
        res += "\\r";
    }
    if(res.length() > 0)
    {
        res.pop_back();
        res.pop_back();
    }
    return res;
}

void testequal(std::string ans, std::string sol) {
    if(ans.length() != sol.length())
    {
        std::cout<<"Expected and ans are not of same length"<<std::endl;
        std::cout<<"Expected length: "<<sol.length()<<std::endl;
        std::cout<<"Answer length: "<<ans.length()<<std::endl;
    }
    assert(ans == sol);
}
void testing(std::string s, std::string expected)
{
    std::cout << "Testing:" << std::endl << s << std::endl;
    testequal(hist(s), expected);
}

int main()
{
    testing("tpwaemuqxdmwqbqrjbeosjnejqorxdozsxnrgpgqkeihqwybzyymqeazfkyiucesxwutgszbenzvgxibxrlvmzihcb", 
            "u  3     ***\\rw  4     ****\\rx  6     ******\\rz  6     ******");
    testing("aaifzlnderpeurcuqjqeywdq", "u  2     **\\rw  1     *\\rz  1     *");
    testing("sjeneccyhrcpfvpujfaoaykqllteovskclebmzjeqepilxygdmzvdfmxbqdzubkzturnuqxsewrwgmdfwgdx", 
        "u  4     ****\\rw  3     ***\\rx  4     ****\\rz  4     ****");
    testing("bnxyytdtqrkeaswymiwbxnuydwthweyzny", "u  1     *\\rw  4     ****\\rx  2     **\\rz  1     *");
    testing("ttopvdaxgwfpzjmomkwssytktaizqtsekfmfhrabidwaugioqyyzrxbugsusxkfdevmijqyprcoxfyjqwsutoutjgozyhsoytg", 
        "u  5     *****\\rw  4     ****\\rx  4     ****\\rz  4     ****");

   return 0;
}