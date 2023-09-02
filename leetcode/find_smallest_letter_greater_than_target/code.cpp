#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int i(0);
        std::sort(letters.begin(), letters.end());
        while(i < letters.size() && letters[i] <= target)
        {
            i++;
        }
        if(i == letters.size())
        {
            return letters[0];
        }
        return letters[i];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<char> letters = {'c','f','j'};
        assert(sol.nextGreatestLetter(letters, 'a') == 'c');
    }
    {
        std::vector<char> letters = {'c','f','j'};
        assert(sol.nextGreatestLetter(letters, 'c') == 'f');
    }
    {
        std::vector<char> letters = {'x','x','y','y'};
        assert(sol.nextGreatestLetter(letters, 'z') == 'x');
    }
    return 0;
}