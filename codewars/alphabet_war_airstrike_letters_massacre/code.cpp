#include <assert.h>
#include <iostream>

#include <string>
#include <map>

std::string alphabetWar(std::string fight)
{ 
    std::map<char, int> left_map{{'w', 4}, {'p', 3}, {'b', 2}, {'s', 1}};
    std::map<char, int> right_map{{'m', 4}, {'q', 3}, {'d', 2}, {'z', 1}};
    
    int left(0);
    int right(0);
    for(size_t i(0); i < fight.length(); i++){
        if(fight[i] == '*'){
            fight[i] = '_';
            if(i > 0)
            {
                fight[i - 1] = '_';
            }
            if(i < fight.length() - 1 && fight[i + 1] != '*')
            {
                fight[i + 1] = '_';
            }
        }
    }
    for(char c: fight){
        if(left_map.count(c)){
            left += left_map[c];
        }
        else if(right_map.count(c))
        {
            right += right_map[c];
        }
    }

    if(left < right){
        return "Right side wins!";
    }
    else if(right < left)
    {
        return "Left side wins!";
    }
    else
    {
        return "Let's fight again!";
    }
}

int main()
{
    assert(alphabetWar("z") == "Right side wins!");
    assert(alphabetWar("****") == "Let's fight again!");
    assert(alphabetWar("z*dq*mw*pb*s") == "Let's fight again!");
    assert(alphabetWar("zdqmwpbs") == "Let's fight again!");
    assert(alphabetWar("zz*zzs") == "Right side wins!");
    assert(alphabetWar("*wwwwww*z*") == "Left side wins!");
    assert(alphabetWar("*ww*ww*w*wz") == "Right side wins!");
    return 0;
}