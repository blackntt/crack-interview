#include <iostream>
#include <unordered_set>
#include <cstring>
#include <string>
using namespace std;
bool isPalindromePermutation(string s){
	unordered_set<char> hashSet;
	for(int i = 0;i < s.length(); i++){
		if(s[i]!=' '){
			unordered_set<char>::iterator itr;
			char c = toupper(s[i]);
			itr = hashSet.find(c);
			if(itr !=hashSet.end()){
				hashSet.erase(itr);
			}else{
				hashSet.emplace(c);
			}
		}
	}
	return hashSet.size()<=1;
}
bool isPalindromePermutationWithBitVector(string s){
	bool bitv[256]={false};
	int count = 0;
	for(int i=0;i< s.length();i++){
		if(s[i]!=' '){
			char c = toupper(s[i]);
			if(bitv[(int)c]==true){
				count--;
				bitv[(int)c]=false;
			}else{
				count++;
				bitv[(int)c]=true;
			}

		}
	}
	return count <=1;
}
int main(int argc, const char * argv[]){
	cout << isPalindromePermutationWithBitVector("Tact Coa");
	return 0;
}
