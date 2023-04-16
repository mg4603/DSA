#include<assert.h>
#include <vector>
#include <numeric>
#include <limits>

int maxSequence(const std::vector<int>& arr){
    if(arr.size() == 0){
        return 0;
    }
    std::vector<int> arr_copy(arr);

    int max_val(std::numeric_limits<int>::min());
    for(size_t i(1); i < arr.size(); i++){
        arr_copy[i] = std::max(arr_copy[i], arr_copy[i] + arr_copy[i - 1]);
        max_val = std::max(max_val, arr_copy[i]);
    }
    if(max_val < 0){
        return 0;
    }
    return max_val;
}

int main()
{
    assert(maxSequence({}) == 0);
    assert(maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
};