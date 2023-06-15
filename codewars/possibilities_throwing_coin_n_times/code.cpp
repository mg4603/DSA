#include <iostream>
#include <assert.h>

#include <string>
#include <vector>
#include <algorithm>

std::string coin(int n) {
    std::vector<std::string> res{"H", "T"};
    
    while(--n)
    {
      std::vector<std::string> temp;
      for(std::string str: res)
      {
        temp.push_back(str + "H");
        temp.push_back(str + "T");
      }
      res = temp;
    }
  
    std::string res_string;
    std::sort(res.begin(), res.end());
    for(std::string str: res)
    {
      res_string += str + ",";
    }
    if(res_string.back() == ',')
    {
      res_string.pop_back();
    }
    return res_string;
}

int main()
{
    assert(coin(1) == "H,T");
    assert(coin(2) == "HH,HT,TH,TT");
    assert(coin(3) == "HHH,HHT,HTH,HTT,THH,THT,TTH,TTT");
    return 0;
};