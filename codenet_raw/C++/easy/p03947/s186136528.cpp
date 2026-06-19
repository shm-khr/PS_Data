#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	char s[100000]={'\0'};
	gets(s);
	int len=strlen(s);
	int count=0;
	for(int i=1;i<len;i++){
		if(s[i]!=s[i-1]){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}