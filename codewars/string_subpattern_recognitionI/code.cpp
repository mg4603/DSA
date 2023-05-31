#include <assert.h>
#include <iostream>

#include <string>

bool hasSubpattern(const std::string& str){
    for(int cnt(1); cnt <= str.length() / 2; cnt++)
    {
        bool flag(true);

        std::string temp(str.substr(0, cnt));
        for(int i(cnt); i < str.length(); i += cnt)
        {
            if(str.substr(i, cnt) != temp)
            {
                flag = false;
                break;
            }
        }


        if(flag)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    assert(hasSubpattern("a") == false);
    assert(hasSubpattern("aaaa") == true);
    assert(hasSubpattern("abcd") == false);
    assert(hasSubpattern("abababab") == true);
    assert(hasSubpattern("ababababa") == false);
    assert(hasSubpattern("123a123a123a") == true);
    assert(hasSubpattern("123A123a123a") == false);
    assert(hasSubpattern("abbaabbaabba") == true);
    assert(hasSubpattern("abbabbabba") == false);
    assert(hasSubpattern("abcdabcabcd") == false);
    assert(hasSubpattern("asdfasdf") == true);
    return 0;
}