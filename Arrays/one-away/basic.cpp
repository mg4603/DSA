#include<bits/stdc++.h>
using namespace std;

bool oneReplaceAway(string str1, string str2){
    bool foundOne = false;
    for(int i(0); i < str1.length(); i++){
        if(str1.at(i) != str2.at(i)){
            if(foundOne){
                return false;
            }
            foundOne = true;
        }
    }
    return true;
}

bool oneInsertAway(string str1, string str2){
    int index1(0), index2(0);
    while(index1 < str1.length() & index2 < str2.length()){
        if(str1.at(index1) != str2.at(index2)){
            if(index1 != index2){
                return false;
            }
            index2++;
        }else{
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(string str1, string str2){
    if(str1.length() == str2.length()){
        return oneReplaceAway(str1, str2);
    }else if(str1.length() + 1 == str2.length()){
        return oneInsertAway(str1, str2);
    }else if(str1.length() - 1 == str2.length()){
        return oneInsertAway(str2, str1);
    }
    return false;
}

int main(){
    string str1="apple", str2="apppple";
    cout<<"Strings "+str1+" and "+str2+(oneEditAway(str1, str2)?
            " are one edit away.":" are more than one edit away")<<endl;
    return 0;
}