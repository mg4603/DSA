#include<assert.h>
#include<string>
#include<unordered_map>
#include<iostream>
size_t duplicateCount(const std::string &in);

int main(){
    assert(duplicateCount(" ") == 0);
    assert(duplicateCount("") == 0);
    assert(duplicateCount("asdfghjkl;'\\") == 0);
    assert(duplicateCount("asdfghjkl;'\\'") == 1);
    assert(duplicateCount("aabbcde") == 2);
    assert(duplicateCount("aabBcde") == 2);
    assert(duplicateCount("Indivisibility") == 1);
    assert(duplicateCount("Indivisibilities") == 2);
    assert(duplicateCount("ABBA") == 2);
    return 0;
}

size_t duplicateCount(const std::string & in){
    std::unordered_map<char, int> table;
    for(char c: in){
        table[tolower(c)]++;
    }
    // if in is a char* array
    // strlen is a cstring fn
    /*
    for(int i(0); i < std::strlen(in); i++){
        table[tolower(in[i])]++;
    }
    */
    size_t count(0);
    for(auto x: table){
        if(x.second > 1)
            count++;
    }
    return count;
    
}