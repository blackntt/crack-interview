#include <iostream>
#include <unordered_map>
#include <assert.h>
using namespace std;
class Node{
	private:
		int data;
		Node* next;
	public:
		friend class LinkedList;
		Node():data(0),next(NULL){}
		Node(int d):data(d),next(NULL){}
		int getData() const{return data;}
		Node* getNextNode()const{return next;}
};
class LinkedList{
	private:
		Node * head;
	public:
		LinkedList():head(NULL){}
		void Add(int data){
			if(head==NULL){
				head = new Node(data);
			}else{
				Node* lastNode = head;
				while(lastNode->next!=NULL){
					lastNode = lastNode->next;
				}
				lastNode->next = new Node(data);
			}
		}
		Node* getHead()const{
			return head;
		}
		void Remove_Dups(){
			/* unordered_map<data,pair<Node*,Node*>> hMap; */
			Node* p1 = head;
			while(p1 !=NULL){
				Node* p2 = p1;
				while(p2!=NULL&&p2->next!=NULL){
					if(p1->data == p2->next->data){
						Node* deletedNode = p2->next;
						p2->next = p2->next->next;
						delete deletedNode;
					}
					p2 = p2->next;
				}
				p1 = p1->next;
			}
		}
		void Print(){
			Node* p1 = head;
			while(p1!=NULL){
				cout << p1->data<<"  ";
				p1 = p1->next;
			}
		}
};
int main(int argc, const char* argv[]){
	LinkedList list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(1);
	list.Add(2);
	cout << "Before"<<"\n";
	list.Print();
	cout << "\nAfter"<<"\n";
	list.Remove_Dups();
	list.Print();
	return 0;
}
