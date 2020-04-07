#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
class Node{
	private:
		vector<Node*> nodes;
	public:
		string name;
		Node(string name){this->name = name;}
		void addConnection(vector<Node*> connectedNodes){
			for(Node* node: connectedNodes){
				addConnection(node);
			}
		}
		void addConnection(Node* node){
			nodes.push_back(node);
		}
		vector<Node*> getConnections() const{
			return nodes;
		}
};
class Graph{
	private:
		vector<Node*> nodes;
	public:
		Graph(){}
		Graph(vector<Node*> nodes){
			this->nodes = nodes;
		}
		void add(Node * node){
			nodes.push_back(node);
		}
		void add(vector<Node*> nodes){
			for(Node * node: nodes){
				add(node);
			}
		}
		bool traversing(Node* node1, Node* node2, set<string> &visited){
			if (node1->name == node2-> name){
				return true;
			}
			visited.emplace(node1->name);
			for(Node * node: node1->getConnections()){
				if(visited.find(node->name)==visited.end()){
					if(traversing(node,node2,visited))
						return true;
				}
			}

			return false;
		}
		bool hasRoute(Node* node1, Node* node2){
			set<string> visited;
			if(node1 == NULL || node2 == NULL) return false;
			return traversing(node1, node2, visited);
		}
};

int main(){
	Node a("a");
	Node b("b");
	Node c("c");
	Node d("d");
	Node e("e");
	Node f("f");
	a.addConnection(&b);
	b.addConnection(&c);
	b.addConnection(&d);
	c.addConnection(&e);
	Graph g;
	g.add(&a);
	g.add(&b);
	g.add(&c);
	g.add(&d);
	g.add(&e);
	g.add(&f);
	assert(g.hasRoute(&a,&e)==true);
	assert(g.hasRoute(&a,&f)==false);
	return 0;
}
