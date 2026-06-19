#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
void solve()
{
	int A,B,C,D;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	int K=(max(A,B)+min(A,B))/(min(A,B)+1);
	int l=-1,r=B+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		long long AA=A-(long long)mid*K;
		long long BB=B-mid;
		if(AA<0||BB<0||BB>AA*K)r=mid;
		else l=mid;
	}
	int X=l*(K+1);A-=l*K;B-=l;
	int Y=X+(A*K-B)/K+1;A-=(A*K-B)/K+1;
	int Z=Y+B-A*K;
	for(int i=C;i<=D;i++)
		if(i<=X){
			if(i%(K+1))printf("A");
			else printf("B");
		}
		else if(i<=Y)printf("A");
		else if(i<=Z)printf("B");
		else{
			if((i-Z)%(K+1)==1)printf("A");
			else printf("B");
		}
	printf("\n");
	return ;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
		solve();
	return 0;
}