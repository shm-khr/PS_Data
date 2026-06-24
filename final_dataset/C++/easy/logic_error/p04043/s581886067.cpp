#include<iostream>
int main(){
int a[3],s=0,f=0;
for(int i=0;i<3;i++)
{cin>>a[i];
if(a[i]==5)f++;
if(a[i]==7)s++;}
if(f==2&&s==1)
cout<<"YES"
else cout<<"NO"; 
return 0;}