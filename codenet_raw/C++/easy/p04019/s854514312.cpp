#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string>
#include <cmath>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int n, w, south, e;
	for(int i=0;i<s.length();i++){
		if(s[i]=='N'){
			n++;
		}
		if(s[i]=='W'){
			w++;
		}
		if(s[i]=='S'){
			south++;
		}
		if(s[i]=='E'){
			e++;
		}
	}
	if(n==south && w==e){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}