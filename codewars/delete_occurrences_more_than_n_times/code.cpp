#include <assert.h>
#include <vector>
#include <map>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> res;
    std::map<int, size_t> mp;
    for(auto num: arr){
        if(!mp.count(num)){
            mp[num] = 1;
            res.push_back(num);
        }else{
            if(mp.at(num) < n){
                mp[num] ++;
                res.push_back(num);
            }
        }
    }
    return res;
}

int main(){
    assert(deleteNth({20,37,20,21}, 1) == std::vector<int>({20, 37, 21}));
    assert(deleteNth({1,1,3,3,7,2,2,2,2}, 3) == std::vector<int>({1, 1, 3, 3, 7, 2, 2, 2}));
    return 0;
}