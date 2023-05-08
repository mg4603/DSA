#include <assert.h>
#include <iostream>

#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <limits>

namespace Closest
{
    int weight(int a, char c){
        return a + (c - '0');
    }
    std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string &strng)
    {
        if(strng == ""){
          return {std::make_tuple(0, 0, 0), std::make_tuple(0, 0, 0)};
        }
        std::stringstream ss(strng);
        std::string token;
        std::vector<std::tuple<int, unsigned int, long long>> intermediate_vals;

        unsigned int idx(0);

        while(ss >> token){

            intermediate_vals.push_back(std::make_tuple(
                                        std::accumulate(token.begin(), token.end(), 0, weight)
                                        , idx, std::stoll(token)));            
            idx++;
        }

        sort(intermediate_vals.begin(), intermediate_vals.end(), [](auto tup1, auto tup2){
            if(std::get<0>(tup1) == std::get<0>(tup2)){
                return std::get<1>(tup1) < std::get<1>(tup2);
            }
            return std::get<0>(tup1) < std::get<0>(tup2);
        });
        
        int min(std::numeric_limits<int>::max());
        size_t idx1(0);
        size_t idx2(0);
        for(size_t i(1); i < intermediate_vals.size(); i++){
            if(std::get<0>(intermediate_vals[i]) - std::get<0>(intermediate_vals[i - 1]) < min)
            {
                min = std::get<0>(intermediate_vals[i]) - std::get<0>(intermediate_vals[i - 1]);
                idx1 = i - 1;
                idx2 = i;
            }
        }
        return {intermediate_vals[idx1], intermediate_vals[idx2]};
    }
}

void testequal(std::vector<std::tuple<int, unsigned int, long long>> ans, std::vector<std::tuple<int, unsigned int, long long>> sol) {
    assert(ans == sol);
}

static void dotest(std::string &strng, std::vector<std::tuple<int, unsigned int, long long>> expected)
{
    testequal(Closest::closest(strng), expected);
}

int main()
{
    std::string s = "103 123 4444 99 2000";
    std::tuple<int, unsigned int, long long> e1 = std::make_tuple(2, 4, 2000);
    std::tuple<int, unsigned int, long long> e2 = std::make_tuple(4, 0, 103);
    std::vector<std::tuple<int, unsigned int, long long>> e = {e1, e2};
    dotest(s, e);

    s = "456899 50 11992 176 272293 163 389128 96 290193 85 52";
    e1 = std::make_tuple(13, 9, 85);
    e2 = std::make_tuple(14, 3, 176);
    e = {e1, e2};
    dotest(s, e);

    s = "239382 162 254765 182 485944 134 468751 62 49780 108 54";
    e = {std::make_tuple(8, 5, 134), std::make_tuple(8, 7, 62)};
    dotest(s, e);

    s = "241259 154 155206 194 180502 147 300751 200 406683 37 57";
    e = {std::make_tuple(10, 1, 154), std::make_tuple(10, 9, 37)};
    dotest(s, e);

    s = "89998 187 126159 175 338292 89 39962 145 394230 167 1";
    e = {std::make_tuple(13, 3, 175), std::make_tuple(14, 9, 167)};
    dotest(s, e);
    return 0;
}