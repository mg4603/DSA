#include <iostream>
#include <assert.h>

#include <string>

std::string to_binary(int n)
{
    std::string bin_string;
    while(n){
        bin_string = std::to_string(n % 2) + bin_string;
        n /= 2;
    }
    return bin_string;
}

char swapCharCase(char c)
{
    if(isupper(c))
    {
        return tolower(c);
    }
    else
    {
        return toupper(c);
    }
}

std::string swap(std::string s, int n) {
    std::string bin_string = to_binary(n);
    int idx(0);

    if(bin_string.length() == 0)
    {
        return s;
    }
    
    for(char &c: s)
    {
        if(isalpha(c))
        {
            if(bin_string[idx++] == '1')
            {
                c = swapCharCase(c);
            }
            idx %= bin_string.length();
        }
    }
    return s;
}

int main()
{
    assert(swap("Hello world!", 11) == "heLLO wORLd!");
    assert(swap("the quick broWn fox leapt over the fence", 9) == "The QUicK BrowN foX LeaPT ovER thE FenCE");
    assert(swap("eVerybody likes ice cReam", 85) == "EVErYbODy LiKeS IcE creAM");
    assert(swap("gOOd MOrniNg", 7864) == "GooD MorNIng");
    assert(swap("how are you today?", 12345) == "HOw are yoU TOdaY?");
    assert(swap("the lord of the rings", 0) == "the lord of the rings");
    assert(swap("", 11345) == "");
    assert(swap("", 0) == "");
    assert(swap("HELLO WORLD!", 5) == "hEllO woRld!");
    assert(swap("hello world!", 56) == "HELlo wORLd!");
    return 0;
}