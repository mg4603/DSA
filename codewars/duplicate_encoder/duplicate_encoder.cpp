#include<string>
#include<assert.h>
#include<map>

using namespace std;

string duplicate_encoder(const string &word){
    map<char, int> a;

    for(char c : word){
        if(a.find(tolower(c)) == a.end()){
            a.insert({tolower(c), 1});
        }else{
            a[tolower(c)]++;    
        }
    }

    string res = "";
    for(char c: word){
        if(a[tolower(c)] > 1){
            res += ")";
        }else{
            res += "(";
        }
    }
    return res;
}

int main(){
        assert(duplicate_encoder("din") == "(((");
        assert(duplicate_encoder("recede") == "()()()");
        assert(duplicate_encoder("Success") == ")())())");
        assert(duplicate_encoder("CodeWarrior") == "()(((())())");
        assert(duplicate_encoder("Supralapsarian") == ")()))()))))()(");
        assert(duplicate_encoder("(( @") == "))((");
        assert(duplicate_encoder(" ( ( )") ==")))))(");
}