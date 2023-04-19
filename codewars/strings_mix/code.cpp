#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2);
};


void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}
void dotest(const std::string &s1, const std::string &s2, std::string expected)
{
    testequal(Mix::mix(s1, s2), expected);
}
int main(){
    std::string sol = "2:eeeee/2:yy/=:hh/=:rr";
    dotest("Are they here", "yes, they are here", sol);
    sol = "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg";
    dotest("looping is fun but dangerous", "less dangerous than coding", sol);
}


std::string Mix::mix(const std::string &s1, const std::string &s2){
    int s1_chars[26] = {0};
    int s2_chars[26] = {0};
    for(char c: s1){
        if(isalpha(c) && islower(c))
        {    
            s1_chars[c-'a']++;
        }
    }

    for(char c: s2){
        if(isalpha(c) && islower(c))
        {
            s2_chars[c-'a']++;
        }
    }

    std::vector<std::string> res_vec;
    for(size_t i(0); i < 26; i++){
        std::string temp;
        if(s1_chars[i] > s2_chars[i]){
            temp += "1:";
            temp += std::string(s1_chars[i], i + 'a');
        }else if(s1_chars[i] == s2_chars[i]){
            temp += "=:";
            temp += std::string(s1_chars[i], i + 'a');
        }else{
            temp += "2:";
            temp += std::string(s2_chars[i], i + 'a');
        }
        temp += "/";
        res_vec.push_back(temp);
    }
    std::sort(res_vec.begin(), res_vec.end(), [](std::string a, std::string b){
        if(a.length() == b.length()){
            return a.compare(b) < 0;
        }
        return a.length() > b.length();
    });
    std::string res;
    for(std::string str: res_vec){
        if(str.length() > 4)
            res += str;
    }
    if(res.size() != 0)
        res.pop_back();

    return res;

}