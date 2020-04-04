#include <iostream>

using namespace std;
bool isOneWay(string s1, string s2){
	if (s1.length()==s2.length()){
		int diff = 0;
		for(int i=0;i<s1.length();i++){
			if(s1[i]!=s2[i]){
				diff ++;
			}
		}
		return diff <=1;
	}
	else
	{
		int maxLen = max(s1.length(),s2.length());
		int diff = 0;
		for(int i=0;i<maxLen;i++){
			if (diff== 0){
				if (s1[i] !=s2[i]){
					diff++;
				}
			}else{
				if (s1[i] != s2[i-diff]){
					return false;
				}
			}
		}
		return diff <=1;
	}
		
}
bool isOneWayOnePass(string s1, string s2){
	int maxLen = max(s1.length(),s2.length());
	int diff = 0;
	for(int i=0;i<maxLen;i++){
		if (diff== 0){
			if (s1[i] !=s2[i]){
				diff++;
			}
		}else{
			if(s1.length()!=s2.length()){
				if (s1[i] != s2[i-diff] ){
					return false;
				}
			}else{
				if (s1[i] != s2[i]){
					return false;
				}
			}
			
		}
	}
	return true;
		
}
int main(int argc, char ** argv){
	
	cout << isOneWayOnePass("pale","ple");
	return 0;
}
