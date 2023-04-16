#include <assert.h>
#include <string>
#include <iostream>

std::string incrementString(const std::string &str)
{
    if(str.size() == 0){
        return "1";
    }
    std::string num;
    size_t non_num_idx_end(0);
    for(int i(str.size() - 1); i >= 0; i--){
        if(std::isdigit(str.at(i))){
            num = str.at(i) + num;
            non_num_idx_end = i;
        }else{
            non_num_idx_end = i;
            break;
        }
    }
    
    int num_int(0);
    if(num.size() == 0){
        num = "1";
    }else{
        num_int = stoi(num);
        num_int++;
        size_t num_of_digits(num.size());
        num = std::to_string(num_int);
        while(num.size() < num_of_digits){
            num = '0' + num;
        }
        if(num.size() == str.size()){
          return num;
        }
    }
    return str.substr(0, non_num_idx_end + 1) + num;
}

int main(){

    assert(incrementString("foobar000") == "foobar001");
    assert(incrementString("foo") == "foo1");
    assert(incrementString("foobar001") == "foobar002");
    assert(incrementString("foobar99") == "foobar100");
    assert(incrementString("foobar099") == "foobar100");
    assert(incrementString("") == "1");
    
}