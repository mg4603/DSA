#include <assert.h>
#include <iostream>

#include <vector>

bool seen_all_digits(std::vector<unsigned> digits){
    for(size_t i(0); i < digits.size(); i++){
        if(!digits.at(i)){
            return false;
        }
    }
    return true;
}

unsigned integer_depth(unsigned n){
    unsigned depth(1);
    std::vector<unsigned> digits(10, 0);
    while(!seen_all_digits(digits)){
        unsigned prod = depth * n;
        std::cout<<prod<<std::endl;
        while(prod){
            digits[prod % 10] = 1;
            prod /= 10;
        }
        depth++;
    }
    return --depth;
}

int main(){
    assert(integer_depth( 1) == 10);
    assert(integer_depth(42) ==  9);
    assert(integer_depth(125) == 72);
    assert(integer_depth(1234567890) ==  1);
    return 0;
}