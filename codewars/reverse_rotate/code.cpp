#include <assert.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#define ull unsigned long long

class RevRot
{
public:
    static std::string revRot(const std::string &strng, unsigned int sz);
};

void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}
static void dotest(std::string s, unsigned int sz, std::string expected)
{
    testequal(RevRot::revRot(s, sz), expected);
}

int main(){
    std::string s = "1234";
    dotest(s, 0, "");
    s = "";
    dotest(s, 0, "");
    s = "733049910872815764";
    dotest(s, 5, "330479108928157");
    s = "73304991087281576455176044327690580265896";
    dotest(s, 8, "1994033775182780067155464327690480265895");
}

std::string RevRot::revRot(const std::string &strng, unsigned int sz){
    if(sz <= 0 || strng.size() == 0 || sz > strng.size()) return "";

    std::string tail;
    if(strng.size() % sz != 0){
        tail = strng.substr(strng.size() - (strng.size() % sz));
    }
    std::vector<std::string> chunks;
    for(size_t i(0); i < strng.size() - tail.length(); i += sz){
        chunks.push_back(strng.substr(i, sz));
    }
    std::string res;
    for(auto &chunk: chunks){
        ull chunk_sum(std::accumulate(chunk.begin(), chunk.end(), 0, [](ull a, char b){
            int num(b - '0');
            return a + (num * num * num);
        }));
        if(chunk_sum % 2 == 0){
            std::reverse(chunk.begin(), chunk.end());
        }else{
            char a = chunk.at(0);
            chunk.erase(chunk.begin());
            chunk += a;
        }
        res += chunk;
    }
    return res;
}