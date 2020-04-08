#include <stack>
#include <assert.h>
using namespace std;
template <class T>
class Queue{
	private:
		stack<T> s1;
		stack<T> s2;
	public:
		Queue(){}
		void add(T data){
			s1.push(data);
		}
		void remove(){

			shiftStack();
			s2.pop();
		}
		T peek(){
			shiftStack();
			return s2.top();
		}
		bool isEmpty(){
			return s1.empty()&&s2.empty();
		}
		void shiftStack(){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
		}
};
int main(){
	Queue<int> q;
	q.add(3);
	q.add(4);
	q.remove();
	assert(q.peek()==4);
	return 0;
}
