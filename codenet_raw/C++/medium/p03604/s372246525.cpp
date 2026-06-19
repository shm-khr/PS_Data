#include<bits/stdc++.h>
using namespace std;
#define N 1111116
#define mod 1000000007
#define next nxt

int n,x[N],y[N],z[N],next[N],p[N],h[N],q[N],f[N],g[N],s[N],cnt,cmt,cir;
long long fac[N],inv[N],ans;
vector<int> v[N];

long long C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

void travel(int x,int pre){
	h[x]=true;q[++cnt]=x;
	for (int t=p[x];t;cmt++,t=next[t])
		if (!h[y[t]]) travel(y[t],t);
		else if (t/2!=pre/2) cir=t;
}

void build(int x,int pre){
	for (int t=p[x];t;t=next[t])
		if (t/2!=pre/2){
			if (y[t]<y[pre^1]) v[x].push_back(y[t]),f[y[t]]=true;
			if (t/2!=cir/2) g[y[t]]=x,build(y[t],t);
		}
}

long long solve(int x){
	s[x]=0;long long ans=1;
	for (int i=0;i<(int)v[x].size();i++){
		ans=ans*solve(v[x][i])%mod;
		s[x]+=s[v[x][i]];
		ans=ans*C(s[x],s[v[x][i]])%mod;
	}
	s[x]++;return ans;
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	for (int i=1;i<=2*n;i++){
		x[2*i]=y[2*i+1]=read();
		y[2*i]=x[2*i+1]=n+read();
		z[2*i]=z[2*i+1]=x[2*i]+y[2*i];
		next[2*i]=p[x[2*i]];p[x[2*i]]=2*i;
		next[2*i+1]=p[x[2*i+1]];p[x[2*i+1]]=2*i+1;
	}
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=2;i<N;i++) inv[i]=-(mod/i)*inv[mod%i]%mod;
	for (int i=2;i<N;i++) inv[i]=inv[i-1]*inv[i]%mod;
	ans=fac[2*n];
	for (int i=1;i<=2*n;i++)
		if (!h[i]){
			cnt=cmt=0;travel(i,0);
			if (cmt!=cnt*2) {printf("0\n");return 0;}
			
			v[0].clear();
			for (int i=1;i<=cnt;i++)
				v[q[i]].clear(),g[q[i]]=0,f[q[i]]=false;
			build(x[cir],cir);
			for (int i=1;i<=cnt;i++)
				if (!f[q[i]]) v[0].push_back(q[i]);
			long long tmp=solve(0);
			
			v[0].clear();
			for (int i=1;i<=cnt;i++)
				v[q[i]].clear(),g[q[i]]=0,f[q[i]]=false;
			build(y[cir],cir);
			for (int i=1;i<=cnt;i++)
				if (!f[q[i]]) v[0].push_back(q[i]);
			tmp+=solve(0);
			
			ans=ans*tmp%mod*inv[cnt]%mod;
		}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}