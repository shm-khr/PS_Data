#include<bits/stdc++.h>
using namespace std;
vector<int> split(int x,int n) {
	vector<int> v(n+1,0);
	for(;x;) {
		if (x>=n) {
			for(int i=1;i<=n;i++) v[i]++;
			x-=n;
		} else if (v[1]==0) {
			for(int i=1;i<=x;i++) v[i]++;
			x=0;
		} else {
			for(int i=n;i>=n-x+1;i--) v[i]++;
			x=0;
		}
	}
	return v;
}
pair<bool,string> check(int a,int b,int m,int x) {
	vector<int> v,v1;
	v=split(b,m);
	v1=split(a,m);
//	for(int i=1;i<(int)v1.size();i++) cerr<<v1[i]<<" ";cerr<<endl;
	reverse(v1.begin()+1,v1.end());
	bool flag=true;
	string s="";
//	cerr<<m<<"  :  ";
	for(int i=1;i<=m;i++) {
//		cerr<<v1[i]<<" "<<v[i]<<" ";
		while (v1[i]--) s+='A';
		while (v[i]--) s+='B';
	}
	for(int i=0;i<a+b;i++) {
		int j=i;
		while (j+1<a+b&&s[j+1]==s[j]) j++;
		if (j-i+1>x) {
			flag=false;break;
		}
	}
	return {flag,s};
}
string solve(int a,int b) {

	int n,x,y;
	string s="",sa="",sb="";
	n=ceil(max(a,b)*1.0/(min(a,b)+1));
	//cout<<n<<endl; 
	x=min(b*1.0,ceil((3.0*a-b)/8));
	y=min(a*1.0,ceil((3.0*b-a)/8));
	//cout<<x<<" "<<y<<endl;
	if (x<0) x=0;
	if (y<0) y=0;
	for (int i=0;i<n;i++){
		sa=sa+'A';
		sb=sb+'B';
	}
	sa=sa+'B';
	sb='A'+sb; 
	//cout<<sa<<" "<<sb<<endl;
	//拼接起始A..AB 
	for(int i=0;i<x;i++){
		s=s+sa;
	}
	
	if (n>1){
		//拼接中间A 
		for(int i=0;i<a-n*x-y;i++){
			s=s+'A';
		}
		//拼接中间B 
		for(int i=0;i<b-x-n*y;i++){
			s=s+'B';
		}
	}
	
	//拼接末尾AB..B 
	for(int i=0;i<y;i++){
		s=s+sb;
	}
		
	if(n==1){
		if(a-n*x-y==1) s=s+'A';
		if(b-x-n*y==1) s='B'+s;
	} 
	return s;
	
}
string ans(int a,int b,int c,int d) {
	return solve(a,b).substr(c-1,d-c+1);
}
int q,a,b,c,d;
string sa,sb,s;
int main() {
	
	scanf("%d",&q);
	while (q--) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
	int n,x,y;
	s="",sa="",sb="";
	n=ceil(max(a,b)*1.0/(min(a,b)+1));
	//cout<<n<<endl; 
	x=min(b*1.0,ceil((3.0*a-b)/8));
	y=min(a*1.0,ceil((3.0*b-a)/8));
	//cout<<x<<" "<<y<<endl;
	if (x<0) x=0;
	if (y<0) y=0;
	for (int i=0;i<n;i++){
		sa+='A';
		sb+='B';
	}
	sa+='B';
	sb='A'+sb; 
	//cout<<sa<<" "<<sb<<endl;
	//拼接起始A..AB 
	for(int i=0;i<x;i++){
		s+=sa;
	}
	
	if (n>1){
		//拼接中间A 
		for(int i=0;i<a-n*x-y;i++){
			s+='A';
		}
		//拼接中间B 
		for(int i=0;i<b-x-n*y;i++){
			s+='B';
		}
	}
	
	//拼接末尾AB..B 
	for(int i=0;i<y;i++){
		s+=sb;
	}
		
	if(n==1){
		if(a-n*x-y==1) s+='A';
		if(b-x-n*y==1) s='B'+s;
	} 
		//cout<<s.substr(c-1,d-c+1)<<endl;
		printf("%s\n",s.substr(c-1,d-c+1).c_str());
	}
	return 0;
}