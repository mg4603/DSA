#include <iostream>
#include <queue>
#include <map>

struct HuffmanNode
{
    char symbol;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode()
    {

    }
    
    HuffmanNode(char symbol, int freq, HuffmanNode *left, HuffmanNode* right)
    {
        this->symbol = symbol;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }

    HuffmanNode(int freq, HuffmanNode *left, HuffmanNode *right)
    {
        this->symbol = '\0';
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct HuffmanComparator
{
    bool operator()(const HuffmanNode *a, const HuffmanNode *b) const
    {
        return a->freq > b->freq;
    }
};

using HuffmanPriorityQueue = std::priority_queue<HuffmanNode*, 
                std::vector<HuffmanNode*>, HuffmanComparator>;


HuffmanNode* build_huffman_tree(std::string text)
{
    std::map<char, int> symbol_mp;
    for(char c: text)
    {
        symbol_mp[c]++;
    }
    HuffmanPriorityQueue pq;
    for(auto pair: symbol_mp)
    {
        HuffmanNode *node = new HuffmanNode(pair.first, pair.second, nullptr, nullptr);
        pq.push(node);
    }
    while(pq.size() > 1)
    {
        HuffmanNode *one = pq.top();
        pq.pop();
        HuffmanNode *two = pq.top();
        pq.pop();
        HuffmanNode *three = new HuffmanNode(one->freq + two->freq, one, two);
        pq.push(three);
    }
    return pq.top();
}

void get_huffman_codes(HuffmanNode *root, 
     std::map<char, std::string> &huffman_codes, std::string prefix = "")
{
    if(root->symbol != '\0')
    {
        huffman_codes[root->symbol] = prefix;
    }
    else
    {
        get_huffman_codes(root->left, huffman_codes, prefix + '0');
        get_huffman_codes(root->right, huffman_codes, prefix + '1');
    }
}

std::string huffman_encode(std::string text, HuffmanNode *root)
{
    std::map<char, std::string> huffman_codes;
    get_huffman_codes(root, huffman_codes);

    std::string res;
    for(char ch: text)
    {
        res += huffman_codes[ch];
    }
    return res;
}

std::string huffman_decode(std::string text, HuffmanNode *root)
{
    HuffmanNode *runner = root;
    std::string res;

    for(char ch: text)
    {
        if(ch == '0')
        {
            if(runner->symbol != '\0')
            {
                res += runner->symbol;
                runner = root->left;
            }
            else
            { 
                runner = runner->left;
            }
        }
        else
        {

            if(runner->symbol != '\0')
            {
                res += runner->symbol;
                runner = root->right;
            }
            else
            {
                runner = runner->right;
            }
        }
    }
    if(runner != nullptr && runner->symbol != '\0')
    {
        res += runner->symbol;
    }
    return res;
}

int main()
{
    std::string text = "Hello world!";
    HuffmanNode* root = build_huffman_tree(text);
    std::string encoded_text = huffman_encode(text, root);
    std::string decoded_text = huffman_decode(encoded_text, root);

    std::cout << "Original Text: " << text << std::endl;
    std::cout << "Encoded Text: " << encoded_text << std::endl;
    std::cout << "Decoded Text: " << decoded_text << std::endl;
    return 0;
}