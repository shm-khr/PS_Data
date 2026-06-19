#include<bits/stdc++.h>
using namespace std;

int main ()
{
long n,i,j,k=0;
cin>>n;
long  A[n];
for(i=0;i<n;i++)
cin>>A[i];
sort(A,A+n);
for(j=1;j<n;j++)
{
  for(i=0;i<j;i++)
  {
   if(A[j]%A[i]==0)
   {
     k++;
     break;
   }
  }

}
if(A[0]==A[1]) k++;
cout<<n-k<<endl;

  return 0;
}
