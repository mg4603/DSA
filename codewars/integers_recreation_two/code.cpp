#include <iostream>
#include <assert.h>

#include <utility>
#include <sstream>

typedef long long lglg;

#include <string>

#include <vector>
#include <algorithm>

#define ll long long

class SqProd2Sum
{
public:
    static std::vector<std::pair <long, long>> prod2Sum(long long a, long long b, long long c, long long d);
};


std::vector<std::pair<long, long>> SqProd2Sum::prod2Sum(ll a, ll b, ll c, ll d)
{
    std::vector<long> possible_sol{abs(a * b - c * d), abs(a*b + c*d), abs(a*c + b*d), abs(a*c - b*d), abs(a*d + b*c), abs(a*d - b*c)};
    std::vector<std::pair<long, long>> sol;
    for(int i(0); i < possible_sol.size(); i++)
    {
        for(int j(0); j < possible_sol.size(); j++)
        {
            if(possible_sol[i] * possible_sol[i] + possible_sol[j] * possible_sol[j] == (a*a + b*b) * (c*c + d*d))
            {
                long first(std::min(possible_sol[i], possible_sol[j]));
                long second(std::max(possible_sol[i], possible_sol[j]));

                if(std::find_if(sol.begin(), sol.end(), [&](const std::pair<long, long>& p){return p.first == first && p.second == second;}) == sol.end())
                    sol.push_back(std::make_pair(first, second));
            }
        }
    }
    sort(sol.begin(), sol.end(), [](std::pair<long, long> a, std::pair<long, long> b)
    {
        return a.first < b.first;
    });
    return sol;
}


std::string str(std::vector<std::pair<long, long>> v) {
  std::stringstream s;
  s << "{";
  for (size_t i = 0; i < v.size(); i += 1) {
    if (i > 0) {
      s << ", ";
    }
    s << "{" << v[i].first << ", " << v[i].second << "}";
  }
  s << "}";
  return s.str();
}

void testequal(std::vector<std::pair <long, long>> ans, std::vector<std::pair <long, long>> sol) {
    assert(str(ans) == str(sol));
}
void dotest(lglg a, lglg b, lglg c, lglg d, std::vector<std::pair <long, long>> expected)
{
    testequal(SqProd2Sum::prod2Sum(a, b, c, d), expected);
}

int main()
{
    dotest(1, 2, 1, 3, {{1, 7}, {5, 5}});
    dotest(2, 3, 4, 5, {{2, 23}, {7, 22}});
    dotest(1, 1, 3, 5, {{2, 8}});
    dotest(1, 2, 2, 3, {{1, 8}, {4, 7}});
    return 0;
}