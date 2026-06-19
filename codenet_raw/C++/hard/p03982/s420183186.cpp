#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll a[100005],b[100005];
int n;
int main(){
	cin >> n;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	ll M = 0,Mval = 0; ll sidelazy = 0;
	multiset<pair<ll,ll>,greater<pair<ll,ll> > >S; ll lazy = 0;
	for(int i=0;i<n;i++){
	
		ll newM,newMval;
		if(M<=0){
			if(M != 0){
				S.insert(mp(M-sidelazy,-lazy)); 
			}
			sidelazy += b[i]-a[i]; M=b[i]-a[i]; lazy--;
		}
		else{
			ll cand = M,MIN = Mval+M,pre = M,val = Mval+M;
			for(multiset<pair<ll,ll>,greater<pair<ll,ll> > >::iterator it=S.begin();it!=S.end();it++){
				ll X = (*it).fi,Y = (*it).sc;
				ll Z = X+sidelazy;
				if(Z>0){
					if(Y+lazy+1<0){
						if(MIN >= val){
							MIN = val;
							cand = pre;
						}
					}
					else{
						if(MIN >= val- (Y+lazy+1) * (pre-Z)){
							MIN = val- (Y+lazy+1) * (pre-Z);
							cand = Z;
						}
					}
					val -= (Y+lazy+1) * (pre-Z);
					pre = Z;
				}
				else{
					if(Y+lazy+1<0){
						if(MIN >= val){
							MIN = val;
							cand = pre;
						}
					}
					else{
						if(MIN >= val- (Y+lazy+1) * pre){
							MIN = val- (Y+lazy+1) * pre;
							cand = 0;
						}
					}
					if(Y+lazy-1<0){
						if(MIN >= val- (Y+lazy+1) * pre){
							MIN = val- (Y+lazy+1) * pre;
							cand = 0ll;
						}
					}
					else{
						if(MIN >= val- (Y+lazy+1) * pre - (Y+lazy-1) * (-Z)){
							MIN = val- (Y+lazy+1) * pre - (Y+lazy-1) * (-Z);
							cand = Z;
						}
					}
					break;
				}
			}
			M = cand;
			Mval = MIN; lazy--; vector<pair<ll,ll> >vec;
			for(multiset<pair<ll,ll>,greater<pair<ll,ll> > >::iterator it=S.begin();it!=S.end();){
				if(sidelazy+(*it).fi>0){
					ll a = (*it).fi, x = (*it).sc;
					S.erase(it++);
					if(a+sidelazy>=M);
					else{
						vec.pb(mp(a,x+2));
					}
				}
				else{
					ll a = (*it).fi, x = (*it).sc;
					S.erase(it);
					if(a+sidelazy>=M);
					else{
						if(0<M) S.insert(mp(-sidelazy,x+2));
						if(a+sidelazy != 0 && a+sidelazy<M) S.insert(mp(a,x));
					}
					break;
				}
			}
			sidelazy += b[i]-a[i]; M += b[i]-a[i]; for(int i=0;i<vec.size();i++) S.insert(vec[i]);
		
		}
		
	}
	if(M<=0){
		cout << Mval << endl;
	}
	else{
		ll pre = M;
		for(multiset<pair<ll,ll>,greater<pair<ll,ll> > >::iterator it=S.begin();it!=S.end();it++){
			if(sidelazy+(*it).fi>0){
				Mval -= ((*it).sc+lazy) * (pre-(*it).fi-sidelazy);
				pre = (*it).fi+sidelazy;
			}
			else{
				Mval -= ((*it).sc+lazy) * (pre);
				break;
			}
		}
		cout << Mval << endl;
	}
}