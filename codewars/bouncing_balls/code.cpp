#include<assert.h>
#include<iostream>

using namespace std;
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};

void testequal(int ans, int sol) {
    assert(ans == sol);
}

int main(){
    testequal(Bouncingball::bouncingBall(3, 0.66, 1.5), 3);
    testequal(Bouncingball::bouncingBall(30, 0.66, 1.5), 15);
    return 0;
};

int Bouncingball::bouncingBall(double h, double bounce, double window){
    if(h <= 0)return -1;
    if(bounce >= 1 || bounce <= 0)return -1;
    if(window >= h)return -1;
    int count(1);
    h *= bounce;
    while(h > window){
        h *= bounce;
        count += 2;
    }
    
    return count;
}