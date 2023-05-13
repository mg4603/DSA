#include <assert.h>
#include <iostream>

#include <string>

std::string catMouse(std::string field, unsigned int jump){
    size_t c = field.find('C');
    size_t d = field.find('D');
    size_t m = field.find('m');

    if(c == std::string::npos || d == std::string::npos || m == std::string::npos)
    {   
        return "boring without all three";
    }

    if(abs(c - m) - 1 > jump)
    {
        return "Escaped!";
    }
    
    // dog is between
    if((d < m && d > c) || (d < c && d > m))
    {
        return "Protected!";
    }
    
    return "Caught!";
}

int main()
{
    assert(catMouse("..D.....Cm", 13) == "Caught!");
    assert(catMouse("............C.............D..m...", 8) == "Escaped!");
    assert(catMouse("m.C...", 5) == "boring without all three");
    assert(catMouse(".CD......m.", 10) == "Protected!");
    assert(catMouse("..D.....C.m", 2) == "Caught!");
    return 0;
}