#include<bits/stdc++.h>
using namespace std;

bool checkPermutation(string str1, string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    vector<int> charsStr1 = vector<int>(128, 0), charsStr2 = vector<int>(128, 0);
    for(char a: str1){
        charsStr1[a]++;
    }
    for(char a:str2){
        charsStr2[a]++;
    }
    for(int i = 0; i < 128; i++){
        if(charsStr1[i] != charsStr2[i]){
            return false;
        }
    }

    return true;
}
string removeSpaces(string str){
    int cnt(0);
    for(int i(0); i < str.size(); i++){
        if(str[i] != ' '){
            str[cnt++] = str[i];
        }
    }
    return str.substr(0, cnt);
}
string toLower(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main(){
    string str1("asdff"), str2("fdsaf");
    cout<<(checkPermutation(str1, str2)?
            "Strings are permutations of each other":"Strings aren't permutations of each other")<<endl;
    return 0;
}