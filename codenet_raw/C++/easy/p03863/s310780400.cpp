#include <iostream>

using namespace std;
int main(void){
	string s;
	cin >> s;
	long long sum = 0;
	for(int i=0; i<s.size()-2; i++){
		if(s[i]!=s[i+2])sum++;
	}
	if(s.size()>3 && s[0]==s[s.size()-1])sum++;
	if(sum%2) cout << "First" << endl;
	else cout << "Second" << endl;
}
