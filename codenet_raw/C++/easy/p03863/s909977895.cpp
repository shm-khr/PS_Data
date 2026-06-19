#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define ll long long
#define rep(x,n) for(ll (x)=0;(x)<n;(x)++)
#define rep1(x,n) for(ll (x)=1;(x)<=n;(x)++)
using namespace std;

char s[300005];

int main()
{
    #ifdef LOCAL
        freopen("B_data","r",stdin);
    #endif
    while(cin>>s)
    {
        ll cnt[27],len=strlen(s),mx=0;
        memset(cnt,-1,sizeof(cnt));
        rep(i,len)
        {
            if(cnt[s[i]-'a']==-1)  cnt[s[i]-'a']=i;
            else mx=max(mx,i-cnt[s[i]-'a']-1);
        }
        if(mx%2) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    return 0;
}
