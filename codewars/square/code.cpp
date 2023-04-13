#include<assert.h>
#include<cmath>

bool is_square(int n);

int main(){
    assert(is_square(-1) == false);
    assert(is_square(0) == true);
    assert(is_square(3) == false);
    assert(is_square(4) == true);
    assert(is_square(25) == true);
    assert(is_square(26) == false);
    return 0;
}

bool is_square(int n){
    double square_root = std::sqrt(n);
    if(std::floor(square_root) == square_root){
        return true;
    }
    return false;
}