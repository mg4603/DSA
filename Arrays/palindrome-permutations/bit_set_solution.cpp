#include<bits/stdc++.h>
using namespace std;
string toLower(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
string removeSpaces(string str){
    int cnt(0);
    for(int i(0); i < str.size(); i++){
        if(str[i] != ' ')
            str[cnt++] = str[i];
    }
    return str.substr(0, cnt);
}

bool checkExactlyOneBitSet(int bitVector){
    return (bitVector & (bitVector-1)) == 0;
}

int toggle(int bitVector, int index){
    if(index < 0) return bitVector;

    int mask = 1 << index;

    if((bitVector & mask) == 0){
        return bitVector | mask;
    }
    return bitVector & ~mask;
}

int createBitVector(string str){
    int bitVector = 0;
    for(char c: str){
        bitVector = toggle(bitVector, c-'a');
    }
    return bitVector;
}

bool isPermutation(string input){
    int bitVector = createBitVector(input);
    return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}



int main(){
    string input="Lo";
    cout<<input+(isPermutation(toLower(removeSpaces(input)))?
            " is the permutation of a palindrome":" isn't the permutation of a palindrome")<<endl;
}