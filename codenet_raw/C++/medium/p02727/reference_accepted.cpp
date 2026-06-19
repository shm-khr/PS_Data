#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;

template<class T>void read(T &x){
    T s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    x = s*w;
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
int X,Y,A,B,C;
int a[maxn],b[maxn],c[maxn];
void solve(){
	ll ans = 0;
	sort(a+1,a+A+1,greater<int>());
	sort(b+1,b+B+1,greater<int>());
	sort(c+1,c+C+1,greater<int>());
	int taila = X,tailb = Y;
	for(int i = 1;i<=X;i++) ans += a[i];
	for(int i = 1;i<=Y;i++) ans += b[i];
	for(int i = 1;i<=min(C,X+Y);i++){
		if(taila && tailb){
			if(c[i] <= min(a[taila],b[tailb])) break;
			if(a[taila] <= b[tailb]){
				ans = ans + c[i]-a[taila];
				taila--;
			}else{
				ans = ans + c[i]-b[tailb];
				tailb--;
			}
		}else if(taila == 0){
			if(c[i] <= b[tailb]) break;
			ans = ans + c[i] - b[tailb];
			tailb--;
		}else if(tailb == 0){
			if(c[i] <= a[taila]) break;
			ans = ans + c[i] - a[taila];
			taila--;
		}
	}
	printf("%lld\n",ans);
}	
int main(){
	// debug;
	
	read(X,Y,A,B,C);
	for(int i = 1;i<=A;i++) read(a[i]);
	for(int i = 1;i<=B;i++) read(b[i]);
	for(int i = 1;i<=C;i++) read(c[i]);
	solve();
	return 0;
}
