#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
  ll a,b,c,x,count=0;
  cin>>a>>b>>c>>x;
  for(ll i=0;i<=a;i++){
    for(ll j=0;j<=b;j++){
      for(ll k=0;k<=c;k++){
        if((i*500+j*100+k*50)==x){
          count++;
          }
        }
      }
    }
  cout<<count<<endl;
  }