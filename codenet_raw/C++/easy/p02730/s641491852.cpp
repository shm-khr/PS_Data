#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool kaibun(string S){
  for(int i=0;i<S.size()/2;i++){
    if(S.at(i)!=S.at(S.size()-i-1)){
       return false;
    }
  }
       return true;
}

int main(){
  string S;
  cin>>S;
  string mae,ato;
  for(int i=0;i<(S.size()-1)/2;i++)
    mae.push_back(S.at(i));
  for(int i=(S.size()+1)/2;i<S.size();i++)
    ato.push_back(S.at(i));
  //cout<<mae<<" "<<ato<<endl;
  
  if(kaibun(mae)&kaibun(ato))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
} 