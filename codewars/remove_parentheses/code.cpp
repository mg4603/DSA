#include <assert.h>
#include <iostream>

#include <string>
#include <utility>
#include <vector>

std::string remove_parentheses(const std::string &str){
    std::string res(str.begin(), str.end());
    size_t pos(0);
    while(true){
        pos = res.find_last_of('(');
        if(pos == std::string::npos){
            break;
        }
        size_t length(res.find_first_of(')', pos) - pos + 1);
        res.erase(pos, length);
    }
    return res;
}

void do_test(const std::string &str, const std::string &expected)
{
    assert(remove_parentheses(str) == expected);
}

int main(){
    for (auto trial : std::vector<std::pair<std::string,std::string>> {
                        {"example(unwanted thing)example", "exampleexample"},
                        {"example(unwanted thing)example", "exampleexample"},
                        {"example (unwanted thing) example", "example  example"},
                        {"a (bc d)e", "a e"},
                        {"a(b(c))", "a"},
                        {"hello example (words(more words) here) something", "hello example  something"},
                        {"(first group) (second group) (third group)", "  "}
    })
    do_test(trial.first, trial.second);
    return 0;
}