#include<string>
#include<assert.h>
#include<iostream>

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
static void dotest(std::string s, std::string expected)
{
    testequal(Accumul::accum(s), expected);
}

int main(){
    dotest("ZpglnRxqenU", "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
    dotest("NyffsGeyylB", "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
    return 0;
}

std::string Accumul::accum(const std::string &s){
    std::string res = "";
    for(int i(0); i < s.size(); i++){
        if(i != 0)
            res += '-';
        res += static_cast<char>(toupper(s[i])) + std::string(i, tolower(s[i]));
    }
    return res;
}