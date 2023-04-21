#include <assert.h>
#include <string>
std::string encode(const std::string &str){
    std::string res;
    for(const char &c: str){
        switch(c){
            case 'a':
                res += '1';
                break;
            case 'e':
                res += '2';
                break;
            case 'i':
                res += '3';
                break;
            case 'o':
                res += '4';
                break;
            case 'u':
                res += '5';
                break;
            default:
                res += c;
        }
    }
    return res;
}

std::string decode(const std::string &str){
    std::string res;
    for(const char c: str){
        switch(c){
            case '1':
                res += 'a';
                break;
            case '2':
                res += 'e';
                break;
            case '3':
                res += 'i';
                break;
            case '4':
                res += 'o';
                break;
            case '5':
                res += 'u';
                break;
            default:
                res += c;
        }
    }
    return res;
}

int main(){
    assert(encode("hello") == "h2ll4");
    assert(encode("How are you today?") == "H4w 1r2 y45 t4d1y?");
    assert(encode("This is an encoding test.") == "Th3s 3s 1n 2nc4d3ng t2st.");
    assert(decode("h2ll4") == "hello");
    assert(decode("H4w 1r2 y45 t4d1y?") == "How are you today?");
    assert(decode("Th3s 3s 1n 2nc4d3ng t2st.") == "This is an encoding test.");
    return 0;
}