#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
int main()
{
    ll n,i;
    ll a[105],ans1=0,sum=0,temp,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n==0)
    {
        temp=sum/n;
        for(i=0;i<n;i++)
       {
        ans+=(a[i]-temp)*(a[i]-temp);
       }
    }
    else
    {
        temp=sum/n+1;
        for(i=0;i<n;i++)
       {
        ans+=(a[i]-temp)*(a[i]-temp);
        ans1+=(a[i]-temp-1)*(a[i]-temp-1);
       }
       if(ans1>ans)
        cout<<ans<<endl;
       else
        cout<<ans1<<endl;
    }


}
