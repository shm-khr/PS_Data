#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
typedef long long ll;
//
int main(){
   int h,w,n;cin>>h>>w>>n;
   vector<pair<int,int>> vp,check;
   rep(i,n){
      int a,b;cin>>a>>b;
      vp.push_back(pair<int,int>(a,b));
   }
   rep(i,n){
      int x=vp[i].F,y=vp[i].S;
       rep(a,3){
            rep(b,3){
               if(x-a>0&&y-b>0&&x-a+2<=h&&y-b+2<=w){
                  check.push_back(pair<int,int>(x-a,y-b));
               }
            }
         }
      
   }
   map<pair<int,int>,int> mp;
   for(auto e:check){
      mp[e]++;
   }
   sort(all(check));
   check.erase(unique(all(check)),check.end());
   vector<ll> count;
   FOR(i,1,9){
      ll a=0;
      for(auto e:check){
         if(mp[e]==i){
            a++;
         }
      }
      count.push_back(a);
   }
   int aa=(h-2)*(w-2);
   rep(i,count.size()){
      aa-=count[i];
   }
   cout<<aa<<endl;
   for(auto e:count)cout<<e<<endl;

}
