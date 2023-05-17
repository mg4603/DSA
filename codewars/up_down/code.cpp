#include <iostream>
#include <assert.h>

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

class UpAndDown
{
public:
    static std::string arrange(const std::string &s);
};

std::string UpAndDown::arrange(const std::string &s)
{
    std::stringstream ss(s);
    std::string token;
    std::vector<std::string> words;

    while(getline(ss, token, ' '))
    {
        words.push_back(token);
    }

    for(size_t i(1); i < words.size(); i += 2)
    {
        if(words[i].size() < words[i - 1].size())
        {

            swap(words[i], words[i - 1]);
        }
        if(i + 1 < words.size() && words[i].size() < words[i + 1].size())
        {
            swap(words[i], words[i + 1]);
        }
    }

    std::string res;
    int idx(0);
    for(auto &word: words)
    {
        if(idx % 2 == 1)
        {
            std::transform(word.begin(), word.end(), word.begin(), toupper);
        }
        else
        {
            std::transform(word.begin(), word.end(), word.begin(), tolower);
        }
        res += word;
        res += ' ';
        idx++;
    }
    if(res.back() == ' ')
    {
        res.pop_back();
    }
    return res;
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void dotest(std::string s, std::string expected)
{
    testequal(UpAndDown::arrange(s), expected);
}
int main()
{
    std::string s = "who hit retaining The That a we taken";
    std::string sol = "who RETAINING hit THAT a THE we TAKEN";
    dotest(s, sol);
    s = "on I came up were so grandmothers";
    sol = "i CAME on WERE up GRANDMOTHERS so";
    dotest(s, sol);
    s = "way the my wall them him";
    sol = "way THE my WALL him THEM";
    dotest(s, sol);
    return 0;
}

