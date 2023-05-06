#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>

class Opstrings1
{
public:
    static std::string rot(const std::string &s);
    static std::string selfieAndRot(const std::string &s);
    static std::string oper(std::string (f)(const std::string &str), const std::string &s);
};

std::string Opstrings1::oper(std::string (f)(const std::string &str), const std::string &s)
{
    return f(s);
}

std::string Opstrings1::rot(const std::string &s)
{
    int len(sqrt(s.length()));
    std::string res;
    for(size_t i(len); i > 0; i--)
    {
        for(size_t j(len); j > 0; j--)
        {
            res += s.at((i - 1) * (len + 1) + (j - 1));
        }
        res += '\n';
    }
    if(res.size() > 0){
        res.pop_back();
    }
    return res;
}

std::string Opstrings1::selfieAndRot(const std::string &s)
{
    int len(sqrt(s.length()));
    std::string res;
    std::string temp1;
    std::string temp2;
    for(size_t i(len); i > 0; i--)
    {
        temp2 += std::string(len, '.');

        for(size_t j(len); j > 0; j--)
        {
            temp1 += s.at((len - i) * (len + 1) + (len - j));
            temp2 += s.at((i - 1) * (len + 1) + (j - 1));
        }
        temp1 += std::string(len, '.');
        temp1 += '\n';

        temp2 += '\n';
    }
    res += temp1;
    res += temp2;
    if(res.size() > 0){
        res.pop_back();
    }
    return res;
}

void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}
template<typename Func>
static void dotest(Func func, std::string s, std::string expected)
{
    testequal(Opstrings1::oper(func, s), expected);
}

void rot_Tests()
{
    std::cout<<"Rot tests"<<std::endl;
    std::string s = "fijuoo\nCqYVct\nDrPmMJ\nerfpBA\nkWjFUG\nCVUfyL";
    std::string sol = "LyfUVC\nGUFjWk\nABpfre\nJMmPrD\ntcVYqC\nooujif";
    dotest(Opstrings1::rot, s, sol);
    s = "rkKv\ncofM\nzXkh\nflCB";
    sol = "BClf\nhkXz\nMfoc\nvKkr";
    dotest(Opstrings1::rot, s, sol);
}
void selfieAndRot_Tests()
{
    std::cout<<"Selfie and Rot"<<std::endl;
    std::string s = "xZBV\njsbS\nJcpN\nfVnP";
    std::string sol = "xZBV....\njsbS....\nJcpN....\nfVnP....\n....PnVf\n....NpcJ\n....Sbsj\n....VBZx";
    dotest(Opstrings1::selfieAndRot, s, sol);
    s = "xZBV\njsbS\nJcpN\nfVnP";
    sol = "xZBV....\njsbS....\nJcpN....\nfVnP....\n....PnVf\n....NpcJ\n....Sbsj\n....VBZx";
    dotest(Opstrings1::selfieAndRot, s, sol);
}

int main(){
    rot_Tests();
    selfieAndRot_Tests();
}