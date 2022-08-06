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

bool isPermutation(string str){
    vector<int> frequencyChars = vector<int>(26, 0);
    for(int i(0); i < str.size(); i++){
        frequencyChars[str[i]-'a']++;
    }
    int odds(0);
    for(int i(0); i < 26; i++){
        if(frequencyChars[i]%2 != 0){
            odds++;
        }
    }
    return odds > 1?0:1;
}

int main(){
    string input = "adam";
    cout<<isPermutation(toLower(removeSpaces(input)));
    return 0;
}