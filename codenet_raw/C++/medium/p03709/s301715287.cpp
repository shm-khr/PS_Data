#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define v first
#define x second
using namespace std;
const int nmax=200005;
const int mod=1000*1000*1000+7;
pair<int,int> a[nmax];
vector<int> lst[nmax];
int dp[nmax],sum[nmax],mx[nmax],mn[nmax],l[nmax],r[nmax];
int n,i,j,p,add;
int main()
{
   // freopen("data.in","r",stdin);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].v;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        mx[i]=max(mx[i-1],a[i].x);l[i]=i;
        for(p=17;p>=0;p--)
            if(l[i]-(1<<p)>0&&mx[l[i]-(1<<p)]>=a[i].x)
               l[i]-=(1<<p);
    }
    mn[n+1]=(1<<30);
    for(i=n;i>=1;i--)
    {
        mn[i]=min(mn[i+1],a[i].x);r[i]=i;
        for(p=17;p>=0;p--)
            if(r[i]+(1<<p)<=n&&mn[r[i]+(1<<p)]<=a[i].x)
              r[i]+=(1<<p);
    }
    for(i=1;i<=n;i++)
    {
        lst[r[i]].push_back(l[i]-1);
    }
    dp[0]=1;sum[0]=1;
    for(i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        for(j=0;j<lst[i].size();j++)
        {
            add=sum[i];
            if(lst[i][j])
                add-=sum[lst[i][j]-1];
            add%=mod;
            if(add<0) add+=mod;
            dp[i]+=add;if(dp[i]>=mod) dp[i]-=mod;
            sum[i]+=add;if(sum[i]>=mod) sum[i]-=mod;
        }
    }
    cout<<dp[n];
    return 0;
}
