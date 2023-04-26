#include <iostream>
#include <assert.h>

#include <string>
#include <algorithm>
int countDeafRats(const std::string &town){
    size_t pPos(0);
    
    std::string newTown = std::string(town.begin(), town.end());
    newTown.erase(std::remove(newTown.begin(), newTown.end(), ' '), newTown.end());
  
    if (newTown == "P")return 0;
  
    if(newTown.find("P") != std::string::npos){
        pPos = newTown.find("P");
    }else{
        return -1;
    }
    int count(0);
    for(size_t i(0); i < pPos; i += 2){
        if(newTown.substr(i, 2) == "O~"){
            count++;
        }
    }
    for(size_t i(pPos + 1); i < newTown.size(); i+=2){
        if(newTown.substr(i, 2) == "~O"){
            count++;
        }        
    }
    return count;
}

void doTest(int expected, const std::string &town)
{
    assert(countDeafRats(town) == expected);
}

int main(){
    doTest(0, "~O~O~O~O P");
    doTest(1, "P O~ O~ ~O O~");
    doTest(2, "~O~O~O~OP~O~OO~");
    return 0;   
}