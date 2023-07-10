#include <assert.h>
#include <iostream>

#include <map>

template <typename T>
T gcd(T a, T b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

bool hasSubpattern(const std::string& str){
    std::map<char, long long> chMp;
    for(auto ch: str)
    {
        if(chMp.count(ch) == 0)
        {
            chMp[ch] = 0;
        }
        chMp[ch]++;
    }

    long long chGcd(chMp.begin()->second);    
    
    for(auto ele: chMp)
    {
        chGcd = gcd(chGcd, ele.second);
    }

    return chGcd > 1?true:false;
}

int main()
{
    assert(hasSubpattern("a") == false);
    assert(hasSubpattern("aaaa") == true);
    assert(hasSubpattern("abcd") == false);
    assert(hasSubpattern("babababababababa") == true);
    assert(hasSubpattern("bbabbaaabbaaaabb") == true);
    assert(hasSubpattern("123a123a123a") == true);
    assert(hasSubpattern("123A123a123a") == false);
    assert(hasSubpattern("12aa13a21233") == true);
    assert(hasSubpattern("12aa13a21233A") == false);
    assert(hasSubpattern("abcdabcaccd") == false);
    return 0;
}