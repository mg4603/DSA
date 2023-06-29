#include <assert.h>
#include <iostream>

#include <vector>

std::vector<std::string> find_max_range(const std::vector<std::string> &ranges)
{
    std::vector<double> temp;
    std::vector<std::string> res;

    double maximum(0);

    for(const std::string range: ranges)
    {
        double temp1(std::abs(std::stod(range.substr(4)) - std::stod(range.substr(range.find("to") + 2))));
        temp.push_back(temp1);
        if(temp1 > maximum)
        {
            maximum = temp1;
        }
    }

    for(size_t i(0); i < ranges.size(); i++)
    {
        if(temp[i] == maximum)
        {
            res.push_back(ranges[i]);
        }
    }

    return res;
}

std::string to_string(const std::vector<std::string> &v);
void doTest(const std::vector<std::string> &ranges, const std::vector<std::string> &expected);

int main()
{
    doTest({"from 1 to 3","from 2 to 6","from -100 to 0"}, {"from -100 to 0"});
    doTest({"from 1 to 3","from 2 to 4","from 1 to 1"}, {"from 1 to 3","from 2 to 4"});
    doTest({"from 1 to 10","from 10 to 1","from -1 to -10"}, {"from 1 to 10","from 10 to 1","from -1 to -10"});
    doTest({"from 1 to 10","from 10.1 to 1","from -1 to -10"}, {"from 10.1 to 1"});
    doTest({}, {});
    return 0;
}

void doTest(const std::vector<std::string> &ranges, const std::vector<std::string> &expected)
{
    std::vector<std::string> actual = find_max_range(ranges);
    assert(to_string(actual) == to_string(expected));
}

std::string to_string(const std::vector<std::string> &v)
{
    std::string s = "{";
    for (auto x : v) s += "\"" + x + "\",";
    if ( 1 < s.size() ) s.pop_back();
    return s + "}";
}
