#include <iostream>
#include <assert.h>

#include <string>

int numSpaces(int n, int k)
{
    int cnt(0);
    for(int i(1); i < n - k; i++)
    {
        cnt += std::to_string(i).length();
    }
    return cnt;
}

std::string pattern(int n)
{
  if(n <= 0)
  {
    return "";
  }
  std::string res;
  for(int i(1); i <=n; i++)
  {
    std::string spaces(n - i, ' ');
    res += spaces;
    for(int j(1); j <= i; j++)
    {
      res += std::to_string(j % 10);
    }
    for(int j(i - 1); j >= 1; j--)
    {
      res += std::to_string(j % 10);
    }
    res += spaces;
    if(i != n)
      res += '\n';
  }
  return res;
}

int main()
{
    std::string expected = "";
    std::string actual = pattern(0);
    assert("\n" + actual == "\n" + expected);
    
    expected = "";
    actual = pattern(-25);
    assert("\n" + actual == "\n" + expected);
    
    expected = "1";
    actual = pattern(1);
    assert("\n" + actual == "\n" + expected);
    
    expected = "   1   \n  121  \n 12321 \n1234321";
    actual = pattern(4);
    assert("\n" + actual == "\n" + expected);
    
    expected = "      1      \n     121     \n    12321    \n   1234321   \n  123454321  \n 12345654321 \n1234567654321";
    actual = pattern(7);
    assert("\n" + actual == "\n" + expected);
    return 0;
}