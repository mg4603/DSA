#include<assert.h>
#include <string>
#include<iostream>

std::string alphabet_position(const std::string &text) {
    std::string res = "";
    for(char c: text){
        if(isalpha(c)){
            if(isupper(c))
                res.append(std::to_string(c - 'A' + 1));
            else
                res.append(std::to_string(c - 'a' + 1));
            res.append(" ");
        }
    }
    return res.substr(0, res.size() - 1);
}

int main(){
    assert(alphabet_position("The sunset sets at twelve o' clock.") == "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11");
    assert(alphabet_position("The narwhal bacons at midnight.") == "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20");
    assert(alphabet_position("0123456789") == "");
    assert(alphabet_position(",./<>?-_=+ ") == "");
    assert(alphabet_position("") == "");
    return 0;
}