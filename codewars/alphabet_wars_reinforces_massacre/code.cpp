#include <assert.h>
#include <iostream>

#include <vector>
#include <string>
#include <queue>
#include <set>

std::string alphabet_war(const std::vector<std::string>& reinforces,
                         const std::vector<std::string>& airstrikes)
{
    std::vector<std::queue<char>> reinforcements(reinforces[0].size());
    for(const std::string reinforce : reinforces)
    {
        for(size_t i(0); i < reinforce.size(); i++)
        {
            reinforcements[i].push(reinforce[i]);
        }
    }

    for(const std::string airstrike: airstrikes)
    {
        std::set<int> st;
        for(size_t i(0); i < airstrike.size(); i++)
        {
            if(airstrike[i] == '*')
            {
                st.insert(i);
                if(i > 0)
                {
                    st.insert(i - 1);
                }
                if(i < reinforces[0].size() - 1)
                {
                    st.insert(i + 1);
                }
            }
        }
        for(int pos: st)
        {
            if(!reinforcements[pos].empty())
                reinforcements[pos].pop();
        }
    }
    
    std::string res;
    for(std::queue<char> q: reinforcements)
    {
        if(q.empty())
        {
            res += '_';
        }
        else
        {
            res += q.front();
        }
    }
    return res;
}

template<class T1, class T2>
void assert_equals(const T1& actual, const T2& expected)
{
    assert(actual == expected);
}

int main()
  {
    static const std::vector<std::string> reinforces = {
      "g964xxxxxxxx",
      "myjinxin2015",
      "steffenvogel",
      "smile67xxxxx",
      "giacomosorbi",
      "freywarxxxxx",
      "bkaesxxxxxxx",
      "vadimbxxxxxx",
      "zozofouchtra",
      "colbydauphxx"
    };
    static const std::vector<std::string> airstrikes = {
      "* *** ** ***",
      " ** * * * **",
      " * *** * ***",
      " **  * * ** ",
      "* ** *   ***",
      "***   ",
      "**",
      "*",
      "*"
    };
    assert_equals(alphabet_war(reinforces, airstrikes), "codewarsxxxx");
    assert_equals(alphabet_war({"abcdefg", "hijklmn"}, {"   *   ", "*  *   "}), "hi___fg");               
    assert_equals(alphabet_war({"zzzzz","bbbbb", "ccccc", "ddddd"}, {"*", " *", "   "}), "ccbzz");
    assert_equals(alphabet_war({"lriixqqlfzhcqtauspv"}, {"    *   "}), "lri___qlfzhcqtauspv"); 

    return 0;
}