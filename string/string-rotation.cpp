#include <assert.h>
#include <string>
#include <sstream>
using namespace std;
bool isSubstring(string s1, string substr){
	return s1.find(substr) != string::npos;
}
bool stringRotation(string s1, string s2){
	if(s1.length()==s2.length() && s1.length()>0){
		stringstream ss;
		ss << s1 << s1;
		return isSubstring(ss.str(),s2); 
	}
	return false;
}
int main(){
	assert(stringRotation("waterbottle","erbottlewat")==true);
	assert(stringRotation("waterbottler","errbottlewat")==false);
	return 0;
}
