#include <assert.h>
#include <vector>
#include <string>

int countSmileys(std::vector<std::string> arr){
    int count(0);
    std::vector<char> eyes{':', ';'};
    std::vector<char> nose{'-', '~'};
    std::vector<char> mouth{')', 'D'};
    for(std::string seq: arr){
        if(seq.size() == 2){
            if(
                (seq.at(0) == ':' || seq.at(0) == ';') &&
                (seq.at(1) == ')' || seq.at(1) == 'D')
            )
            count++;
        }else{
            if(
                (seq.at(0) == ':' || seq.at(0) == ';') &&
                (seq.at(1) == '-' || seq.at(1) == '~') &&
                (seq.at(2) == ')' || seq.at(2) == 'D')
            )
            count++;
        }
    }
    return count;
}

int main(){
    assert(countSmileys({}) == 0);
    assert(countSmileys({":D", ":~)", ";~)", ":)"}) == 4);
    assert(countSmileys({":)", ":(", ":D", ":O", ":;"}) == 2);      
    assert(countSmileys({";]", ":[", ";*", ":$", ";-D"}) == 1);   
}