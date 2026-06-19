#include <bits/stdc++.h>
using namespace std;
int main(){
  int n=0;
  cin>>n;
  vector<int> shorui(n);
  for(int i=0;i<n;i++){
    cin>>shorui.at(i);
  }
  
  for(int i=0;i<n;i++){
    int sum=0;
    if(shorui.at(i)%2==0){
      
      if(shorui.at(i)%3==0||shorui.at(i)%5==0){
        cout<<"APPROVED"<<endl;
        return 0;
      }else{
        cout<<"DENIED"<<endl;
        return 0;
      }
      sum++;
    }
    if(i==n-1&&sum==0)cout<<"APPROVED"<<endl;
  }
  
}