#include <assert.h>
#include <iostream>

#include <sstream>

std::string insideOutWord(std::string word)
{
    if(word.size() <= 3)
    {
        return word;
    }
    std::string res_word;
    if(word.size() % 2 == 1)
    {
        res_word += word[word.size() /2];
    }

    for(size_t i(0); i < (word.size() / 2); i++)
    {
        res_word = word[i] + res_word;
        res_word += word[word.size() - i - 1];
    }

    return res_word;
}

std::string insideOut(std::string x)
{
    std::stringstream ss(x);
    std::string res;
    std::string token;
    while(getline(ss, token, ' '))
    {
        res += insideOutWord(token);
        res += ' ';
    }
    if(res.size() > 0 && res.back() == ' ')
    {
        res.pop_back();
    }
    return res;
}

int main()
{
    assert(insideOut("man i need a taxi up to ubud") == "man i ende a atix up to budu");
    assert(insideOut("what time are we climbing up the volcano") == "hwta item are we milcgnib up the lovcona");
    assert(insideOut("take me to semynak") == "atek me to mesykan");
    assert(insideOut("massage yes massage yes massage") == "samsega yes samsega yes samsega");
    assert(insideOut("take bintang and a dance please") == "atek nibtgna and a adnec elpesa");
    return 0;
}