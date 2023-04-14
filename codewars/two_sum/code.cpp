#include<vector>
#include<assert.h>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    int temp(0);
    
    for(std::size_t i(0); i < numbers.size(); i++){
        temp = target - numbers.at(i);
        for(std::size_t j(i+1); j < numbers.size(); j++){
            if(numbers.at(j) == temp){
                return std::pair<std::size_t, std::size_t>({i, j});
            }
        }
    }
    return {0, 0};
    
}

std::pair<std::size_t, std::size_t> do_test(const std::vector<int>& numbers, int target) {
        auto result = two_sum(numbers, target);
        assert(result.first != result.second);
        assert(numbers[result.first] + numbers[result.second] == (target));
        return result;
}

int main(){
    assert(do_test({1, 2, 3}, 4) == (std::pair<std::size_t, std::size_t>({0, 2})));
    assert(do_test({1234, 5678, 9012}, 14690) == (std::pair<std::size_t, std::size_t>({1, 2})));
    assert(do_test({2, 2, 3}, 4) == (std::pair<std::size_t, std::size_t>({0, 1})));
    return 0;   
}
