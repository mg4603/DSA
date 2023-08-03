#include <assert.h>
#include <iostream>

template <char... C>
struct make_string { 
  static constexpr char value[sizeof...(C) + 1] = {C..., '\0'};
};

template <char... C>
constexpr char make_string<C...>::value[];


int main()
{    
    using Hi = make_string<'H','i'>;
    
    static_assert(Hi::value[0] == 'H' && Hi::value[1] == 'i' && Hi::value[2] == '\0', "");
    // assert(Hi::value == expected);
    return 0;   
}