#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>
#include <vector>

class Cubes
{
    private:
        static bool isCubic(std::string num);
    public:
        static std::string isSumOfCubes(std::string &str);
};

bool Cubes::isCubic(std::string num)
{
    int n(0);
    for(char c: num)
    {
        n += pow(c - '0', 3);
    }
    if(n == std::stoi(num))
    {
        return true;
    }
    return false;
}

std::string Cubes::isSumOfCubes(std::string &str)
{

    std::string res;
    std::string numbers("0123456789");
    int idx(0);
    int idx1(0);
    int sum(0);
    while(true)
    {
        idx = str.find_first_of(numbers, idx);
        idx1 = str.find_first_not_of(numbers, idx);
        std::string temp;
        if(idx == static_cast<long long>(std::string::npos))
        {
            break;
        }
        else if(idx1 == static_cast<long long>(std::string::npos))
        {
            temp = str.substr(idx);
        }
        else
        {
            temp = str.substr(idx, idx1 - idx);
        }
        int num_grp(0);
        while(num_grp < static_cast<long long>(temp.size()))
        {
            if(temp.size() - num_grp < 3)
            {
                std::string num_str = temp.substr(num_grp);
                if(isCubic(num_str))
                {
                    res += num_str;
                    res += ' ';
                    sum += std::stoi(num_str);
                }
                num_grp = temp.size();
            }
            else
            {
                std::string num_str = temp.substr(num_grp, 3);
                num_grp += 3;
                if(isCubic(num_str))
                {
                    res += std::to_string(std::stoi(num_str));
                    res += ' ';
                    sum += std::stoi(num_str);
                }
            }
        }
        idx = idx1;
    }

    if(res.size() > 0)
    {
        return res + std::to_string(sum) + " Lucky";
    }
    return "Unlucky";
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
static void dotest(std::string &str, std::string expected)
{
    testequal(Cubes::isSumOfCubes(str), expected);
}

int main()
{
    std::string str = "&z _upon 407298a --- ???ry, ww/100 I thought, 631str*ng and w===y -721&()";
    dotest(str, "407 407 Lucky");

    str = "0 9026315 -827&()";
    dotest(str, "0 0 Lucky");
    return 0;
}
