// #include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <iterator>
#include <functional>
#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define trace(x) cerr << #x << ": " << x << " " << endl;
 
typedef int64_t ll;
 
#define endl '\n'
#define int ll
ll mod=1e9+7;
ll mod1=1e9+5;
ll power(ll a,ll b)
{
    if(b==0) return 1;
    else if(b%2==0)
        return power(((((a)%mod)*((a)%mod))%mod),b/2)%mod;
    else return (((a)%mod)*(power(((((a)%mod)*((a)%mod))%mod),b/2)%mod))%mod;
}
inline ll inverse(ll a,ll md) {
  a %= md;
  if (a < 0) a += md;
  ll b = md, u = 0, v = 1;
  while (a) {
    ll t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
  
  
 //using namespace __gnu_pbds;
 //#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//find_by_order(k)  returns iterator to kth element starting from 0;
//order_of_key(k) returns count of elements strictly smaller than k;
//erase,insert same as normal set
// mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count()); for randomized solution
const int ce=1e9+7;
ll fast_mod(ll input)
{
    return input < ce ? input : input%ce;
}
#define pi 3.14159
vector<int> v[2001];
vector<int> eu;
int n;
int a[20001];
int st[400001];
int en[400001];
set<int> s[200001];
int rev[400001];
int rev1[400001];
int sub[200001];
set<int> s1[200001];
void dfs(int u,int par)
{
	eu.push_back(u);
	for(auto i:v[u])
	{
		if(i==par)
			continue;
		dfs(i,u);
	}
	eu.push_back(-u);
}
int ans[200001];
void comp(int u,int par)
{
	sub[u]=1;
	for(auto i:v[u])
	{
		if(i==par)
			continue;
		comp(i,u);
		sub[u]+=sub[i];
	}
	vector<int> te;
	int x=n-sub[u];
	auto it1=s1[a[u]].lower_bound(st[u]);
	if(it1!=s1[a[u]].begin())
	{
		it1--;
		x-=sub[rev1[*it1]];
	}
	
	te.push_back(x);
	for(auto i:v[u])
	{
		if(i==par)
			continue;
		auto it=s[a[u]].lower_bound(st[i]);

		if(it==s[a[u]].end())
		{
			te.push_back(sub[i]);
			continue;
		}
		if(*it>en[i])
		{
			te.push_back(sub[i]);
			continue;
		}
		te.push_back(sub[i]-sub[rev[*it]]);
	}
	int sum=0;
	for(auto i:te)
		sum+=i;
	sum++;
	for(auto i:te)
	{
		ans[a[u]]+=(sum-i)*i;
		sum-=i;
	}

	ans[a[u]]++;

}
int32_t main()
{
    IOS
    
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(ans,0,sizeof(ans));
	dfs(1,0);

	for(int i=0;i<(int)eu.size();i++)
	{
		if(eu[i]>0)
		{
			rev[i]=eu[i];
			st[eu[i]]=i;
		}
		else
		{
			en[abs(eu[i])]=i;
			rev1[i]=abs(eu[i]);
		}
	}

	for(int i=1;i<=n;i++)
	{
		s[a[i]].insert(st[i]);
		s1[a[i]].insert(en[i]);
	}

	comp(1,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
}       