#include <bits/stdc++.h>
#define N 200010
using namespace std;
typedef int ll;
ll p[N];
map<ll,ll>mp;
      ll a;
bool check(ll k)
{
  mp.clear();
    for(ll i=2;i<=a;i++)
        if(p[i]>p[i-1])
        continue;
    else
    {
        if(k==1)
            return false;
    
    
       while(mp.size()){
        ll u=mp.rbegin() -> first;
        if(u>p[i])
        mp.erase(u);
        else
            break;
       }


        ll j=p[i];
        while(j&&mp[j]+1==k)
        {

            mp.erase(j);
              j--;
        }
       if(j==0)
        return false;
       mp[j]++;
    }
    return true;



}
int main() {


        cin>>a;
        for(ll i=1;i<=a;i++)
            cin>>p[i];

        ll l=1,r=a,mid;


        while(l<r)
        {
            mid=(l+r)>>1;
            if(check(mid))
                r=mid;
            else
                l=mid+1;
        }

        cout<<l<<endl;
    return 0;
}
