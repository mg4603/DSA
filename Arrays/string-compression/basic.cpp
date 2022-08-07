#include<bits/stdc++.h>
using namespace std;

string compressString(string str){
    string result = "";
    int cnt(0);
    for(int i(0); i < str.length(); i++){
        cnt++;
        if(i+1 >= str.length() || str.at(i) != str.at(i+1)){
            result += str.at(i) + to_string(cnt);
            cnt = 0;
        }
    }

    return result;
}

int main(){
    string input = "aabcccccaaa";
    cout<<compressString(input)<<endl;
    return 0;
}