#include <iostream>
#include <assert.h>

#include <vector>
#include <sstream>

class Solution {
    class Node
    {
        std::vector<Node*> chars;
        bool end;
        public:
        Node()
        {
            chars = std::vector<Node*>(26, nullptr);
            end = false;
        }
        bool isEnd()
        {
            return end;
        }
        void setEnd()
        {
            end = true;
        }

        bool containsKey(int key)
        {
            return chars[key] != nullptr;
        }

        void setKey(int key)
        {
            chars[key] = new Node();
        }

        Node* getKey(int key)
        {
            return chars[key];
        }
    };

    Node *root;
    void insertWord(std::string s)
    {
        Node *curr = root;
        for(int i = 0; i < s.length(); i++)
        {
            if(!curr->containsKey(s[i] - 'a'))
            {
                curr->setKey(s[i] - 'a');
            }
            curr = curr->getKey(s[i] - 'a');
        }
        curr->setEnd();
    }

    std::pair<bool, std::string> containsWord(std::string s)
    {
        Node *curr = root;
        for(int i = 0; i < s.length(); i++)
        {
            if(curr->isEnd())
            {
                return std::make_pair(true, s.substr(0, i));
            }
            
            if(!curr->containsKey(s[i] - 'a'))
            {
                return std::make_pair(false, "");
            }
            
            curr = curr->getKey(s[i] - 'a');
        }
        return std::make_pair(true, s);
    }
public:
    std::string replaceWords(std::vector<std::string>& dictionary, 
                                    std::string sentence) 
    {
        root = new Node();
        for(int i = 0; i < dictionary.size(); i++)
        {
            insertWord(dictionary[i]);
        }

        std::stringstream ss(sentence);
        std::string temp;
        std::vector<std::string> words;
        while(ss >> temp)
        {
            words.push_back(temp);
        }
        std::string res;
        for(int i = 0; i < words.size(); i++)
        {
            std::pair<bool, std::string> it = containsWord(words[i]);
            if(it.first)
            {
                words[i] = it.second;
            }

            if(i != 0)
            {
                res += ' ';
            }
            res += words[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> dictionary = {"cat","bat","rat"};
        std::string sentence = "the cattle was rattled by the battery";
        std::string res = "the cat was rat by the bat";
        assert(sol.replaceWords(dictionary, sentence) == res);
    }
    {
        std::vector<std::string> dictionary = {"a","b","c"};
        std::string sentence = "aadsfasf absbs bbab cadsfafs";
        std::string res = "a a b c";
        assert(sol.replaceWords(dictionary, sentence) == res);
    }
    return 0;
}