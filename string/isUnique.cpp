#include <iostream>
#include <unordered_set>
using namespace std;
bool isUnique(string s){
	int n = s.length();
	unordered_set<char> set;
	for(int i =0;i< n;i++){
		if (set.find(s[i])!=set.end())
			return false;
		set.emplace(s[i]);
	}
	return true;
}
int main(int argc, char** argv){
	cout << isUnique(argv[1]); 
	return 0;	
}
