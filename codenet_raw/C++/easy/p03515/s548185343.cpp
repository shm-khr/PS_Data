#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
typedef vector<int>vi;
vector<vi>adjlist;
vector<iii>edge;
const int N=1e5+5;
long long ans[N],lazy[N];
int pa[N],sz[N];
void unionset(int x,int y,int w)
{
    x=pa[x];
    y=pa[y];
    if(sz[x]<sz[y]){
        lazy[y]+=sz[x]*w;
        for(int i=0;i<adjlist[x].size();++i){
            int v=adjlist[x][i];
            pa[v]=y;
            adjlist[y].push_back(v);
            ans[v]+=lazy[x];
            ans[v]+=sz[y]*w;
            ans[v]-=lazy[y];
        }
        sz[y]+=sz[x];
    }
    else{
        lazy[x]+=sz[y]*w;
        for(int i=0;i<adjlist[y].size();++i){
            int v=adjlist[y][i];
            pa[v]=x;
            adjlist[x].push_back(v);
            ans[v]+=lazy[y];
            ans[v]+=sz[x]*w;
            ans[v]-=lazy[x];
        }
        sz[x]+=sz[y];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    adjlist.assign(n+1,vi());
    for(int i=1;i<=n;++i){
        adjlist[i].push_back(i);
        pa[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge.push_back(iii(w,ii(u,v)));
    }
    sort(edge.begin(),edge.end());
    reverse(edge.begin(),edge.end());
    for(int i=0;i<edge.size();++i){
        unionset(edge[i].second.first,edge[i].second.second,edge[i].first);
    }
    int root=0;
    for(int i=1;i<=n;++i)if(pa[i]==i)root=i;
    for(int i=0;i<adjlist[root].size();i++)ans[adjlist[root][i]]+=lazy[root];
    for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
}
