#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;
string compressString(string s){
	stringstream ss;
	char curC = s[0];
	int count = 1;
	for(int i=1;i<s.length();i++){
		if(s[i] == curC)
			count++;
		else{
			ss << curC << count;
			curC = s[i];
			count = 1;
		}
	}
	ss << curC << count;
	string compressedStr = ss.str();
	return compressedStr.length()<s.length()?compressedStr: s;
	
}

int main(int argc, char** argv){
	assert(compressString("aabcccccaaa")=="a2b1c5a3");
	assert(compressString("aabcccccaaa")=="a2b1c5a3");
	return 0;
}
