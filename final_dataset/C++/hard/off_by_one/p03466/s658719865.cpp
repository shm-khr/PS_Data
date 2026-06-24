#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2e3+10;
char s[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	int q=read();
	while(q--){
		int A=read(),B=read(),C=read(),D=read(),len=A+B;
		if(A>B){
			int Min=(A-1)/(B+1)+1,tmp=0;
			REP(i,1,len){
				if(!A) s[i]='B',--B;
				else if(tmp==Min){
					s[i]='B';
					--B;
					tmp=0;
					continue;
				}
				else{
					s[i]='A';
					--A;
					tmp++;
					if(Min*A<B){
						DREP(j,len,i+1){
							if((len-j+1)%(Min+1)==0) s[j]='A';
							else s[j]='B';
						}
						break;
					}
				}
			}
		}
		else{
			int Min=(B-1)/(A+1)+1,tmp=0;
			if(Min*A<B){
				DREP(j,len,1){
					if((len-j+1)%(Min+1)==0) s[j]='A';
					else s[j]='B';
				}
			}
			else REP(i,1,len){
				if(!A) s[i]='B',--B;
				else if(tmp==Min){
					s[i]='B';
					--B;
					tmp=0;
					continue;
				}
				else{
					s[i]='A';
					--A;
					tmp++; 
					if(Min*A<B){
						DREP(j,len,i+1){
							if((len-j+1)%(Min+1)==0) s[j]='A';
							else s[j]='B';
						}
						break;
					}
				}
			} 
//			DREP(i,len,1){
//				if(!B) s[i]='A',--A;
//				else if(tmp==Min){
//					s[i]='A';
//					tmp=0;
//					--A;
//					continue;
//				}
//				else{
//					s[i]='B';
//					--B;
//					tmp++;
//					if(Min*(B+1)==A){
//						REP(j,1,i-1){
//							if(j%(Min+1)==0) s[j]='B';
//							else s[j]='A';
//						}
//						break;
//					}
//				}
//			}
		}
		REP(i,C,D) putchar(s[i]);
		putchar('\n');
//		REP(i,1,len) putchar(s[i]);
//		putchar('\n');
	}
	return 0;
}