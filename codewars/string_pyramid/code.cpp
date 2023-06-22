#include <assert.h>
#include <iostream>

#include <cmath>
#include <sstream>
#include <vector>

std::string watchPyramidFromTheSide(std::string characters)
{
    if(characters == "")
      return "";
    std::stringstream ss;

    int n(characters.size());

    for(int i(0); i < n; i++)
    {
        if(i > 0)
            ss << '\n';
        
        ss << std::string(n - i - 1, ' ');
        ss << std::string( 2 * i + 1, characters[n - i - 1]);
        ss << std::string(n - i - 1, ' ');
    }
    return ss.str();
}

std::string watchPyramidFromAbove(std::string characters)
{
    if(characters == "")
      return "";
    int n(characters.size());
    std::vector<std::vector<int>> pat(2 * n - 1, std::vector<int>(2 * n - 1, 0));
    for(int i(1); i < n; i++)
    {
        for(int j(i); j < (2 * n - 1) - i; j++)
        {
            for(int k(i); k < (2 * n - 1) - i; k++)
            {
                pat[j][k]++;
            }
        }
    }

    std::stringstream ss;
    
    for(int i(0); i < pat.size(); i++)
    {
        if(i > 0)
            ss << '\n';
        for(int j(0); j < pat[i].size(); j++)
        {
            ss << characters[pat[i][j]];
        }
    }
    return ss.str();
}

int countVisibleCharactersOfThePyramid(std::string characters)
{
    if(characters.size() == 0)
      return -1;
    return pow(characters.size() * 2 - 1, 2);
}

int countAllCharactersOfThePyramid(std::string characters)
{
    if(characters.size() == 0)
      return -1;
    int n(characters.size());
    return ((n* ((4 * n * n) - 1))/3);
}

void test1()
{
    std::string testCharacters = "*#";
    
    // Test CountVisibleCharacters
    assert(countVisibleCharactersOfThePyramid(testCharacters) == (9));
    
    // Test CountAllCharacters
    assert(countAllCharactersOfThePyramid(testCharacters) == (10));

    // Test FromSide
    std::string expectedWatchFromSide = " # \n***";
    std::string actualWatchFromSide = watchPyramidFromTheSide(testCharacters);
    
    assert("\n" + actualWatchFromSide == ("\n" + expectedWatchFromSide));

    // Test FromAbove
    std::string expectedWatchFromAbove = "***\n*#*\n***";
    std::string actualWatchFromAbove = watchPyramidFromAbove(testCharacters);
    
    assert("\n" + actualWatchFromAbove == ("\n" + expectedWatchFromAbove));

}

void test2()
{
    std::string testCharacters = "abc";
    
    // Test FromSide
    std::string expectedWatchFromSide = "  c  \n bbb \naaaaa";
    std::string actualWatchFromSide = watchPyramidFromTheSide(testCharacters);
    
    assert("\n" + actualWatchFromSide == ("\n" + expectedWatchFromSide));
    
    //Test FromAbove
    std::string expectedWatchFromAbove = "aaaaa\nabbba\nabcba\nabbba\naaaaa";
    std::string actualWatchFromAbove = watchPyramidFromAbove(testCharacters);
    
    assert("\n" + actualWatchFromAbove == ("\n" + expectedWatchFromAbove));
    
    // Test CountVisibleCharacters
    assert(countVisibleCharactersOfThePyramid(testCharacters) == (25));
    
    // Test CountAllCharacters
    assert(countAllCharactersOfThePyramid(testCharacters) == (35));
} 

int main()
{
    test2();
    test1();
    return 0;
}