#include <assert.h>
#include <iostream>

#include <vector>
#define V std::vector<int>

V beggars(const V &values, unsigned int n){
    if(n == 0)
        return {};
    V res(n, 0);
    int beggar(0);
    for(int val: values){
        res[beggar++] += val;
        beggar %= n;
    }
    return res;
}

int main(){
    assert(beggars(V{1,2,3,4,5},1) == (V{15}));
    assert(beggars(V{1,2,3,4,5},2) == (V{9,6}));
    assert(beggars(V{1,2,3,4,5},3) == (V{5,7,3}));
    assert(beggars(V{1,2,3,4,5},6) == (V{1,2,3,4,5,0}));
    assert(beggars(V{1,2,3,4,5},0) == (V{}));
    return 0;
}