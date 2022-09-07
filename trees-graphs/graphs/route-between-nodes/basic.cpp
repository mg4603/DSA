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
        void addAdjacentNode(Node<Q>* node){
            this->adjacentNodes.push_back(node);
        }
        void getAdjacentNodes(){
            return this->adjacentNodes;
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

        void connectNodes(Node<Q>* node1, Node<Q>* node2){
            node1->addAdjacentNode(node2);
            node2->addAdjacentNode(node1);
        }
        
};  


int main(){
    return 0;
}