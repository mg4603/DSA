#include <assert.h>
#include <iostream>

#include <cstdint>
#include <string>
#include <sstream>
#include <cmath>


uint32_t ip_to_int32(const std::string& ip) {

    std::stringstream ss(ip);
    std::string token;

    int order(3);
    uint32_t int32Rep(0);

    while(getline(ss, token, '.'))
    {
        std::cout<<pow(256, order) * stoi(token)<<std::endl;;
        int32Rep += pow(256, order--) * stoi(token);
    }
    std::cout<<int32Rep<<std::endl;
    return int32Rep;
} 

int main()
{
    assert(ip_to_int32("128.32.10.1") == 2149583361);
}