
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[10],n,b[10];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  if(prev_permutation(a,a+n)==false) 1;
  else{
    for(int i=0;i<n;i++){
      if(i!=0) cout<<" ";
      cout<<a[i];
    }
    cout<<endl;
  }
  for(int i=0;i<n;i++){
    if(i!=0) cout<<" ";
    cout<<b[i];
  }
  cout<<endl;
  if(next_permutation(b,b+n)==true){
    for(int i=0;i<n;i++){
      if(i!=0) cout<<" ";
      cout<<b[i];
    }
    cout<<endl;
  }
  return 0;
}

