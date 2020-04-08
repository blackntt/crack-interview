#include <iostream>
#include <unordered_set>
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
			unordered_set<int> hashMap;
			Node* p1 = head;
			while(p1 !=NULL){
				hashMap.emplace(p1->data);
				Node* deletedNode = p1;
				p1 = p1->next;
				delete deletedNode;
			}
			head = NULL;
			for(int data:hashMap){
				Add(data);
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
