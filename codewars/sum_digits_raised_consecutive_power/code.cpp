#include <string>
#include <vector>
#include<assert.h>
#include<cmath>

unsigned int sumOfSquareOfConsecutiveDigits(unsigned int num){
    unsigned int sum(0);
    unsigned int digits(floor(log10(num) + 1));
    while(num){
        sum += pow(num % 10, digits--);
        num /= 10;
    }
    return sum;
}

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b) {
  //your code here
  std::vector<unsigned int> res = std::vector<unsigned int>();
  for(unsigned int i(a); i <= b; i++){
    if(sumOfSquareOfConsecutiveDigits(i) == i){
        res.push_back(i);
    }
  }
  return res;
}

int main(){
        unsigned int a =  1, 
                     b = 10;
        std::vector<unsigned int> result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert(sumDigPow(a, b)== result);
        a =  1, b = 100, result = {1, 2, 3, 4, 5, 6, 7, 8, 9, 89};
        assert(sumDigPow(a, b)== result);
        a = 10, b = 100, result = {89};
        assert(sumDigPow(a, b)== result);
        a = 90, b = 100, result = {};
        assert(sumDigPow(a, b)== result);
        a = 90, b = 150, result = {135};
        assert(sumDigPow(a, b)== result);
        a = 50, b = 150, result = {89, 135};
        assert(sumDigPow(a, b)== result);
        a = 10, b = 150, result = {89, 135};
        assert(sumDigPow(a, b)== result);
        return 0;
}