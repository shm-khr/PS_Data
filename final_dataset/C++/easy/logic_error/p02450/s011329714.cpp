#include<bits/stdc++.h>
using namespace std;
#define lp(n) for(int i=0;i<n;i++)
void out(int a[],int n){
  lp(n){
    if(i!=0) cout<<" ";
      cout<<a[i];
  }
  cout<<endl;
  return;
}
int main(){
  int n,a[10];
  cin>>n;
  for(int i=0;i<n;i++){
    a[i]=i+1;
  }
  while(next_permutation(a,a+n)){
    out(a,n);
  }
  return 0;
}

