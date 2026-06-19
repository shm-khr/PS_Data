#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(){
	vector<int> a,b;
	int n,m;
	cin>>n;
	lp(i,n){
		int hoge;
		cin>>hoge;
		a.push_back(hoge);
	}
	cin>>m;
	lp(i,m){
		int hoge;
		cin>>hoge;
		b.push_back(hoge);
	}
	vector<int> ans;
	set_symmetric_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(ans,ans.end()));
	for_each(ans.begin(),ans.end(),[](int hoge){ cout<<hoge<<endl;});
	return 0;
}
