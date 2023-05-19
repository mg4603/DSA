#include <assert.h>
#include <iostream>

#include <string>

namespace process
{
    char reverseChar(char ch, int n)
    {
        int cnt(0);
        char res;
        for(int i(0); i < 26; i ++)
        {
            if((i * n) % 26 == (ch - 'a'))
            {
                res = (i + 'a');
                cnt++;
            }
        }
        if(cnt > 1)
        {
            return 0;
        }
        return res;
    }
    std::string decode(const std::string &r)
    {
        int num(std::stoi(r));
        std::string res;
    
        int start(r.find_first_not_of("0123456789"));
    
        for(int i(start); i < static_cast<int>(r.size()); i++)
        {
            char revChr = reverseChar(r[i], num);
            if(revChr == 0)
            {
                return "Impossible to decode";
            }
            res += revChr;
        }
        return res;
    }
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void testing_decode(std::string r, std::string expect)
{
    testequal(process::decode(r), expect);
}
    
int main()
{
    testing_decode("1273409kuqhkoynvvknsdwljantzkpnmfgf", "uogbucwnddunktsjfanzlurnyxmx");
    testing_decode("1544749cdcizljymhdmvvypyjamowl", "mfmwhbpoudfujjozopaugcb");
    testing_decode("105860ymmgegeeiwaigsqkcaeguicc", "Impossible to decode");
    testing_decode("1122305vvkhrrcsyfkvejxjfvafzwpsdqgp", "rrsxppowmjsrclfljrajtybwviqb");
    testing_decode("7235897srigyvazffyrtxizwgpmvpts", "qfkoexapddefbtkpiojcxjbq");
    return 0;
} 