#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>

class Opstrings3
{
public:
    static std::string diag1Sym(const std::string &s);
    static std::string rot90Clock(const std::string &s);
    static std::string selfieAndDiag1(const std::string &s);
    static std::string oper(std::string f(const std::string &str), const std::string &s);
};

std::string Opstrings3::diag1Sym(const std::string &s){
    std::string res;
    int n(sqrt(s.length()));
    for(size_t i(0); i < n; i++){
        for(size_t j(0); j < n; j++){
            res += s.at((n + 1) * j + i);
        }
        res += '\n';
    }
    if(res.size() > 0)
    {
        res.pop_back();
    }
    return res;
}

std::string Opstrings3::rot90Clock(const std::string &s){
    std::string res;
    int n(sqrt(s.length()));
    for(size_t i(0); i < n; i++)
    {
        for(size_t j(n); j > 0; j--){
            res += s.at((n + 1) * (j - 1) + i);
        }
        res += '\n';
    }
    if(res.size() > 0){
        res.pop_back();
    }
    return res;
}
std::string Opstrings3::selfieAndDiag1(const std::string &s){
    int n(sqrt(s.length()));
    std::string res;
    for(size_t i(0); i < n; i++)
    {
        std::string temp1;
        std::string temp2;
        for(size_t j(0); j < n; j++)
        {
            temp1 += s.at( ( n + 1 ) * i + j);
            temp2 += s.at((n + 1) * j + i);
        }
        res += temp1;
        res += '|';
        res += temp2;
        res += '\n';
    }
    
    if(res.size() > 0){
        res.pop_back();
    }
    return res;
}

std::string Opstrings3::oper(std::string f(const std::string &str), const std::string &s){
    return f(s);
}


void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}

template<typename Func>
static void dotest(Func func, std::string s, std::string expected)
{
    testequal(Opstrings3::oper(func, s), expected);
}

void test_rot90Clock()
{
    std::cout << "Fixed Tests rot90Clock" << std::endl;
    dotest(Opstrings3::rot90Clock, "rgavce\nvGcEKl\ndChZVW\nxNWgXR\niJBYDO\nSdmEKb",
                "Sixdvr\ndJNCGg\nmBWhca\nEYgZEv\nKDXVKc\nbORWle");
}
void test_diag1Sym()
{
    std::cout << "Fixed Tests diag1Sym" << std::endl;
    dotest(Opstrings3::diag1Sym, "wuUyPC\neNHWxw\nehifmi\ntBTlFI\nvWNpdv\nIFkGjZ",
                "weetvI\nuNhBWF\nUHiTNk\nyWflpG\nPxmFdj\nCwiIvZ");
}
void test_selfieAndDiag1()
{
    std::cout << "Fixed Tests selfieAndDiag1" << std::endl;
    dotest(Opstrings3::selfieAndDiag1, "NJVGhr\nMObsvw\ntPhCtl\nsoEnhi\nrtQRLK\nzjliWg",
                "NJVGhr|NMtsrz\nMObsvw|JOPotj\ntPhCtl|VbhEQl\nsoEnhi|GsCnRi\nrtQRLK|hvthLW\nzjliWg|rwliKg");
}

int main()
{
    test_diag1Sym();
    test_rot90Clock();
    test_selfieAndDiag1();
    return 0;
}