#include <iostream>
#include <assert.h>

#include <string>
#include <map>
using namespace std;

std::map<char, char> getKeyMp(std::string key)
{
    std::map<char, char> key_mp;
    for(size_t i(0); i < key.size(); i += 2)
    {
        key_mp[tolower(key[i])] = tolower(key[i + 1]);
        key_mp[tolower(key[i + 1])] = tolower(key[i]);

    }
    return key_mp;
}

std::string substitute(std::string str, std:: string key)
{
    std::map<char, char> key_mp = getKeyMp(key);
    for(char &c: str)
    {
        if(isalpha(c) && key_mp.count(tolower(c)))
        {
            if(isupper(c))
            {
                c = toupper(key_mp[tolower(c)]);
            }
            else
            {
                c = key_mp[c];
            }
        }
    }
    return str;
}

std::string encode (std::string str, std::string key)
{
    return substitute(str, key);
}

std::string decode (std::string str, std::string key)
{
    return substitute(str, key);
}

int main()
{
    assert(encode("Ala has a cat","gaderypoluki") == "Gug hgs g cgt");
    assert(decode("Gug hgs g cgt","gaderypoluki") == "Ala has a cat");
    assert(decode("Dkucr pu yhr ykbir","politykarenu") == "Dance on the table");  
    assert(decode("Hide our beers","regulaminowy") == "Hmdr nge brres");
    assert(encode("ABCD","gaderypoluki") == "GBCE");
    assert(decode("GBCE","gaderypoluki") == "ABCD");
    assert(encode("gaderypoluki","gaderypoluki") == "agedyropulik");
    assert(decode("agedyropulik","gaderypoluki") == "gaderypoluki");        
    return 0;
}