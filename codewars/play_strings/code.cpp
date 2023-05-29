#include <assert.h>
#include <iostream>

#include <vector>
#include <string>

std::string work_on_strings(const std::string &a, const std::string &b) {
    std::vector<int> a_chars(26, 0);
    std::vector<int> b_chars(26, 0);
    for(const char c: a)
    {
        a_chars[tolower(c) - 'a']++;
        a_chars[tolower(c) - 'a'] %= 2;
    }
    for(const char c: b)
    {
        b_chars[tolower(c) - 'a']++;
        b_chars[tolower(c) - 'a'] %= 2;

    }
    std::string res;

    for(const char c: a)
    {
        if(b_chars[tolower(c) - 'a'])
        {
            if(isupper(c))
            {
                res += tolower(c);
            }
            else
            {
                res += toupper(c);
            }
        }
        else
        {
            res += c;
        }
    }

    for(const char c: b)
    {
        if(a_chars[tolower(c) - 'a'])
        {
            if(isupper(c))
            {
                res += tolower(c);
            }
            else
            {
                res += toupper(c);
            }
        }
        else
        {
            res += c;
        }
    }
    return res;
}

int main()
{
    assert(work_on_strings("abc","cde") == "abCCde");
    assert(work_on_strings("abcdeFgtrzw", "defgGgfhjkwqe") == "abcDeFGtrzWDEFGgGFhjkWqE");
    assert(work_on_strings("abcdeFg", "defgG") == "abcDEfgDEFGg");
    assert(work_on_strings("abab", "bababa") == "ABABbababa");
    return 0;
};