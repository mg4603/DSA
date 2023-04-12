#include<assert.h>
#include<cmath>

long int findNextSquare(long int);

int main(){
    assert(findNextSquare(121) == 144);
    assert(findNextSquare(625) == 676);
    assert(findNextSquare(319225) == 320356);
    assert(findNextSquare(15241383936) == 15241630849);
    assert(findNextSquare(155) == -1);
}

long int findNextSquare(long int num){
    double root = sqrt(num);

    if(root != floor(root)){
        return -1;
    }else{
        return pow((root + 1), 2);
    }
    

}