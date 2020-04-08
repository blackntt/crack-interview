#include <vector>
#include <iostream>
using namespace std;

template <class T>
class ThreeInOneStack{
	private:
		vector<T> store;
		int numOfStacks;
		int * sizes;
	public:
		ThreeInOneStack(int stackSize,int stackNum):numOfStacks(stackNum){
			store = vector<T>(this->numOfStacks * stackNum);
			sizes = new int[this->numOfStacks];
			memset(this->sizes,0,this->numOfStacks*sizeof(*sizes));
			/* for(int i=0;i<numOfStacks;i++){ */
			/* 	sizes[i]= 0; */
			/* } */
		}

		void push(T data,int stack){
			if(isFullStack(stack))
				throw "The stack is full";
			else{
				sizes[stack]++;
				store[indexOfTop(stack)]=data;
			}
		}
		T pop(int stack){
			if (sizes[stack]==0)
				throw "The stack is empty";
			T top = this->store[indexOfTop(stack)];
			this->sizes[stack]--;
			return top;
		}
		T peek(int stack){
			if (sizes[stack]==0)
				throw "The stack is empty";
			T top = this->store[indexOfTop(stack)];
			return top;
		}
		bool isFullStack(int stack){
			return sizes[stack] >= store.size()/this->numOfStacks;
		}
		int indexOfTop(int stack){
			int index = store.size()/numOfStacks *stack + sizes[stack]-1;
			return index;

		}
		bool isEmpty(int stack){
			return sizes[stack]==0;
		}

};

int main(int argc, const char * argv[]){
	ThreeInOneStack<int> stacks(10,3);
	stacks.push(5,1);
	stacks.push(3,1);
	stacks.push(4,2);
	cout << stacks.pop(1);
	cout << stacks.pop(1);
	cout << stacks.peek(2);
	cout << stacks.pop(2);
	return 0;
}
