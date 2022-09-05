#include<iostream>
#include<queue>
#include<vector>
using namespace std;

enum State{
    Unvisited, Visited, Visiting
};

template <typename Q>
struct Node{
    Q value;
    vector<Node*> adjacentNodes;
    public:
        Node(Q value){
            this->value = value;
        }
};

template<typename Q>
class Graph{
    vector<Node<Q>*> nodes;
    public:
        Graph(){}
        void addNode(Node* node){
            this->nodes.push_back(node);
        }

        
};


int main(){
    return 0;
}