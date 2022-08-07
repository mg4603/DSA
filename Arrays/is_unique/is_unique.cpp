#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isUnique(string str){
    vector<bool> seen = vector<bool>(128, false);
    if(str.size() > 128)
    return false;

    for(auto a: str){
        if(seen[a])
            return false;
        seen[a] = true;
    }
    return true;
}


int main(){
    string str = "asdfasdf";
    cout<<(isUnique(str)?"Every char is unique":"Some char is repeated");
}