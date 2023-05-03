#include <assert.h>
#include <iostream>

#include <string>
#include <vector>

class CaesarCipher{
    public:
        static std::vector<std::string> movingShift(const std::string &s, int shift);
        static std::string demovingShift(std::vector<std::string> &s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string &s, int shift){
    std::string encodedString;
    for(char c: s){
        if(isalpha(c))
        {
            if(isupper(c)){
                encodedString += ((c - 'A' + shift) % 26 + 'A');
            }else{
                encodedString += ((c - 'a' + shift) % 26 + 'a');

            }
        }else{
            encodedString += c;
        }
        shift++;
    }
    int len(0);
    std::vector<std::string> res;

    if (encodedString.length() % 5 == 0){
        len = encodedString.length() / 5;
    }else{
        len = (encodedString.length() / 5) + 1;
    }

    for(size_t i(0); i < encodedString.length(); i += len){
        res.push_back(encodedString.substr(i, len));
    }
    if(res.size() < 5){
        res.push_back(encodedString.substr(len * 4));
    }

    return res;
}

std::string CaesarCipher::demovingShift(std::vector<std::string> &s, int shift){
    std::string res;
    for(std::string str: s){
        res += str;
    }
    for(char &c: res){
        if(isalpha(c))
        {
            if(isupper(c))
            {
                c = (((c - 'A' - shift) % 26 + 26) % 26 + 'A');
            }else
            {   
                c = (((c - 'a' - shift) % 26 + 26) % 26 + 'a');
            }
        }
        shift++;
    }
    return res;
}


void testequal1(std::vector<std::string> ans, std::vector<std::string> sol)
{
    assert(ans == sol);
}
static void dotest1(const std::string &s, int shift, std::vector<std::string> expected)
{
    testequal1(CaesarCipher::movingShift(s, shift), expected);
}

void testequal2(std::string ans, std::string sol)
{
    assert(ans == sol);
}
static void dotest2(std::vector<std::string> &s, int shift, std::string expected)
{
    testequal2(CaesarCipher::demovingShift(s, shift), expected);
}

void testequal3(std::string ans, std::string sol)
{
    assert(ans == sol);
}
static void dotest3(std::string s, int shift)
{
    std::vector<std::string> r = CaesarCipher::movingShift(s, shift);
    testequal3(CaesarCipher::demovingShift(r, shift), s);
}

int main()
{
    std::string  u = "I should have known that you would have a perfect answer for me!!!";
    std::vector<std::string> sol = {"J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"};
    dotest1(u, 1, sol);
    dotest2(sol, 1, u);
    dotest3(u, 1);

    u = "O CAPTAIN! my Captain! our fearful trip is done;";
    dotest3(u, 1);
    return 0;
}