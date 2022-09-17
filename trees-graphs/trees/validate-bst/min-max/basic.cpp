#include<iostream>
using namespace std;

template <typename T, typename Q>
class Tree{
    private:
        class Node{
            private:
                Q value;
                Node *left;
                Node *right;
            public:
                Node(Q value):left(nullptr), right(nullptr){
                    this->value = value;
                }
                Q getValue(){
                    return this->value;
                }
                Node* getLeft(){
                    return this->left;
                }
                Node* getRight(){
                    return this->right;
                }
                
        };
    public:
        Tree():root(nullptr){}
};

int main(){
    return 0;
}