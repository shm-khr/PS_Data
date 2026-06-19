#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,m,t;
  cin>>n>>m>>t;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  sort(a.rbegin(),a.rend());
  Int INF=100000000000;
  vector<Int> w(t,INF);
  w[a[0]%t]=a[0];
  for(Int i=0;i<n;i++)
    w[(a[0]-a[i])%t]=min(w[(a[0]-a[i])%t],a[0]-a[i]);

  //for(Int i=0;i<t;i++) cout<<i<<"+"<<w[i]<<endl;
  
  vector<Int> dist(t,INF),used(t,0);
  dist[0]=0;
  while(1){
    Int u=-1;
    for(Int i=0;i<t;i++){
      //cout<<i<<";"<<used[i]<<" "<<dist[i]<<endl;
      if(used[i]) continue;
      if(u<0||dist[i]<dist[u]) u=i;
    }
    //cout<<u<<"   "<<dist[u]<<endl;
    if(u<0) break;
    //cout<<u<<"   "<<dist[u]<<endl;
    used[u]=1;
    for(Int i=0;i<t;i++)
      dist[(u+i)%t]=min(dist[(u+i)%t],dist[u]+w[i]);
    //for(Int i=0;i<t;i++) cout<<(u+i)%t<<" "<<dist[(u+i)%t]<<" "<<dist[u]+w[i]<<endl;
  }
  //for(Int i=0;i<t;i++) cout<<i<<":"<<dist[i]<<endl;
  //cout<<a[0]*m<<endl;
  vector<Int> res(t,INF);
  for(Int i=0;i<t;i++)
    res[(a[0]*m+(t-i))%t]=a[0]*m-dist[i];
  //for(Int i=0;i<t;i++) cout<<i<<":"<<res[i]<<endl;
  for(int i=t-2;i>=0;i--) res[i]=max(res[i],res[i+1]);
  //for(Int i=0;i<t;i++) cout<<i<<":"<<res[i]<<endl;

  
  Int q;
  cin>>q;
  
  while(q--){
    Int A,B;
    cin>>A>>B;
    if(res[A]>=B*t) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}