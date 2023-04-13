#include<vector>
#include<assert.h>
#include<map>

float find_uniq(const std::vector<float> &v);

int main(){
    assert(find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1}) == 2.f);
    assert(find_uniq(std::vector<float>{ 0, 0, 0.55, 0, 0 }) == 0.55f);
    assert(find_uniq(
            std::vector<float>{
                999.666,  999.666, 999.666, 999.666, 999.666, 999.666, 999.666, 999, 999.666
            }) == 999.f);
}

float find_uniq(const std::vector<float> &v){
    std::map<float, int> mp;
    for(float f: v){
        mp[f]++;
    }
    for(auto const &x: mp){
        if(x.second == 1){
            return x.first;
        }
    }
    return 0.0f;
}