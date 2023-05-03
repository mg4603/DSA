#include <iostream>
#include <assert.h>

#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> rotate(const std::string &s){
    std::vector<std::string> res;
    if(s.length() == 0){
        return res;
    }
    std::string s_new(s.begin(), s.end());
    for(size_t i(0); i < s_new.size(); i++){
        std::rotate(s_new.begin(), s_new.begin() + 1, s_new.end());
        res.push_back(s_new);
    }
    return res;
}

void test_Basic_case()
{
	assert(rotate("hello")==
			(std::vector<std::string>{"elloh", "llohe", "lohel", "ohell", "hello"}));
}
void test_Whitespace_case()
{
	assert(rotate(" ")==
			(std::vector<std::string>{" "}));
}
void test_Empty_string()
{
	assert(rotate("")==
			(std::vector<std::string>{}));
}

int main(){
    test_Basic_case();
    test_Whitespace_case();
    test_Empty_string();
    return 0;
}