#include<iostream>
#include<string>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int a[81];
	int b[81];
	int ans[81];
	int n;
	cin>>n;
	rep(j,n){
		rep(i,81){
			a[i]=b[i]=ans[i]=0;
		}
		string s[2];
		cin>>s[0];
		int cnt=80;
		for(int i=s[0].size()-1;i>=0;i--){
			a[cnt]=s[0][i]-'0';
			cnt--;
		}
		cin>>s[1];
		if(s[0].size()>80 || s[1].size()>80){
			cout<<"overflow"<<endl;
			continue;
		}
		cnt=80;
		for(int i=s[1].size()-1;i>=0;i--){
			b[cnt]=s[1][i]-'0';
			cnt--;
		}
		bool check=true;
		for(int i=80;i>=0;i--){
			ans[i]=a[i]+b[i];
			//cout<<i<<":"<<a[i]<<"+"<<b[i]<<"="<<ans[i]<<endl;
			if(ans[i]>=10){
				a[i-1]++;
				ans[i]%=10;
			}
		}
		if(ans[0]>0){
			cout<<"overflow"<<endl;
			check=false;
		}
		int ite=0;
		rep(i,81){
			if(ans[i]!=0){
				ite=i;
				break;
			}
		}
		if(check){
			for(int i=ite;i<81;i++){
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
	return 0;
}