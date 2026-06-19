#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,at=0;
  cin>>a>>b>>c>>x;
  for(int i=0;i<=a;i++){
    for(int j=0;j<=b;j++){
      for(int k=0;k<=c;k++){
        if(500*a+100*b+50*c==x){
          at++;
        }
      }
    }
  }
  cout<<at<<endl;
}