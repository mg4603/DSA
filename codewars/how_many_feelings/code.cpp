#include <assert.h>
#include <iostream>

#include <vector>
#include <map>

std::map<char, int> getCharNum(std::string s)
{
    std::map<char, int> charNums;
    for(char c: s)
    {
        if(!charNums.count(c))
        {
            charNums[c] = 0;
        }
        charNums[c]++;
    }
    return charNums;
}

std::string countFeelings(std::string s, std::vector<std::string> arr)
{
    std::map<char, int> charNums(getCharNum(s));
    int cnt(0);
    for(std::string str: arr)
    {
        std::map<char, int> temp(getCharNum(str));
        int ls(0);
        for(auto ele: temp)
        {
            if(charNums[ele.first] < ele.second)
            {
                break;
            }
            ls++;
        }
        if(ls == temp.size())
        {
            cnt++;
        }
    }

    if(cnt == 1)
    {
        return "1 feeling.";
    }
    return std::to_string(cnt)+" feelings.";
}

int main()
{
    assert(countFeelings("yliausoenvjw", {"anger", "awe", "joy", "love", "grief"}) == "3 feelings.");
    assert(countFeelings("angerw", {"anger", "awe", "joy", "love", "grief"}) == "2 feelings.");
    assert(countFeelings("griefgriefgrief", {"anger", "awe", "joy", "love", "grief"}) == "1 feeling.");
    assert(countFeelings("abcdkasdfvkadf", {"desire", "joy", "shame", "longing", "fear"}) == "0 feelings.");
    assert(countFeelings("abcdkasdfvkadflongin", {"desire", "joy", "shame", "longing", "fear"}) == "0 feelings.");
    return 0;
}