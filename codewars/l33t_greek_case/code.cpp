#include <iostream>
#include <assert.h>

#include <map>

std::string greekLeet(std::string str)
{
  std::map<char, std::string> gk_mp{
   {'A', "α"}, {'B', "β"}, {'D', "δ"},
{'E', "ε"}, {'I', "ι"}, {'K', "κ"},
{'N', "η"}, {'O', "θ"}, {'P', "ρ"},
{'R', "π"}, {'T', "τ"}, {'U', "μ"},
{'V', "υ"}, {'W', "ω"}, {'X', "χ"},
{'Y', "γ"}
  };
  std::string res;
  for(char c: str)
  {
    if(gk_mp.count(toupper(c)))
    {
      res +=  gk_mp[toupper(c)];
    }
    else{
      res += tolower(c);
    }
  }
  return res;
}

int main()
{
    assert(greekLeet("codewars") == "cθδεωαπs");
    assert(greekLeet("kata") == "κατα");
    assert(greekLeet("kumite") == "κμmιτε");
    assert(greekLeet("greekleet") == "gπεεκlεετ");
};