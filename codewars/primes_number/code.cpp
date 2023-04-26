#include <assert.h>
#include <iostream>

#include <vector>
#include <cmath>

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};

std::string PrimeDecomp::factors(int lst){
    unsigned int sqrt_lst = sqrt(lst);
    std::vector<int> sieve(sqrt_lst, 0);
    for(size_t i(2); i < sqrt_lst; i++){
        if(sieve.at(i) == 0){
            for(size_t j(2 * i); j < sqrt_lst; j += i){
                sieve[j] = 1;
            }
        }
    }
    std::vector<int> primes;
    for(size_t i(2); i < sqrt_lst; i++){
        if(sieve.at(i) == 0){
            primes.push_back(i);
        }
    }

    std::string res;
    for(int prime: primes){
        int cnt(0);
        while(lst % prime == 0){
            cnt++;
            lst /= prime;
        }
        if (cnt > 0)
        {    if(cnt == 1){
                res += "(";
                res += std::to_string(prime);
                res += ")";
            }else{
                res += "(";
                res += std::to_string(prime);
                res += "**";
                res += std::to_string(cnt);
                res += ")";
            }
        }
    }
    if(lst != 1)
      res += "(" + std::to_string(lst) + ")";
    return res;
}


void testequal(std::string ans, std::string sol) 
{
    assert(ans == sol);
}

int main()
{
    testequal(PrimeDecomp::factors(7775460), "(2**2)(3**3)(5)(7)(11**2)(17)");
    testequal(PrimeDecomp::factors(7919), "(7919)");
    return 0;
}
