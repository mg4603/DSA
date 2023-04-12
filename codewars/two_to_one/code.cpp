#include <string>
#include<assert.h>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void dotest(std::string a1, std::string a2, std::string expected)
{
    testequal(TwoToOne::longest(a1, a2), expected);
}

int main(){
    dotest("aretheyhere", "yestheyarehere", "aehrsty");
    dotest("loopingisfunbutdangerous", "lessdangerousthancoding", "abcdefghilnoprstu");
}

std::string TwoToOne::longest(const std::string &s1, const std::string &s2){
    int table[26] = {0};
    for(char c : s1){
        table[tolower(c)-97]++;
    }
    for(char c : s2){
        table[tolower(c)-97]++;
    }
    std::string res = "";
    for(int i(0); i < 26; i++){
        if(table[i] > 0){
            res += ('a' + i);
        }
    }
    return res;
}