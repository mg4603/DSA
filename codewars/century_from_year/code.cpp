#include<assert.h>

int centuryFromYear(int);

int main(){
    assert(centuryFromYear(1705) == 18);
    assert(centuryFromYear(1900) == 19);
    assert(centuryFromYear(1601) == 17);
    assert(centuryFromYear(2000) == 20);
}

int centuryFromYear(int year){
    int res = year / 100;
    if(year % 100 > 0){
        res++;
    }
    return res;
}