#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
ll x,n,s1=0,s2=0,s=0,i;
cin>>n;
int a[n],b[n];

for(i=0;i<n;i++)
{  cin>>a[i];
    if(i) s1+=a[i];
    else s+=a[i];
} 
 
 for(i=0;i<n;i++)
 {
     cin>>b[i];
     if(i==n-1)s+=b[i];
     else s2+=b[i];
     
 }
 
 for(i=0;i<n-1;i++)
 {   if(a[i+1]>b[i])s+=a[i+1],s1-=a[i+1],s2-=b[i];
    else if(s2>=s1)
     {
         s+=s2;break;
     }
     else s1-=a[i+1],s2-=b[i],s+=a[i+1];
 }
    cout<<s;
}