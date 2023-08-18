#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        if(s == t)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    assert(sol.isAnagram("anagram", "nagaram") == true);
    assert(sol.isAnagram("rat", "car") == false);
    return 0;
}