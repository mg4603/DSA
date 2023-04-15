#include <vector>
#include<assert.h>
#include<numeric>
#include<iostream>

int find_even_index(const std::vector<int> numbers){
    int left(0), right(0);

    for(auto it = numbers.begin(); it != numbers.end(); it++){
        left = std::accumulate(numbers.begin(), it, 0);
        right = std::accumulate(it + 1, numbers.end(), 0);
        if(left == right)return it - numbers.begin();
    }
    return -1;
}

int main(){
    
    std::vector <int> numbers = { 1,2,3,4,3,2,1 };
    int expected = 3;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { 1,100,50,-51,1,1 };
    expected = 1;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { 1,2,3,4,5,6 };
    expected = -1;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { 20,10,30,10,10,15,35 };
    expected = 3;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { 20,10,-80,10,10,15,35 };
    expected = 0;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { 10,-80,10,10,15,35,20 };
    expected = 6;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { 0,0,0,0,0 };
    expected = 0;
    assert(find_even_index (numbers) == (expected));
    
    
    
    numbers = { -1,-2,-3,-4,-3,-2,-1 };
    expected = 3;
    assert(find_even_index (numbers) == (expected));
    
    
};
