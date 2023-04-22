#include <assert.h>
#include <iostream>
#include <string>
#include <limits>

int solve(const std::string &s){
    int maximum(std::numeric_limits<int>::min());
    std::string vowels("aeiou");

    int sum(0);
    for(const char c: s){
        if(vowels.find(c) != std::string::npos){
            maximum = std::max(maximum, sum);
            sum = 0;
            continue;
        }
        sum += (c - 'a' + 1);
    }
    maximum = std::max(sum, maximum);
    return maximum;
}

int main(){
    assert(solve("zodiac") == 26);
    assert(solve("chruschtschov") == 80);
    assert(solve("khrushchev") == 38);
    assert(solve("strength") == 57);
    assert(solve("catchphrase") == 73);
    assert(solve("twelfthstreet") == 103);
    assert(solve("mischtschenkoana") == 80);
    return 0;
}