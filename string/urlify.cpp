#include <iostream>

using namespace std;
char* urlify(char *s,int length){
	int spaces = 0;
	for(int i=0;i<length;i++){
		if(s[i]==' ')
			spaces++;
	}
	int actualLength = length + 2*spaces;
	int j=actualLength -1;
	for(int i=length-1;i>=0;i--){
		if(s[i]!=' '){
			s[j--]=s[i];
		}else{
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';	
		}
	}
	return s;
}
int main(int argc, char ** argv){
	char s[]="Mr John Smith    ";    
	cout << urlify(s,13);
	return 0;
}
