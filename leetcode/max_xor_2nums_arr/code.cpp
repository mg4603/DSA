#include <iostream>
#include <assert.h>

#include <vector>

class Node
{
    std::vector<Node*> links;

    public:
    Node()
    {
        links = std::vector<Node*>(2, nullptr);
    }

    bool containsKey(int bit)
    {
        if(links[bit] == nullptr)
        {
            return false;
        }
        return true;
    }

    Node *getKey(int bit)
    {
        return links[bit];
    }

    void insertKey(int bit)
    {
        links[bit] = new Node();
    }
};
class Solution {
    Node* trie;
public:
    Solution()
    {
        trie = new Node();
    }

    void insertNum(int num)
    {
        Node * curr = trie;
        for(int i = 31; i >= 0; i--)
        {
            int key = num >> i & 1;
            if(!curr->containsKey(key))
            {
                curr->insertKey(key);
            }
            curr = curr->getKey(key);
        }
    }
    
    int getMax(int num)
    {
        Node *curr = trie;
        int res = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bit = num >> i & 1;
            if(curr->containsKey(1 - bit))
            {
                res |= (1 << i);
                curr = curr->getKey(1-bit);
            }
            else
            {
                curr = curr->getKey(bit);
            }
        }
        return res;
    }

    int findMaximumXOR(std::vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            insertNum(nums[i]);
        }

        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res = std::max(res, getMax(nums[i]));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,10,5,25,2,8};
        int res = 28;
        assert(sol.findMaximumXOR(nums) == res);
    }
    {
        std::vector<int> nums = {14,70,53,83,49,91,36,80,92,51,66,70};
        int res = 127;
        assert(sol.findMaximumXOR(nums) == res);
    }
    return 0;
}