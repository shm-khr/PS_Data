#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a,b,c,aa,bb,cc,ans;
int main()
{
  cin>>aa>>bb>>cc;
    a=max(max(aa,bb),cc);
    b=min(max(min(aa,bb),cc),max(min(cc,bb),aa));
    c=min(min(aa,bb),cc); 
  while(1){
    if(a==b and c==a-1){
      a++;b++;
    }
    else{
      aa=a;
      bb=b+1;
      cc=c+1; 
      a=max(max(aa,bb),cc);
      b=min(max(min(aa,bb),cc),max(min(cc,bb),aa));
      c=min(min(aa,bb),cc); 
    }
    ans++;//cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==b and a==c){
      cout<<ans<<endl;
      system("pause");
      return 0;
    }
    aa=a;
    bb=b;
    cc=c+2;
    a=max(max(aa,bb),cc);
    b=min(max(min(aa,bb),cc),max(min(cc,bb),aa));
    c=min(min(aa,bb),cc); 
    ans++;//cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==b and a==c){
      cout<<ans<<endl;
      system("pause");
      return 0;
    }
  }
  system("pause");
  return 0;
}