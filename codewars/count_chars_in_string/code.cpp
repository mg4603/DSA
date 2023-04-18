#include <assert.h>
#include <map>
#include <string>

std::map<char, unsigned> count(const std::string &str){
    std::map<char, unsigned> mp;
    for(char c: str){
        mp[c]++;
    }
    return mp;
}

int main(){
    using m = std::map<char, unsigned>;
    assert(count("aba") == (m{{ 'a', 2 }, { 'b', 1 }}));
    assert(count("") == (m{}));
    return 0;
}