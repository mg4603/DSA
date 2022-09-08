#include<iostream>
#include<vector>
using namespace std;

template <typename Q>
struct Node{
    private:
        Q value;
        Node<Q>* left, *right;
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
        Q getValue(){
            return this->value;
        }
};

template<typename T, typename Q>
class Tree{
    Node<Q>* root;
    public:
        Tree(){}
        Node<Q>* getRoot(){
            return this->root;
        }
        void createMinimalBST(vector<Q> vec){
            this->root = createMinimalBST(vec, 0, vec.size()-1);
        }
        Node<Q>* createMinimalBST(vector<Q> vec, T start, T end){
            if(end < start){
                return nullptr;
            }
            T mid((start+end)/2);
            Node<Q>* n = new Node<Q>(vec[mid]);
            n->setLeft(createMinimalBST(vec, start, mid - 1));
            n->setRight(createMinimalBST(vec, mid + 1, end));
            return n;
        }
};

int main(){
    vector<int> vec = {1,2,3,4,5,6,7, 8};
    Tree<int, int>* tree = new Tree<int, int>();
    tree->createMinimalBST(vec);
    cout<<tree->getRoot()->getRight()->getRight()->getRight()->getValue();
    return 0;
}