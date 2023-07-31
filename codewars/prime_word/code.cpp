#include <assert.h>
#include <iostream>

#include <vector>
#include <cmath>
#include <string>
#include <utility>

bool is_prime(int num)
{
    if(num <= 2)
    {
        return true;
    }

    for(int i(2); i <= static_cast<int>(sqrt(num)); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

std::vector<int> prime_word(const std::vector<std::pair<std::string, int>> &list){
    std::vector<int> res(list.size(), 0);
    for(int i(0); i < static_cast<int>(list.size()); i++)
    {
        for(int j(0); j < static_cast<int>(list[i].first.size()); j++)
        {
            if(is_prime(static_cast<int>(list[i].first[j]) + list[i].second))
            {
                res[i] = 1;
            }
        }
    }
    return res;
}

int main()
{
    std::vector<int> r1 = {1,1};
    std::vector<int> r2 = {0,1};
    std::vector<int> r3 = {1,1};

    assert(prime_word({{"Emma",30},{"Liam",30}}) == r1);
    assert(prime_word({{"Olivia",20},{"Noah",45}}) == r2);
    assert(prime_word({{"Ava",75},{"William",50}}) == r3);
}