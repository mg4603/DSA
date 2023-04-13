#include<vector>
#include<string>
#include<assert.h>

#define VI std::vector<int>
#define VC std::vector<char>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
    if(iterable.empty()){
        return std::vector<T>();
    }
    T temp;
    std::vector<T> res;
    temp = iterable.at(0);
    res.push_back(temp);
    for(auto item: iterable){
        if(temp != item){
            temp = item;
            res.push_back(temp);
        }
    }
    return res;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
    if(iterable.empty()){
        return std::vector<char>();
    }
    char temp;
    std::vector<char> res;
    temp = iterable.at(0);
    res.push_back(temp);
    for(char c: iterable){
        if(temp != c){
            temp = c;
            res.push_back(temp);
        }
    }
    return res;
}

int main(){
    
    assert(uniqueInOrder("") == VC{});
    assert(uniqueInOrder("AA") == VC{'A'});
    assert(uniqueInOrder("A") == VC{'A'});
    assert(uniqueInOrder("AAAABBBCCDAABBB") == (VC{'A', 'B', 'C', 'D', 'A', 'B'}));
    assert(uniqueInOrder("AADD") == (VC{'A', 'D'}));
    assert(uniqueInOrder("AAD") == (VC{'A', 'D'}));
    assert(uniqueInOrder("ADD") == (VC{'A', 'D'}));
    assert(uniqueInOrder("ABBCcAD") == (VC{'A', 'B', 'C', 'c', 'A', 'D'}));
    assert(uniqueInOrder(VI{1,2,3,3}) == (VI{1,2,3}));
    assert(uniqueInOrder(VC{'a','b','b'}) == (VC{'a','b'}));
    return 0;
}