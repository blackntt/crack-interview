#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
private:
	int name;
	Node *left;
	Node *right;

public:
	Node(int n=0) : name(n) {}
	Node* getLeft()const{
		return left;
	}
	Node* getRight() const{
		return right;
	}
	int getName()const{
		return name;
	}
	void setLeft(Node* n){
		left = n;
	}
	void setRight(Node* n){
		right = n;
	}
};
class ListNode
{
private:
	Node *data;
	ListNode *next;

public:
	ListNode(Node* d=NULL, ListNode* n=NULL) : data(d), next(n) {}

	Node* getData()const{
		return data;
	}
	ListNode* getNext()const{
		return next;
	}
	void setNext(ListNode *n){
		next = n;
	}
};
class List
{
private:
	ListNode *head;
	ListNode *tail;
public:
	List():head(NULL),tail(NULL){}
	ListNode* getHead()const{
		return head;
	}
	ListNode* getTail() const{
		return tail;
	}
	void add(Node * node){
		ListNode * newNode = new ListNode(node);
		if(head == NULL){
			head = newNode;
			tail = head;
		}else{
			tail->setNext(newNode);
			tail = newNode;
		}
	}
};
void traversing(Node* root, vector<List*> &lists, int height){
	if (root ==NULL)
		return;
	
	
	if (height>=lists.size()){
		
		List* newList = new List;
		newList->add(root);
		lists.push_back(newList);
	
	}else{
;
		lists[height]->add(root);
	}
	traversing(root->getLeft(),lists,height+1);
	traversing(root->getRight(),lists,height+1);
}
vector<List*> createListFromBT(Node* root){
	vector<List*> lists;
	traversing(root, lists,0);
	return lists;
}
int main()
{
	Node* a=new Node(1);
	Node* b=new Node(2);
	Node* c=new Node(3);
	Node* d=new Node(4);

	a->setLeft(b);
	a->setRight(c);
	b->setLeft(d);

	auto ls = createListFromBT(a);
	for(auto l: ls){
		cout << l->getHead()->getData()->getName();
	}
	
	
	
	return 0;
}
