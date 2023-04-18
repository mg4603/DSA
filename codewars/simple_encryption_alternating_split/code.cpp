#include <assert.h>
#include <string>

std::string encrypt(std::string text, int n)
{
    if(text.size() == 0 || n <= 0)return text;
    while(n--){
        std::string temp;
        for(size_t i(1); i < text.size(); i += 2){
            temp += text[i];
        }
        for(size_t i(0); i < text.size(); i+=2){
            temp += text[i];
        }
        text = temp;
    }
    return text;
}

std::string decrypt(std::string encryptedText, int n)
{
    if(encryptedText.size() == 0 || n <= 0)return encryptedText;

    while(n--){
        std::string temp;
        size_t i(encryptedText.size() / 2);
        size_t j(0);
        for(; i < encryptedText.size() && j < encryptedText.size() / 2; i++, j++){
            temp  += encryptedText.at(i);
            temp += encryptedText.at(j);
        }
        for(; i < encryptedText.size(); i++){
            temp += encryptedText.at(i);
        }
        for(; j < encryptedText.size() / 2; j++){
            temp += encryptedText.at(j);
        }
        encryptedText = temp;
    }
    return encryptedText;
}

int main(){
    assert(encrypt("This is a test!", 0) == "This is a test!");
    assert(encrypt("This is a test!", 1) == "hsi  etTi sats!");
    assert(encrypt("This is a test!", 2) == "s eT ashi tist!");
    assert(encrypt("This is a test!", 3) == " Tah itse sits!");
    assert(encrypt("This is a test!", 4) == "This is a test!");
    assert(encrypt("This is a test!", -1) == "This is a test!");
    assert(encrypt("This kata is very interesting!", 1) == "hskt svr neetn!Ti aai eyitrsig");
    assert(decrypt("This is a test!", 0) == "This is a test!");
    assert(decrypt("hsi  etTi sats!", 1) == "This is a test!");
    assert(decrypt("s eT ashi tist!", 2) == "This is a test!");
    assert(decrypt(" Tah itse sits!", 3) == "This is a test!");
    assert(decrypt("This is a test!", 4) == "This is a test!");
    assert(decrypt("This is a test!", -1) == "This is a test!");
    assert(decrypt("hskt svr neetn!Ti aai eyitrsig", 1) == "This kata is very interesting!");
    assert(encrypt("", 0) == "");
    assert(encrypt("", 3) == "");
    assert(decrypt("", 0) == "");
    assert(decrypt("", 3) == "");
    return 0;
}