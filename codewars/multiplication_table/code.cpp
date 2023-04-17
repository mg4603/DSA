#include <assert.h>
#include <vector>
#include <iostream>

std::vector<std::vector<int>> multiplication_table(int n){
    std::vector<std::vector<int>> res (n, std::vector<int>(n, 0));
    for(int i(1); i <= n ;i++){
        for(int j(1); j <= n; j++){
            if(res.at(j - 1).at(i - 1) == 0){
                res[i-1][j-1] = i * j;
            }else{
                res[i - 1][j - 1] = res.at(j - 1).at(i - 1);
            }
        }
    }
    return res;
}

int main(){
    std::vector<std::vector<int>> test({{1,2,3},{2,4,6},{3,6,9}});
    
    assert(multiplication_table(3) ==(test));
}