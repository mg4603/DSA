#include <iostream>
#include <assert.h>

#include <map>

std::string numStr(int num)
{
    if(num == 30)
    {
        return "half";
    }

    if(num < 20 && num >= 10)
    {
        std::map<int, std::string> elnin_mp{
            {10, "ten"},
            {11, "eleven"},
            {12, "twelve"},
            {13, "thirteen"},
            {14, "fourteen"},
            {15, "fifteen"},
            {16, "sixteen"},
            {17, "seventeen"},
            {18, "eighteen"},
            {19, "nineteen"},
        };
        return elnin_mp[num];
    }

    std::string res;
    std::map<int, std::string> one_nine{
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
    };
    res = one_nine[num % 10];

    if(num / 10 == 0)
    {
        return res;
    }
    else if(num / 10 == 2)
    {
        if(num % 10 == 0)
            return "twenty";
        return "twenty " + res;
    }
    return "";
}

std::string solve(std::string time){
    int h(stoi(time));
    int m(stoi(time.substr(time.find(":") + 1)));

    if(m == 0)
    {
        switch(h)
        {
            case 12:
                return "twelve o'clock";
            case 0:
            case 24:
                return "midnight";
            default:
                return numStr(h % 12) + " o'clock";
        }
    }

    std::string res;
    if(m > 30)
    {
        h++;
        m = 60 - m;
        switch(m)
        {
            case 15:
                res += "quarter to ";
                break;
            case 1:
                res += "one minute to ";
                break;
            default:
                res += numStr(m) + " minutes to ";
        }
    }
    else
    {
        switch(m)
        {
            case 15:
                res += "quarter past ";
                break;
            case 30:
                res += "half past ";
                break;
            case 1:
                res += "one minute past ";
                break;
            default:
                res += numStr(m) + " minutes past ";
                break;
        }
    }

    switch(h)
    {
        case 12:
            res += "twelve";
            break;
        case 24:
        case 0:
            res += "midnight";
            break;
        default:
            res += numStr(h % 12);
    }

    return res;
}

int main()
{
    std::cout << solve("13:00") << std::endl;
    assert(solve("13:00") == "one o'clock");
    std::cout << solve("13:09") << std::endl;
    assert(solve("13:09") == "nine minutes past one");
    std::cout << solve("13:15") << std::endl;
    assert(solve("13:15") == "quarter past one");
    std::cout << solve("13:29") << std::endl;
    assert(solve("13:29") == "twenty nine minutes past one");
    std::cout << solve("13:30") << std::endl;
    assert(solve("13:30") == "half past one");
    std::cout << solve("13:31") << std::endl;
    assert(solve("13:31") == "twenty nine minutes to two");
    std::cout << solve("13:45") << std::endl;
    assert(solve("13:45") == "quarter to two");
    std::cout << solve("13:59") << std::endl;
    assert(solve("13:59") == "one minute to two");
    std::cout << solve("00:48") << std::endl;
    assert(solve("00:48") == "twelve minutes to one");
    std::cout << solve("00:08") << std::endl;
    assert(solve("00:08") == "eight minutes past midnight");
    std::cout << solve("12:00") << std::endl;
    assert(solve("12:00") == "twelve o'clock");
    std::cout << solve("00:00") << std::endl;
    assert(solve("00:00") == "midnight");
    std::cout << solve("19:01") << std::endl;
    assert(solve("19:01") == "one minute past seven");
    std::cout << solve("07:01") << std::endl;
    assert(solve("07:01") == "one minute past seven");
    std::cout << solve("01:59") << std::endl;
    assert(solve("01:59") == "one minute to two");
    std::cout << solve("12:01") << std::endl;
    assert(solve("12:01") == "one minute past twelve");
    std::cout << solve("00:01") << std::endl;
    assert(solve("00:01") == "one minute past midnight");
    std::cout << solve("11:31") << std::endl;
    assert(solve("11:31") == "twenty nine minutes to twelve");
    std::cout << solve("23:31") << std::endl;
    assert(solve("23:31") == "twenty nine minutes to midnight");
    std::cout << solve("00:01") << std::endl;
    assert(solve("00:01") == "one minute past midnight");
    std::cout << solve("11:45") << std::endl;
    assert(solve("11:45") == "quarter to twelve");
    std::cout << solve("11:59") << std::endl;
    assert(solve("11:59") == "one minute to twelve");
    std::cout << solve("23:45") << std::endl;
    assert(solve("23:45") == "quarter to midnight");
    std::cout << solve("23:59") << std::endl;
    assert(solve("23:59") == "one minute to midnight");
    std::cout << solve("01:45") << std::endl;
    assert(solve("01:45") == "quarter to two");
    std::cout << solve("00:01") << std::endl;
    assert(solve("00:01") == "one minute past midnight");

    return 0;
}