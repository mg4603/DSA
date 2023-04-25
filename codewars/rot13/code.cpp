#include <assert.h>
#include <iostream>

#include <string>

std::string rot13(std::string msg){
    for(char &c: msg){
        if(isalpha(c)){
            if(islower(c)){
                c -= 'a';
                c += 13;
                c %= 26;
                c += 'a';
            }else{
                c -= 'A';
                c += 13;
                c %= 26;
                c += 'A';
            }
        }
    }
    return msg;
}

int main(){
    assert(rot13("test") == "grfg");
    assert(rot13("Test") == "Grfg");
    assert(rot13("AbCd") == "NoPq");
    return 0;
}