#include<assert.h>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

std::string highAndLow(const std::string &);

int main(){
    assert(highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4") == "42 -9");
    assert(highAndLow("1 2 3") == "3 1");
    return 0;
}

std::string highAndLow(const std::string & seq){
    std::stringstream ss(seq);
    std::vector<int> temp = std::vector<int>();
    std::string num;
    while(ss >> num){
        temp.push_back(std::stoi(num));
    }
    std::string res = "";
    std::sort(temp.begin(), temp.end());


    res += std::to_string(temp[temp.size() - 1]);
    res += ' ';
    res += std::to_string(temp[0]);
    
    return res;
}