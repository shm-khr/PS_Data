#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mi,mx,d,l,h,su=0,su1=0,su2=0,su3=0,su4=0,arr[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0){mi=arr[i]; mx=arr[i];}
        else{

            if(mi>arr[i]){mi=arr[i];}
            if(mx<arr[i]){mx=arr[i];}
        }
    }
    d=mx-mi;
    d=d/2;
    l=mi+d;
    h=mx-d;
    for(int i=0;i<n;i++)
    {
      su+=pow((arr[i]-mi),2) ;
      su1+=pow((arr[i]-mx),2);
      su2+=pow((arr[i]-l),2);
      su3+=pow((arr[i]-h),2);
    }
 su=min(su,su1);
 su=min(su,su2);
 su=min(su,su3);
 cout<<su<<endl;
}
