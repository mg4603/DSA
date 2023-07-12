#include <iostream>

int main()
{
    // literals:
    //      * quoted         :
    //                          * chars   : 'c'
    //                          * strings : "Hello"
    //      * integers       : suffix integral type literal values with 
    //                         specified suffix
    //                          * unsigned           : U
    //                          * unsigned long      : UL
    //                          * unsigned long long : ULL
    //      * floating point : suffix floating point type literal values with
    //                         specified suffix
    //                          * float       : F 
    //                          * double      : nothing 
    //                          * long double : L
    //
    // Why you might want to specify type of literal:
    //      * when using auto:
    //              * type of variable is determined by literal assigned to it
    //              * can't reassign variable with literal of different type
    // 
    std::cout << "Literals" << std::endl;
    auto x = 5U;
    // x = "string"; // won't work
    auto y = 6.0F;
    return 0;
}