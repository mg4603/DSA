#include<assert.h>
#include<string>

std::string get_middle(const std::string &s){
    int size = s.size();
    if(size % 2 == 0){
        return s.substr(size / 2 - 1, 2);
    }else{
        return s.substr(size / 2, 1);
    }
}

int main(){
    assert(get_middle("test") == "es");
    assert(get_middle("testing") == "t");
}