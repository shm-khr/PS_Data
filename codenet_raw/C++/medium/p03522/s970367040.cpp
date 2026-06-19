#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];

struct node
{
	int v,lazy;
};

const int INF = int(1e9);

node st[222222*4];
void build(int id, int l, int r)
{
	st[id].lazy=0;st[id].v=INF;
	if(r-l>=2)
	{
		int mid=(l+r)>>1;
		build(id*2,l,mid); build(id*2+1,mid,r);
	}
}

void push(int id, int l, int r)
{
	if(st[id].lazy!=0)
	{
		st[id].v+=st[id].lazy;
		if(r-l>=2)
		{
			st[id*2].lazy+=st[id].lazy; st[id*2+1].lazy+=st[id].lazy;
		}
		st[id].lazy=0;
	}
}

void update(int id, int l, int r, int pos, int v)
{
	push(id,l,r);
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[id].v=v; return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,pos,v); update(id*2+1,mid,r,pos,v);
	st[id].v=min(st[id*2].v,st[id*2+1].v);
}

void updaterange(int id, int l, int r, int ql, int qr, int v)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return ;
	if(ql<=l&&r<=qr)
	{
		st[id].lazy+=v; push(id,l,r); return ;
	}
	int mid=(l+r)>>1;
	updaterange(id*2,l,mid,ql,qr,v); updaterange(id*2+1,mid,r,ql,qr,v);
	st[id].v=min(st[id*2].v,st[id*2+1].v);
}

ii query(int id, int l, int r, int ql, int qr)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return mp(INF, -1);
	if(ql<=l&&r<=qr) return mp(st[id].v, l);
	int mid=(l+r)>>1;
	return min(query(id*2,l,mid,ql,qr),query(id*2+1,mid,r,ql,qr));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	pbds T; int timer = 0; vi S;
	ll ans = 0; build(1,0,n);
	for(int i=0;i<n;i++)
	{
		int aft = T.order_of_key(mp(a[i]+1,-1)) - 1;
		int mn = i-1-aft;
		if(mn==0)
		{
			T.insert(mp(a[i],++timer));			
			if(S.empty()||S.back()!=a[i]) 
			{
				S.pb(a[i]);
				update(1,0,n,S.size(),a[i]-i);
			}
			else
			{
				update(1,0,n,S.size()-1,a[i]-i);
			}
			continue;
		}
		int id = upper_bound(S.begin(),S.end(),a[i])-S.begin();
		id--;
		aft=id;
		ii X = query(1,0,n,id+1,n);
		if(X.fi+i-1-a[i]<mn)
		{
			mn=X.fi+i-1-a[i];
			aft=X.se;
		}
		//cerr<<"MN "<<mn<<' '<<"AFT "<<aft<<'\n';
		ans+=mn;
		updaterange(1,0,n,aft+1,n,-1);
		if(aft>=0) 
		{
			int pos = T.order_of_key(mp(S[aft]+1,-1));
			//cerr<<S[aft]<<' '<<pos<<'\n';
			T.insert(mp(S[aft],++timer));
			update(1,0,n,aft,S[aft]-pos);
		}
		else T.insert(mp(a[i],++timer));
	}
	cout<<ans<<'\n';
}
