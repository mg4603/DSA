#include <string>
#include <vector>
#include <assert.h>
#include <map>
#include <limits>
#include <iostream>

class LongestConsec
{
public:
    static std::string longestConsec(const std::vector<std::string> &strarr, int k);
};


void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void dotest(const std::vector<std::string> arr, int k, std::string expected)
{
    testequal(LongestConsec::longestConsec(arr, k), expected);
}

int main()
{
    std::vector<std::string> arr = {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
    dotest(arr, 2, "abigailtheta");
    arr = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
    dotest(arr, 1, "oocccffuucccjjjkkkjyyyeehh");
    return 0;
};

std::string LongestConsec::longestConsec(const std::vector<std::string> &strarr, int k){
    int strarr_len(strarr.size());
    if(strarr_len == 0 || k > strarr_len || k <= 0)return "";
    std::map<int, std::string> mp;
    for(auto it = strarr.begin(); it != strarr.end() - k + 1; it++){
        std::string temp;

        for(size_t i(0); i < k; i ++)
        {
            temp += *(it + i);
        }    

        if(!mp.count(temp.length())){
            mp[temp.length()] = temp;
        }
    }
    int max(std::numeric_limits<int>::min());
    for(auto it: mp){
        if(it.first > max)max = it.first;
    }
    return mp[max];
}