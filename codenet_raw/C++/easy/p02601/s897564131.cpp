#include <iostream>

using namespace std;

int check(int a,int b,int c)
{
	if(c>b and b>a) return 1;
	else return 0;
}

int main()
{
	int a,b,c,k;cin>>a>>b>>c>>k;

	bool flag=false;
	int count=0;

	while(count<=k)
	{	

		if(b<a) {b=b*2;count++;}
		else if(c<b) {c=c*2;count++;} 
		else {a=a*2;count++;}
	}
	if(check(a,b,c)) flag=true;
	if(flag) cout<<"Yes";
	else cout<<"No";
}