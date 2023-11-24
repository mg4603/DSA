#include <iostream>
#include <assert.h>

#include <vector>

struct Node
{
    std::vector<Node*> links;
    int flag;
    Node(): flag(false), links(std::vector<Node*>(26, nullptr)){};

    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }

    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void setChar(char ch)
    {
        links[ch - 'a'] = new Node();
    }

    bool containsKey(char key)
    {
        return (links[key - 'a'] != nullptr);
    }
};

class WordDictionary {
    Node *root;

    bool searchHelper(std::string word, Node *root)
    {
        Node *curr = root;
        int n = word.size();

        for(int i = 0; i < n; i++)
        {
            char ch = word[i];
            if(ch == '.')
            {   
                if(i + 1 != n)
                {
                    for(int j = 0; j < 26; j++)
                    {
                        ch = j + 'a';
                        if(curr->containsKey(ch) && 
                           searchHelper(word.substr(i + 1), 
                                        curr->getNode(ch)))
                        {
                            break;
                        }
                    }
                }
                else
                {
                    for(int j = 0; j < 26; j++)
                    {
                        ch = j + 'a';
                        if(curr->containsKey(j + 'a') && 
                           curr->getNode(j + 'a')->isEnd())
                        {
                            return true;
                        }
                    }
                }
            }
            if(!curr->containsKey(ch))
            {
                return false;
            }
            curr = curr->getNode(ch);

        }    
        return curr->isEnd();
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(std::string word) {
        Node *curr = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(!curr->containsKey(word[i]))
            {
                curr->setChar(word[i]);
            }
            curr = curr->getNode(word[i]);
        }
        curr->setEnd();
    }
    
    bool search(std::string word) 
    {
        return searchHelper(word, root);
    }
};

int main()
{

    WordDictionary obj;
    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");
    assert(obj.search("pad") == false);
    assert(obj.search("bad") == true);
    assert(obj.search(".ad") == true);
    assert(obj.search("b..") == true);
    return 0;
}