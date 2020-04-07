#include <stack>
#include <assert.h>
using namespace std;
template <class T>
stack<T> sortStack(stack<T> s1){
	stack<T> sorted;
	while(!s1.empty()){
		T data = s1.top();
		s1.pop();
		while(!sorted.empty() && sorted.top()<data){
			s1.push(sorted.top());
			sorted.pop();
		}
		sorted.push(data);
	}
	return sorted;
}
int main(){
	stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(4);
	s1.push(1);
	stack<int> s2=sortStack<int>(s1);
	assert(s2.top()==1);
	s2.pop();
	assert(s2.top()==1);
	s2.pop();
	assert(s2.top()==2);
	s2.pop();
	assert(s2.top()==4);
	s2.pop();
	return 0;
}
