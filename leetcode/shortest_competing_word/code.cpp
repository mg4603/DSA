#include <iostream>
#include <assert.h>

#include <map>
#include <vector>

class Solution {
    std::map<char, int> getFrequencyLowerCase(std::string word)
    {
        std::map<char, int> freq;
        for(char ch: word)
        {
            if(isalpha(ch))
            {
                freq[std::tolower(ch)]++;
            }
        }
        return freq;
    }
public:
    std::string shortestCompletingWord(std::string licensePlate, 
                            std::vector<std::string>& words) {
        
        std::map<char, int> freq_license = getFrequencyLowerCase(licensePlate);


        std::string res;

        for(std::string word: words)
        {
            std::map<char, int> freq_word = getFrequencyLowerCase(word);
            int cnt(0);
            for(auto pair: freq_license)
            {
                if(freq_word[pair.first] >= pair.second)
                {
                    cnt++;
                }
            }
            if(cnt == freq_license.size())
            {
                if(res == "" || res.size() > word.size())
                {
                    res = word;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string license_plate = "1s3 PSt";
        std::string res = "steps";
        std::vector<std::string> words = {"step","steps","stripe","stepple"};
        assert(sol.shortestCompletingWord(license_plate, words) == res);
    }
    {
        std::string license_plate = "1s3 456";
        std::string res = "pest";
        std::vector<std::string> words = {"looks","pest","stew","show"};
        assert(sol.shortestCompletingWord(license_plate, words) == res);
    }
    return 0;
}