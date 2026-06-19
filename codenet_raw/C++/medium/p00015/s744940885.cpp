#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int cnt, m;
	cin >> cnt;
	string s1, s2, ans;
	for(int i = 0; i < cnt; i++){
		cin >> s1 >> s2;
		ans = "";
		m = max(s1.size(), ans.size());
		while( s1.size() < m ) 
			s1 = '0' + s1;
		while( s2.size() < m )
			s2 = '0' + s2;		
		int c = 0;	
		for(int i = m-1; i >= 0; i--){
			char ch = ((s1[i] - '0') + (s2[i] - '0') + c) % 10 + '0';
			c = ((s1[i] - '0') + (s2[i] - '0') + c) / 10;
			ans += ch;
		}		
		if(c) 
			ans += c + '0';
		reverse(ans.begin(), ans.end());
		while(ans.size() > 1 && ans[0] == '0') 
			ans.erase(ans.begin());		
		if(ans.size() > 80)
			cout << "overflow" << endl;
		else
			cout << ans << endl;
	}
}