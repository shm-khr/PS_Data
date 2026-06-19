#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[3][n+1],i,j;
    for (i=1;i<=2;i++)
    {
    	for (j=1;j<=n;j++)
    	{
    		cin>>a[i][j];
    	}
    }
    if (n==1)
    {
    	cout<<a[1][1]+a[2][1]<<endl;
    	return 0;
    }
    int ans=0;
    int h1[n+1],h2[n+1];
    for (i=1;i<=n;i++)
    {
    	h1[i]=0;
    	h2[i]=0;
    	for (j=n;j>=i;j--)
    	{
    		h1[i]+=a[1][j];
    		h2[i]+=a[2][j];
    	}
    }
    //cout<<h1[1]<<" "<<h2[1]<<endl;
    for (i=n;i>=1;i--)
    {
    	if (h1[i]<h2[i-1])
    	{
    		ans+=h2[i-1];
    		for (j=1;j<=i-1;j++)
    		{
    			ans+=a[1][j];
    		}
			cout<<ans<<endl;
			return 0;
    	}
    }
    cout<<h1[1]+a[2][n]<<endl;
    return 0;
}