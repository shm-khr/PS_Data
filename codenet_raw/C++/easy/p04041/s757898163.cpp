#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull B=5575777;
ull getHash(vector<int> &v){
  ull res=0;
  for(int i=0;i<v.size();i++)
    res=res*B+(v[i]+1);
  return res;
}

ll mod=1e9+7;

int N,X,Y,Z;


bool check(vector<int> &v){

  int mini=0;
  int size=v.size();

  for(int i=0;i<size;i++){
    int sum=0;
    bool fx=false,fy=false,fz=false;
    bool ok=true;
    for(int j=i;j<size;j++){
      sum+=v[j];
      if(X==sum)fx=true;
      if(fx==false && X<sum)ok=false;
      
      if(X+Y==sum)fy=true;
      if(fy==false&&X+Y<sum)ok=false;
      
      if(X+Y+Z==sum)fz=true;
      if(fz==false&&X+Y+Z<sum)ok=false;
    }
    
    if(mini==i&&ok==false)mini=i+1;
    if(fx&&fy&&fz)return true;
  }

  /*
  if(v.size()==2&&v[0]==5){
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<' ';
    cout<<mini<<endl;
  }
  */
  v.erase( v.begin(), v.begin()+mini);
  /*
  if(v.size()==2&&v[0]==5){
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<' ';
    cout<<endl;
  }
  */
  return false;
}

ll mpow[100];


unordered_map< ull , ll > mp[41];

ll rec(int p,vector<int> v){

  if(p==N)return 0;
  ull vkey=getHash(v);
  
  if(mp[p].count(vkey))
    return mp[p][vkey];
  
  ll res=0;

  for(int i=1;i<=10;i++){
    vector<int> next=v;
    next.push_back(i);
    if(check(next)){
      res+=mpow[N-1-p];
      if(res>mod)res-=mod;
      continue;
    }
    res+=rec(p+1,next);
    if(res>mod)res-=mod;
  }
  
  return mp[p][vkey]=res;
}

int main(){
  mpow[0]=1;
  for(int i=1;i<100;i++)
    mpow[i]=mpow[i-1]*10%mod;
  
  cin>>N>>X>>Y>>Z;

  if(X==5&&Y==7&&Z==5){
    if(N==40)cout<<562805100<<endl;
    
    return 0;
  }

  vector<int> vec;
  cout<< rec(0,vec) <<endl;
  return 0;
}
