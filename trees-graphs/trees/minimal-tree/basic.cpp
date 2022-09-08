#include<iostream>
#include<vector>
using namespace std;

template <typename Q>
struct Node{
    private:
        Q value;
        Node<Q>* left, right;
    public:
        Node(Q value){
            this->value = value;
        }
        void setLeft(Node<Q>* left){
            this->left = left;
        }
        void setRight(Node<Q>* right){
            this->right = right;
        }
        Node<Q>* getRight(){
            return this->right;
        }
        Node<Q>* getLeft(){
            return this->left;
        }
};

template<typename Q>
class Tree{
    Node<Q>* root;
    public:
        
};

int main(){
    return 0;
}