#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string toGoatLatin(std::string sentence) {
        
        int i(0);
        int cnt(1);
        std::string res;
        std::string vowels = "aeiou";
        while(i != std::string::npos)
        {
            int start = i;
            i = sentence.find_first_of(" ", start);

            std::string temp = sentence.substr(start, i - start);
            if(vowels.find(std::tolower(temp[0])) != std::string::npos)
            {
                res += temp + "ma" + std::string(cnt, 'a') + " ";
            }
            else
            {
                res += temp.substr(1) + temp[0] + "ma" + std::string(cnt, 'a') + " ";                
            }
            i = sentence.find_first_not_of(" ", i);
            cnt++;
        }
        if(res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};
int main()
{
    Solution sol;
    {
        std::string sentence = "I speak Goat Latin";
        std::string res = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa";
        assert(sol.toGoatLatin(sentence) == res);
    }
    {
        std::string sentence = "The quick brown fox jumped over the lazy dog";
        std::string res = "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
        assert(sol.toGoatLatin(sentence) == res);
    }
    return 0;
}