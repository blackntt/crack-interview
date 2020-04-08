#include <assert.h>
#include <iostream>
using namespace std;
struct Node{
	int name;
	Node* left;
	Node* right;
	Node(int name):left(NULL),right(NULL){this->name = name;}
};
Node* createTree(int arr[], int left, int right){
	if(left > right){
		return	NULL;
	}
	int mean = (left+right)/2;
	Node * root =new Node(arr[mean]);
	root->left = createTree(arr, left, mean-1);
	root->right = createTree(arr, mean+1,right);
	return root;
}
Node* createMinialFromArray(int arr[],int length){
	return createTree(arr,0,length-1);
}
void printTree(Node* root){
	if(root == NULL)
		return;
	printTree(root->left);
	cout << root->name<<endl;
	printTree(root->right);
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8};
	Node * root = createMinialFromArray(arr,8);
	printTree(root);
}
