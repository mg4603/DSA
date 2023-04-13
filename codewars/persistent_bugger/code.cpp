#include<assert.h>

int persistence(long long n);

int main(){
    assert(persistence(39) == 3);
    assert(persistence(4) == 0);
    assert(persistence(25) == 2);
    assert(persistence(999) == 4);
    assert(persistence(444) == 3);
    return 0;
}

int persistence(long long n){
    int count(0);
    while(n / 10){
        count++;
        long long temp(1);
        while(n){
            temp *= n % 10;
            n /= 10;
        }
        n = temp;
    }
    return count;
}