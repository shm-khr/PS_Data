#include<bits/stdc++.h>
#define N 200005
using namespace std;
const int p = 1000000007;
int n;
int head[N],ver[N],nxt[N],tot;
void add(int a,int b)
{
    tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;return ;
}
int jie[N],ni[N];
int c(int x,int y)
{
    return 1LL*jie[x]*ni[y]%p*ni[x-y]%p;
}
int v[N],dian,bian,st[N],top;
int pi[N],cir[N],sz,q[N];
void dfs(int x,int fa)
{
    st[++top]=x;
    v[x]=1;q[++dian]=x;
    for(int i=head[x];i;i=nxt[i])
    {
        bian++;
        if(!v[ver[i]])dfs(ver[i],x);
        else if(ver[i]!=fa&&!sz)
        {
            for(int j=top;j>=1;j--)
            {
                cir[++sz]=st[j];
                if(st[j]==ver[i])break;
            }
        }
    }
    top--;
    return ;
}
int now;
void sao(int x,int f)
{
    for(int i=head[x];i;i=nxt[i])
    {
        if(ver[i]==f)continue;
        pi[ver[i]]=x;
        if(ver[i]==now)continue;
        sao(ver[i],x);
    }
}
vector<int>vv[N];
int size[N],fa[N],f[N];
void dp(int x)
{
    f[x]=1;size[x]=1;
    for(int i=0;i<vv[x].size();i++)
    {
        dp(vv[x][i]);
        size[x]+=size[vv[x][i]];
        f[x]=1LL*f[x]*f[vv[x][i]]%p*c(size[x]-1,size[vv[x][i]])%p;
    }
}
int solve()
{
    for(int j=1;j<=dian;j++)fa[q[j]]=0;
    for(int j=1;j<=dian;j++)
    {
        int u=q[j];vv[u].clear();
        for(int k=head[u];k;k=nxt[k])
        {
            if(ver[k]<pi[u])
            {
                //if(u==9&&ver[k]==5)cout<<pi[9]<<'s'<<endl;
                vv[u].push_back(ver[k]),fa[ver[k]]=u;
            }
        }
    }
    int ans=1;int szzz=0;
    for(int j=1;j<=dian;j++)
    {
        if(!fa[q[j]])
        {
            dp(q[j]);szzz+=size[q[j]];
            ans=1LL*ans*f[q[j]]%p*c(szzz,size[q[j]])%p;
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    jie[0]=ni[0]=ni[1]=1;
    for(int i=1;i<=2*n;i++)jie[i]=1LL*jie[i-1]*i%p;
    for(int i=2;i<=2*n;i++)ni[i]=1LL*(p-p/i)*ni[p%i]%p;
    for(int i=2;i<=2*n;i++)ni[i]=1LL*ni[i-1]*ni[i]%p;
    for(int i=1;i<=2*n;i++)
    {
        int t1,t2;scanf("%d%d",&t1,&t2);
        add(t1,t2+n);add(t2+n,t1);
    }
    int ans=1;int nw=2*n;
    for(int i=1;i<=2*n;i++)
    {
        if(v[i])continue;
        dian=sz=bian=0;
        dfs(i,-1);bian/=2;
        if(dian!=bian)return puts("0"),0;
        now=cir[sz];
        sao(cir[sz],-1);
        cir[sz+1]=cir[1];
        int as=solve();

        for(int j=1;j<=sz;j++)pi[cir[j]]=cir[j+1];
        //cout<<pi[9]<<' '<<pi[5]<<' '<<pi[15]<<endl;
        as+=solve();
        ans=1LL*ans*c(nw,dian)%p*as%p;
        nw-=dian;
    }
    cout<<ans<<endl;
    return 0;
}
