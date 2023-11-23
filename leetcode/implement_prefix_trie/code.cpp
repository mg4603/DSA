#include <iostream>
#include <assert.h>

#include <vector>

struct Node
{
    std::vector<Node*> links;
    bool flag;

    Node() : flag(false), links(std::vector<Node*>(26, nullptr)){};
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != nullptr);
    }

    Node* getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void setChar(char ch)
    {
        links[ch - 'a'] = new Node();
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(std::string word) 
    {
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
        Node *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!curr->containsKey(word[i]))
            {
                return false;
            }
            curr = curr->getNode(word[i]);
        }
        return curr->isEnd();
    }
    
    bool startsWith(std::string prefix) 
    {
        Node *curr = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!curr->containsKey(prefix[i]))
            {
                return false;
            }
            curr = curr->getNode(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie obj;
    obj.insert("apple");
    assert(obj.search("apple") == true);
    assert(obj.search("app") == false);
    assert(obj.startsWith("app") == true);
    obj.insert("app");
    assert(obj.search("app") == true);
    return 0;
}