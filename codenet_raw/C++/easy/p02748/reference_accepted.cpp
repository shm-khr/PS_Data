#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,m;
    cin>>a>>b>>m;
    int arr[a+1];
    int brr[b+1];
    arr[0]=brr[0]=2*(1e6);
    for(int i=1;i<=a;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=b;i++)
    {
        cin>>brr[i];
    }
    int ans = *min_element(arr,arr+a+1)+*min_element(brr,brr+b+1);
    while(m--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        ans = min(ans,arr[x]+brr[y]-c);

    }
    cout<<ans<<"\n";
    
}