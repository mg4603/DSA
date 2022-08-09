#include<bits/stdc++.h>
using namespace std;

// ford - > rdfo (rotation point between o and r, i.e., x='fo' y='rd' and rotation is yx -> rdfo)
// a rotation yx will always be a substring of xyxy so check for that

// check if str2 is a rotation of str1
bool isRotation(string str1, string str2){
    if(str1.length() && str1.length() == str2.length())
    {
        // check if str2 is a substring of str1
        return (str1+str1).find(str2,0) != string::npos;
    }
    return false;
}

int main(){
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout<<s2+(isRotation(s1,s2)?" is ":" isn't ")+" a rotation of "+s1<<endl;
    return 0;
}