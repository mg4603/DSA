#include<string>
#include<iostream>
using namespace std;

string urlify(string str, int length){
    string output = "";
    for(int i(0); i < length; i++){
        if(str[i] == ' '){
            output += "%20";
        }else{
            output += str[i];
        }
    }
    return output;
}

int main(){
    string input="Mr John Smith";
    int n(13);
    cout<<urlify(input, n);    
} 