#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>

struct less{
    bool operator ()(std::string a, std::string b) const
    {
        int n(std::min(static_cast<int>(a.size()), static_cast<int>(b.size())));
        int i(0);
        while(i < n)
        {
            if(a[i] != b[i])return a[i] < b[i];
            i++;
        }
        return a.size() < b.size();
    }
};

class Dinglemouse
{
    static std::string numToString(int num);
public:
    static std::vector<int> sort(const std::vector<int> &array);
};

std::string Dinglemouse::numToString(int num)
{
        if(num == 0)
        {
            return "zero";
        }
    int hundreds(num / 100);
    num %= 100;
    int tens(num / 10);
    num %= 10;
    
    std::map<int, std::string> numMp{
        {1, "one"}, {2, "two"}, {3, "three"}, 
        {4, "four"}, {5, "five"}, {6, "six"}, 
        {7, "seven"}, {8, "eight"}, {9, "nine"}, 
        {0, ""}
    };
    std::map<int, std::string> tensMp{
        {2, "twenty"}, {3, "thirty"}, {4, "forty"}, {5, "fifty"}, 
        {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"},
        {0, ""}
    };

    std::map<int, std::string> elevenNineteenMp{
        {1, "eleven"}, {2, "twelve"}, {3, "thirteen"}, {4, "fourteen"}, 
        {5, "fifteen"}, {6, "sixteen"}, {7, "seventeen"}, {8, "eighteen"},
        {9, "nineteen"}, {0, "ten"},
    };

    std::string res;

    res += numMp[hundreds];
    if(hundreds != 0)
    {
        res += " hundred and ";
    }

    if(tens != 1)
    {
        res += tensMp[tens];
        if(tens != 0)
            res += " ";
        res += numMp[num];
    }
    else
    {
        res += elevenNineteenMp[num];
    }

    return res;
}

std::vector<int> Dinglemouse::sort(const std::vector<int> &array)
{
    std::map<std::string, std::pair<int, int>> arMp;
    for(auto elem: array)
    {
        std::string temp(numToString(elem));
        if(!arMp.count(temp))
        {
            arMp[temp] = std::make_pair(elem, 0);
        }
        arMp[temp].second++;
    }


    std::vector<int> res;

    for(auto mpEle: arMp)
    {
        while(mpEle.second.second--)
        {
            res.push_back(mpEle.second.first);
        }
    }
    return res;
}


void doTest(const std::vector<int> &expected, const std::vector<int> &array);


int main()
{
    doTest({8, 8, 9, 9, 10, 10}, {8, 8, 9, 9, 10, 10});
    doTest({4, 1, 3, 2}, {1, 2, 3, 4});
    doTest({9, 999, 99}, {9, 99, 999});
    doTest({ 8, 18, 11, 15, 5, 4, 14, 9, 19, 1, 7, 17, 6, 16, 10, 13, 3, 12, 20, 2, 0}, {8, 5, 4, 9, 1, 7, 6, 3, 2, 18, 11, 15, 14, 19, 17, 16, 10, 13, 12, 20, 0});
    doTest({ 855, 513, 46, 495, 991, 116, 165, 620, 280, 231}, { 855, 513, 495, 46, 991, 116, 165, 620, 280, 231 });
}

void doTest(const std::vector<int> &expected, const std::vector<int> &array)
{
    assert(Dinglemouse::sort(array) == expected);
}