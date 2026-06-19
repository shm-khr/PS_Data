#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=50005;
bitset<N> s[N];
int x[N],y[N],vis[N];
char ans[N];
void GG(){
	puts("-1"); exit(0);
}
int main(){
	
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),m=read(),T=read(),tot=n;
	For(i,1,n)s[i][i]=1;
	For(i,1,m){
		x[i]=read(); y[i]=read();
		s[x[i]]=s[y[i]]=s[x[i]]|s[y[i]];
	}
	For(i,1,n)if(s[i].count()==n){
		vis[i]=1;
		Rep(j,m,1){
			//cout<<x[i]<<" "<<vis[x[i]]<<endl;
			if(vis[x[j]])ans[j]='^'; else ans[j]='v';
			vis[x[j]]=vis[y[j]]=vis[x[j]]|vis[y[j]];
		}
		cout<<(ans+1)<<endl; return 0;
	}
	GG();
}
