#include <assert.h>
#include <iostream>

int lenPalindrome(const std::string &s, int start, int end)
{
    if(start < 0 || end >= s.length())
    {
        return 0;
    }
    while(start >= 0 && end < s.length() && s.at(start) == s.at(end))
    {
        start--;
        end++;
    }
    return end - start - 1;
}

int longest_palindrome(const std::string &s)
{
    int longest(0);
    for(int i(0); i < s.length(); i++)
    {
        longest = std::max(lenPalindrome(s, i, i), longest);
        longest = std::max(lenPalindrome(s, i, i + 1), longest);
    }
    return longest;
}

void doTest(const std::string &s, int expected, bool equals = true)
{
    if ( equals )
        assert(longest_palindrome(s) == expected);
    else
        assert(longest_palindrome(s) != expected);
}

int main()
{
    doTest("a", 1);
    doTest("aa", 2);
    doTest("baa", 2);
    doTest("aab", 2);
    doTest("zyabyz", 6, false);
    doTest("baabcd", 4);
    doTest("baablkj12345432133d", 9);
    doTest("lolollolollolollolol", 20);
    doTest("abcdefghijklmnopqrstuvwxyz lolollolollolollolol", 20);
    return 0;
}