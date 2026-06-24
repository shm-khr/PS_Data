#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+5;
int n,m,a[N],b[N],tree[4*N],tree2[4*N],lazy[4*N];
ll ans;
void initseg(int nd,int l,int r)
{
    if(l==r){ tree[nd]=b[l]; tree2[nd]=l; return; }
    int m=(l+r)/2;
    initseg(nd*2,l,m);
    initseg(nd*2+1,m+1,r);
    tree[nd]=tree[nd*2];
    tree2[nd]=l;
}
void pushdown(int nd,int l,int r)
{
    if(l!=r){
        lazy[nd*2]+=lazy[nd];
        lazy[nd*2+1]+=lazy[nd];
    }
    tree[nd]+=lazy[nd];
    lazy[nd]=0;
}
P query(int nd,int l,int r,int s,int e)
{
    if(r<s||e<l) return P(2e9,2e9);
    pushdown(nd,l,r);
    if(s<=l&&r<=e) return P(tree[nd],tree2[nd]);
    int m=(l+r)/2;
    P p1=query(nd*2,l,m,s,e);
    P p2=query(nd*2+1,m+1,r,s,e);
    if(p1.first>=p2.first) return p2;
    return p1;
}
void update(int nd,int l,int r,int s,int e)
{
    if(r<s||e<l) return;
    pushdown(nd,l,r);
    if(s<=l&&r<=e){
        lazy[nd]++;
        pushdown(nd,l,r);
        return;
    }
    int m=(l+r)/2;
    update(nd*2,l,m,s,e);
    update(nd*2+1,m+1,r,s,e);
    if(tree[nd*2]>=xtree[nd*2+1]){
        tree[nd]=tree[nd*2+1];
        tree2[nd]=tree2[nd*2+1];
    }
    else{
        tree[nd]=tree[nd*2];
        tree2[nd]=tree2[nd*2];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){ cin>>a[i]; b[i]=a[i]; }
    sort(b+1,b+1+n);
    m=unique(b+1,b+1+n)-b-1;
    initseg(1,1,m);
    for(int i=1;i<=n;i++){
        P tp=query(1,1,m,lower_bound(b+1,b+1+m,a[i])-b,m);
        ans+=(ll)tp.first-a[i];
        if(tp.second==1) continue;
        update(1,1,m,1,tp.second-1);
    }
    cout<<ans;
    return 0;
}