#include <iostream>
#include <assert.h>

#include <string>
#include <cmath>

class CodeSqStrings
{
public:
    static std::string code(const std::string &s);
    static std::string decode(const std::string &s);
};

std::string CodeSqStrings::code(const std::string &s)
{
    int n(sqrt(s.size()));
    if(n * n != s.size())
    {
        n++;
    }
    
    int l(n * n);
    std::string new_s(s.begin(), s.end());
    
    for(int i(0); i < l - static_cast<int>(s.size()); i++)
    {
        new_s += '\013';
    }
    
    std::string res;
    for(int i(0); i < n; i++)
    {
        for (int j(0); j < n; j++)
        {
            res += new_s[(n * (n - j - 1)) + i];
        }
        res += '\n';
    }
    if(res.back() == '\n')
    {
        res.pop_back();
    }
    return res;
}

std::string CodeSqStrings::decode(const std::string &s)
{
    std::string new_s;

    for(auto chr: s)
    {
        if(chr != '\n')
        {
            new_s += chr;
        }
    }

    int n(sqrt(new_s.size()));
    std::string res;

    for(int i(0); i < n; i++)
    {
        for(int j(0); j < n; j++)
        {
            res += new_s[(n * j) + (n - i - 1)];
        }
    }
    while(res.back() == '\013')
    {
        res.pop_back();
    }
    return res;
}


void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}

int main()
{
    std::string d = "What do you remember? When I looked at his streaky glasses, I wanted "
    "to leave him. And before that? He stole those cherries for me at midnight. We were walking "
    "in the rain and I loved him. And before that? I saw him coming "
    "toward me that time at the picnic, edgy, foreign.";
    std::string s = "\013ctg?.nadr d gdbW\n\013,i    lnis tl eh\n\013 mtIAakietboaara\n\013eeo nnigsoe st?t\n\013d wsddnh lfls   \n\013gaaa  gtfeoeehWd\n"
    "\013ytrwbI .o rasiho\n\013, d e i rtev,se \n\013 t hflnW h e  ny\n\013fhmioo emot Is o\n\013oeemrvt eshh tIu\n\013r   eehw eaiwr  \n"
    "\013eptc deea tmaelr\n\013iihot  rtc?.naoe\n\013gcamhhre h  tkom\n\013nntiaia meHAeyke\n\013.i ntmiwirend em";
    testequal(CodeSqStrings::code(d), s);
    
    d = "Some say the world will end in fire, Some say in ice. From what I've tasted of desire "
    "I hold with those who favor fire. But if it had to perish twice, I think I know enough of hate"
    " To say that for destruction ice Is also great And would suffice.";
    s = "fa  h ttrheI ilS\nitifakw   s'irdo\nc cotnihftivce m\neAereocaihree,we\n.n   wedroe . i \n\013dIdT , es t Sls\n\013 seoe t.eIaFola\n"
    "\013w s nIo   srm y\n\013oatso  Bwhtoee \n\013ulrautpuhoem nt\n\013lsuyghetold sdh\n\013doc hir  d wa e\n\013  tt niif ohyi \n\013sgihoksfawfa nw\n"
    "\013uroaf h vi ti o\n\013fent I iotd nfr";
    testequal(CodeSqStrings::decode(s), d);
    
    return 0;
};
