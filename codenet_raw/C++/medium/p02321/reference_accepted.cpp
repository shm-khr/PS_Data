#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define SIZE 200005
#define INF 1000000005LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N;
ll W,v[50],w[50];
pair<ll,ll> ps[1<<20];

int main()
{
	scanf("%d%lld",&N,&W);
	for(int i=0;i<N;i++)scanf("%lld%lld",&v[i],&w[i]);
	int n2 = N/2;
	for(int S=0;S<1<<n2;S++){
		ll v1=0,w1=0;
		for(int i=0;i<n2;i++){
			if(S>>i&1){
				v1 += v[i];
				w1 += w[i];
			}
		}
		ps[S] = make_pair(w1,v1);
	}
	sort(ps,ps+(1<<n2));
	//無駄な要素をけす（wが大きくvが小さいものをなくす）
	int m=1;
	for(int S=1;S<1<<n2;S++){
		if(ps[m-1].second < ps[S].second){
			ps[m++] = ps[S];
		}
	}
	ll res=0;
	for(int S=0;S<1<<(N-n2);S++){
		ll v2=0,w2=0;
		for(int i=0;i<N-n2;i++){
			if(S>>i&1){
				v2 += v[n2+i];
				w2 += w[n2+i];
			}
		}
		if(w2<=W){
			ll V = (upper_bound(ps,ps+m,make_pair(W-w2,INF))-1) -> second;
			res = max(res,V+v2);
		}
	}
	printf("%lld\n",res);
	return 0;
}

