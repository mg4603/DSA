#include <assert.h>
#include <iostream>

#include <sstream>
#include <utility>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>

std::vector<std::pair<int,int>> select_subarray(const std::vector<int> &arr)
{
    double smallestQ(std::numeric_limits<double>::max());
    double sum(std::accumulate(arr.begin(), arr.end(), 0));
    double prod(std::accumulate(arr.begin(), arr.end(), 1, [](double p, int b){return p * b;}));

    std::vector<double> qs;

    for(const int num: arr)
    {
        if(sum - num != 0)
            qs.push_back(std::abs((prod / 1.0 / static_cast<double>(num))/ (sum - static_cast<double>(num))));
        else
            qs.push_back(std::numeric_limits<double>::max());

        if(qs.back() < smallestQ)
        {
            smallestQ = qs.back();
        }
    }

    std::vector<std::pair<int, int>> res;
    for(int i(0); i < static_cast<int>(arr.size()); i++)
    {
        if(qs[i] == smallestQ)
        {
            res.push_back(std::make_pair(i, arr[i]));
        }
    }
    
    return res;
}

std::vector<std::pair<int,int>> select_subarray(const std::vector<int> &arr);

template <typename T, typename U>
static std::string to_string(const std::pair<T,U> &p)
{
    std::stringstream ss;
    ss << '{' << p.first << ',' << p.second << '}'; 
    return ss.str();
}

void do_test(const std::vector<int> &arr, const std::vector<std::pair<int,int>> &expected)
{
    std::vector<std::pair<int,int>> actual = select_subarray(arr);
    if ( actual.size() != expected.size() )
    {
        std::cout << "Element count is wrong\n" << std::endl;
        assert(actual.size() == expected.size());
    }
    for (size_t i = 0; i < actual.size(); i++)
        if ( actual[i] != expected[i] )
        {
            std::cout << "Expected: " << to_string(expected[i]) << '\n'
                 << "Received: " << to_string(actual[i]) << '\n';
            std::cout << "Mismatch at index " << i << std::endl;
            assert(to_string(actual[i]) == to_string(expected[i]));
        }
}

int main()
{
    do_test({1, 23, 2, -8, 5}, {{3, -8}});
    do_test({1, 3, 23, 4, 2, -8, 5, 18}, {{2, 23}});
    return 0;
}