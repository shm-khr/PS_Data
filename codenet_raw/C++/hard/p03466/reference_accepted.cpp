#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define ll long long
//#define file
using namespace std;

int T,n,s,s2,s3,i,j,k,l,A,B,C,D;
char ans[101];
bool bz;

void swap(int &x,int &y) {int z=x;x=y;y=z;}

int main()
{
	#ifdef file
	freopen("agc020D.in","r",stdin);
	#endif
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%d%d%d%d",&A,&B,&C,&D),bz=0;
		if (A<B) swap(A,B),C=(A+B)-C+1,D=(A+B)-D+1,swap(C,D),bz=1;
		s=ceil((double)A/(B+1));
		
		if (A>=B*s)
		{
			fo(i,C,D)
			ans[i-C+1]=(!(i%(s+1)))?'B':'A';
		}
		else
		{
			s2=(B*s-A)/(s*s-1);
			s3=(A-s2)+(A-s2)/s;
			fo(i,C,D)
			if (i<=s3)
			ans[i-C+1]=(!(i%(s+1)))?'B':'A';
			else
			ans[i-C+1]=(!(((A+B)-i+1)%(s+1)))?'A':'B';
		}
		
		if (!bz)
		{
			fo(i,1,D-C+1) putchar(ans[i]);
			putchar('\n');
		}
		else
		{
			fd(i,D-C+1,1) putchar(ans[i]=='A'?'B':'A');
			putchar('\n');
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}