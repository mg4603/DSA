#include <iostream>
#include <assert.h>

std::pair< std::string, bool > bears( int x, const std::string & s )
{
    std::string res = "";
    int pos(0);
    while(true)
    {
        pos = s.find_first_of("B8", pos);
        if(pos == std::string::npos)
        {
            break;
        }
        if(s[pos] == 'B' && s[pos + 1] == '8')
        {
            res += "B8";
            pos += 2;
        }
        else if(s[pos] == '8' && s[pos + 1] == 'B')
        {
            res += "8B";
            pos += 2;
        }
        else
        {
            pos += 1;
        }
    }
    if(res.size() >= x)
    {
        return std::make_pair(res, true);
    }
    return std::make_pair(res, false);
}

int main()
{
    assert( bears( 7, "8j8mBliB8gimjB8B8jlB" ) ==  (std::make_pair<std::string, bool>( "B8B8B8", false )));
    assert( bears( 3, "88Bifk8hB8BB8BBBB888chl8BhBfd" ) ==  (std::make_pair<std::string, bool>( "8BB8B8B88B", true )));
    assert( bears( 8, "8" ) ==  (std::make_pair<std::string, bool>( "", false )));
    assert( bears( 1, "j8BmB88B88gkBBlf8hg8888lbe88" ) ==  (std::make_pair<std::string, bool>( "8BB88B", true )));
    assert( bears( 0, "8j888aam" ) ==  (std::make_pair<std::string, bool>( "", false )));
    return 0;
}