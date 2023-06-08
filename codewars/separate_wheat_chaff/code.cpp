#include <assert.h>
#include <iostream>

#include <vector>

using namespace std ; 
using vec = vector <long long int> ;

std::vector <long long int> wheatFromChaff (std::vector <long long int> values)
{
    int lo(0);
    int hi(values.size() - 1);
    while( lo < hi)
    {
        while(lo < hi && values[hi] > 0)
        {
            hi--;
        }
        if(values[lo] > 0)
        {
            swap(values[lo], values[hi]);
        }
        else
        {
            lo++;
        }
    }
    return values;
}


void check_Short_length_Vectors(){
    assert(wheatFromChaff(vec({2,-4,6,-6})) == vec({-6,-4,6,2}));
    assert(wheatFromChaff(vec({7,-3,-10})) == vec({-10,-3,7}));
    assert(wheatFromChaff(vec({7,-8,1,-2}))== vec({-2,-8,1,7}));
    assert(wheatFromChaff(vec({8,10,-6,-7,9}))== vec({-7,-6,10,8,9}));
    assert(wheatFromChaff(vec({-3,4,-10,2,-6}))== vec({-3,-6,-10,2,4}));
    assert(wheatFromChaff(vec({2,-6,-4,1,-8,-2}))== vec({-2,-6,-4,-8,1,2}));
}
void check_Medium_length_Vectors(){
    assert(wheatFromChaff(vec({16,25,-48,-47,-37,41,-2}))== vec({-2,-37,-48,-47,25,41,16}));
    assert(wheatFromChaff(vec({-30,-11,36,38,34,-5,-50}))== vec({-30,-11,-50,-5,34,38,36}));
    assert(wheatFromChaff(vec({-31,-5,11,-42,-22,-46,-4,-28}))== vec({-31,-5,-28,-42,-22,-46,-4,11}));
    assert(wheatFromChaff(vec({46,39,-45,-2,-5,-6,-17,-32,17}))== vec({-32,-17,-45,-2,-5,-6,39,46,17}));
    assert(wheatFromChaff(vec({-9,-8,-6,-46,1,-19,44}))== vec({-9,-8,-6,-46,-19,1,44}));
    assert(wheatFromChaff(vec({-37,-10,-42,19,-31,-40,-45,33}))== vec({-37,-10,-42,-45,-31,-40,19,33}));
    assert(wheatFromChaff(vec({-25,-48,-29,-25,1,49,-32,-19,-46,1}))== vec({-25,-48,-29,-25,-46,-19,-32,49,1,1}));
}
void check_lengthy_Vectors(){
    assert(wheatFromChaff(vec({-7,-35,-46,-22,46,43,-44,-14,34,-5,-26}))== vec({-7,-35,-46,-22,-26,-5,-44,-14,34,43,46}));
    assert(wheatFromChaff(vec({-46,-50,-28,-45,-27,-40,10,35,34,47,-46,-24}))== vec({-46,-50,-28,-45,-27,-40,-24,-46,34,47,35,10}));
    assert(wheatFromChaff(vec({-33,-14,16,31,4,41,-10,-3,-21,-12,-45,41,-19}))== vec({-33,-14,-19,-45,-12,-21,-10,-3,41,4,31,41,16}));
    assert(wheatFromChaff(vec({-17,7,-12,10,4,-8,-19,-24,40,31,-29,21,-45,1}))== vec({-17,-45,-12,-29,-24,-8,-19,4,40,31,10,21,7,1}));
    assert(wheatFromChaff(vec({-16,44,-7,-31,9,-43,-44,-18,50,39,-46,-24,3,-34,-27}))== vec({-16,-27,-7,-31,-34,-43,-44,-18,-24,-46,39,50,3,9,44}));
}
void check_Edge_Negatives(){
    assert(wheatFromChaff(vec({-22,-20,-32}))== vec({-22,-20,-32}));
    assert(wheatFromChaff(vec({-46,-3,-15,-5}))== vec({-46,-3,-15,-5}));
    assert(wheatFromChaff(vec({-46,-17,-48,-5,-21}))== vec({-46,-17,-48,-5,-21}));
    assert(wheatFromChaff(vec({-38,-46,-19,-50,-3,-6}))== vec({-38,-46,-19,-50,-3,-6}));
    assert(wheatFromChaff(vec({-43,-39,-3,-48,-26,-8,-11}))== vec({-43,-39,-3,-48,-26,-8,-11}));
    assert(wheatFromChaff(vec({-16,-3,-26,-33,-3,-31,-6,-14}))== vec({-16,-3,-26,-33,-3,-31,-6,-14}));
    assert(wheatFromChaff(vec({-45,-40,-22,-4,-39,-50,-20,-20}))== vec({-45,-40,-22,-4,-39,-50,-20,-20}));
    assert(wheatFromChaff(vec({-47,-10,-21,-16,-9,-10,-12,-35,-12,-44}))== vec({-47,-10,-21,-16,-9,-10,-12,-35,-12,-44}));
    assert(wheatFromChaff(vec({-14,-5,-10,-39,-15,-12,-50,-3,-34,-15,-48}))== vec({-14,-5,-10,-39,-15,-12,-50,-3,-34,-15,-48}));
    assert(wheatFromChaff(vec({-20,-30,-26,-14,-15,-30,-44,-38,-35,-38,-10,-44}))== vec({-20,-30,-26,-14,-15,-30,-44,-38,-35,-38,-10,-44}));
    assert(wheatFromChaff(vec({-15,-45,-23,-2,-35,-37,-24,-13,-19,-6,-26,-11,-34}))== vec({-15,-45,-23,-2,-35,-37,-24,-13,-19,-6,-26,-11,-34}));
}
void check_Edge_Positives(){
    assert(wheatFromChaff(vec({9,9,20}))== vec({9,9,20}));
    assert(wheatFromChaff(vec({34,17,37,45}))== vec({34,17,37,45}));
    assert(wheatFromChaff(vec({18,9,27,45,35}))== vec({18,9,27,45,35}));
    assert(wheatFromChaff(vec({3,6,24,46,42,18}))== vec({3,6,24,46,42,18}));
    assert(wheatFromChaff(vec({22,43,50,38,33,1,36}))== vec({22,43,50,38,33,1,36}));
    assert(wheatFromChaff(vec({2,34,48,19,20,16,5,45}))== vec({2,34,48,19,20,16,5,45}));
    assert(wheatFromChaff(vec({50,16,39,11,16,50,6,36,25}))== vec({50,16,39,11,16,50,6,36,25}));
    assert(wheatFromChaff(vec({21,22,9,3,7,26,13,26,25,15}))== vec({21,22,9,3,7,26,13,26,25,15}));
    assert(wheatFromChaff(vec({31,22,24,25,17,12,11,14,38,15,22}))== vec({31,22,24,25,17,12,11,14,38,15,22}));
    assert(wheatFromChaff(vec({24,4,48,15,25,5,5,10,32,37,37,11}))== vec({24,4,48,15,25,5,5,10,32,37,37,11}));
    assert(wheatFromChaff(vec({49,10,5,40,26,17,25,24,30,34,13,36,21}))== vec({49,10,5,40,26,17,25,24,30,34,13,36,21}));
    assert(wheatFromChaff(vec({28,44,44,41,24,50,28,27,50,1,25,34,11,45}))== vec({28,44,44,41,24,50,28,27,50,1,25,34,11,45}));
}

int main()
{
    check_Edge_Negatives();
    check_Edge_Positives();
    check_Short_length_Vectors();
    check_Medium_length_Vectors();
    check_lengthy_Vectors();
}