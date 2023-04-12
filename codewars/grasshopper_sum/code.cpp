#include<assert.h>

int summation(int num);

int main(){
    assert(summation(1) == 1);
    assert(summation(8) == 36);
}

int summation(int num){
    int sum(0);
    for(int i(1); i <= num; i ++){
        sum += i;
    }
    return sum;
}