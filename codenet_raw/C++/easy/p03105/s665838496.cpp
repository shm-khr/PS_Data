#include<iostream>
using namespace std;
int main()
{
   int a,b,c,cnt=0,ans=0;
   cin>>a>>b>>c;
   if(b<a)
   {
   	cout<<0;
   	return 0;
   }
   for(int i=1;i<=c;i++)
   {
   	cnt++;
   	ans+=a;
   	if(ans>=b)
   	{
   		break;
   	}
   }
   
   cout<<cnt;
}