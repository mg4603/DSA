#include <vector>
#include <assert.h>
#include<iostream>

typedef unsigned long long ull;

class ProdFib{
    public:
        static std::vector<ull> productFib(ull prod);
};

void testequal(std::vector<ull> ans, std::vector<ull> sol)
{
    assert(ans == sol);
}

void dotest(ull prod, std::vector<ull> expected)
{
    testequal(ProdFib::productFib(prod), expected);
}

int main()
{
    dotest(4895, {55, 89, true});
    dotest(5895, {89, 144, false});
    dotest(74049690, {6765, 10946, 1ULL});
    dotest(84049690, {10946, 17711, 0ULL});
}

std::vector<ull> ProdFib::productFib(ull prod){
    std::vector<ull> fibSequence = std::vector<ull>();
    fibSequence.push_back(0);
    fibSequence.push_back(1);
    auto end = fibSequence.end();
    while(*(end - 1) * *(end - 2) < prod){
        fibSequence.push_back(*(end - 1) + * (end - 2));
        end = fibSequence.end();
    }
    
    if(*(end - 1) * *(end - 2) == prod){
        return {*(end - 2), *(end - 1), true};
    }
    return {*(end - 2), *(end - 1), false};
}