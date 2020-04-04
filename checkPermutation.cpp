#include <iostream>
#include <unordered_set>
using namespace std;
bool checkPermutation(string s1, string s2){
	//brute force
	if(s1.length() != s2.length())
		return false;
	bool visited[s2.length()];
	memset(visited,0,s2.length()*sizeof(visited[0]));
	for(int i=0;i<s1.length();i++){
		bool isExisted = false;
		for(int j =0;j<s2.length();j++){
			if(s1[i]==s2[j] && visited[j]==false){
				visited[j] = true;
				isExisted = true;
			}
		}
		if (isExisted==false){
			return false;
		}
	}
	return true;
}
bool checkPermutation2(string s1, string s2){
	if(s1.length() != s2.length())
		return false;
	unordered_set<char> set;
	for(int i=0;i<s2.length();i++){
		set.emplace(s2[i]);
	}
	bool isPermutation = true;
	for(int i=0;i<s1.length();i++){
		unordered_set<char>::iterator itr;
		itr = set.find(s1[i]);
		if(itr==set.end())
			return false;
		set.erase(itr);
	}
	return true;
}
bool checkPermutation3(string s1, string s2){
	if (s1.length() != s2.length()){
		return false;
	}
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());	
	for(int i=0;i<s1.length();i++){
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}
int main(int argc, char ** argv){
	cout <<	checkPermutation3("abc","bad");
	return 0;
}
