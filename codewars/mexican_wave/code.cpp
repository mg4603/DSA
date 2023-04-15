#include<assert.h>
#include<string>
#include<vector>
#include<iostream>

std::vector<std::string> wave(std::string y){
    std::vector<std::string> res;
    std::string upper_str = "";
    for(char c: y){
        upper_str += toupper(c);
    }
    for(size_t i(0); i < y.length(); i++){
        std::string temp = "";
        if(y.at(i) == ' '){
            temp += " ";
            continue;
        }
        for(size_t j(0); j < y.length(); j++){
            if(j == i){
                temp += upper_str.at(i);
            }else{
                temp += y.at(j);
            }
        }
        res.push_back(temp);
    }

    /*
    for(auto it = y.begin(); it != y.end(); it++){
        if(isalpha(*it)){
            *it = toupper(*it);
            res.push_back(y);
            *it = tolower(*it);
        }
    }
    */
    return res;
}

int main(){
    assert(wave("hello") == (std::vector<std::string> {"Hello", "hEllo", "heLlo", "helLo", "hellO"}));
    assert(wave("codewars") == (std::vector<std::string> {"Codewars", "cOdewars", "coDewars", "codEwars", "codeWars", "codewArs", "codewaRs", "codewarS"}));
    assert(wave("") == (std::vector<std::string> {}));
    assert(wave("two words") == (std::vector<std::string> {"Two words", "tWo words", "twO words", "two Words", "two wOrds", "two woRds", "two worDs", "two wordS"}));
    assert(wave(" gap ") == (std::vector<std::string> {" Gap ", " gAp ", " gaP "}));
    return 0;
}