#include<vector>
#include<assert.h>
using namespace std;

bool isValidWalk(vector<char> V){
    int up_down(0);
    int left_right(0);
    if(V.size() != 10){
        return false;
    }
    for(char a: V){
        if(a == 'n'){
            up_down += 1;
        }else if(a == 's'){
            up_down -= 1;
        }else if(a == 'e'){
            left_right -= 1;
        }else if(a == 'w'){
            left_right += 1;
        }
    }
    if(left_right == 0 && up_down == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    using V = vector<char>;
    assert(isValidWalk(V{'n'}) == false);
    assert(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s'}) == true);
    assert(isValidWalk(V{'n','s'}) == false);
    assert(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s','n','s'}) == false);
    assert(isValidWalk(V{'e','w','e','w','n','s','n','s','e','w'}) == true);
    assert(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}) == false);
    assert(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s'}) == true);
    assert(isValidWalk(V{'s','e','w','n','n','s','e','w','n','s'}) == true);
    assert(isValidWalk(V{'n','s','n','s','n','s','n','s','n','n'}) == false);
    assert(isValidWalk(V{'e','e','e','w','n','s','n','s','e','w'}) == false);
    return 0;
}