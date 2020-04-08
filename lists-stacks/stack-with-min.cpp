#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;
template <class T>
class Stack {
	private:
		vector<T> values;
	public:
		Stack(){}
		virtual T pop(){
			if (isEmpty()){
				throw "Stack is empty";
			}
			T data =this->values[this->values.size()-1];
			this->values.erase(this->values.begin()+this->values.size()-1);
			return data;
		}
		virtual T peek(){
			if (isEmpty()){
				throw "Stack is empty";
			}
			return values[values.size()-1];
		}
		virtual void push(T data){
			this->values.push_back(data);
		}
		virtual bool isEmpty(){
			return values.size()==0;
		}
};
template <class T>
class StackWithMin:public Stack<T>{
	private:
		Stack<T> minStack;
	public:
		StackWithMin(){
		}
		T pop(){

			T data = Stack<T>::pop();
			try{
				T min = minStack.peek();
				if (min == data){
					minStack.pop();
				}
			}catch(...){

			}
			return data;
		}
		void push(T data){
			try{
				T min= minStack.peek();
				if( data <= min ){
					minStack.push(data);
				}
			}catch(...){

				minStack.push(data);
			}
			Stack<T>::push(data);
		}
		T min(){
			if(Stack<T>::isEmpty()){
				throw "Stack is Empty";
			}
			return minStack.peek();
		}

};
int main(){
	StackWithMin<int> stackWithMin;
	stackWithMin.push(3);
	stackWithMin.push(4);
	stackWithMin.push(5);
	stackWithMin.push(2);
	assert(stackWithMin.min()==2);
	assert(stackWithMin.pop()==2);
	assert(stackWithMin.min()==3);
	return 0;
}
