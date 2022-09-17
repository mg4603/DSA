#include<iostream>
using namespace std;

template <typename T, typename Q>
class BinaryTree{
    private:
        class Node{
            private:
                Q value;
                Node* left;
                Node* right;
            public:
                Node(Q value){
                    this->value = value;
                }
                void setValue(Q value){
                    this->value = value;
                }
                void setLeft(Node* left){
                    this->left = left;
                }
                void setRight(Node* right){
                    this->right = right;
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
        void inorderPrint(Node *root){
            if(root != nullptr){
                inorderPrint(root->getLeft());
                cout<<root->getValue()<<" ";
                inorderPrint(root->getRight());
            }
        }
        Node *root;
    public:
        BinaryTree():root(nullptr){}
        void setRoot(Node *root){
            this->root = root;
        }
        Node* getRoot(){
            return this->root;
        }
        void inorderPrint(){
            inorderPrint(this->getRoot());
        }

};

int main(){
    return 0;
}