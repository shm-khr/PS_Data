#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1e9+7,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,string> P;

P S(int x,int y,int m) {
  vector<ll> a(m,0),b(m,0);
  rep(i,x) a[i%m]++;
  rep(i,y) b[i%m]++;
  ll M=0;
  rep(i,m) M=max(M,max(a[i],b[i]));
  vector<P> v;
  string s;
  rep(k,2) {
    s="";
    rep(i,m) {
      if(s.size()&&s[s.size()-1]=='A') goto next;
      rep(j,a[i]) s+='A';
      if(s.size()&&s[s.size()-1]=='B') goto next;
      rep(j,b[i]) s+='B';
    }
    v.pb(P(M,s));
  next:;
    reverse(all(a));
    s="";
    rep(i,m) {
      if(s.size()&&s[s.size()-1]=='A') goto next2;
      rep(j,a[i]) s+='A';
      if(s.size()&&s[s.size()-1]=='B') goto next2;
      rep(j,b[i]) s+='B';
    }
    v.pb(P(M,s));
  next2:;
    reverse(all(b));
  }
  rep(k,2) {
    s="";
    rep(i,m) {
      if(s.size()&&s[s.size()-1]=='B') goto next3;
      rep(j,b[i]) s+='B';
      if(s.size()&&s[s.size()-1]=='A') goto next3;
      rep(j,a[i]) s+='A';
    }
    v.pb(P(M,s));
  next3:;
    reverse(all(a));
    s="";
    rep(i,m) {
      if(s.size()&&s[s.size()-1]=='B') goto next4;
      rep(j,b[i]) s+='B';
      if(s.size()&&s[s.size()-1]=='A') goto next4;
      rep(j,a[i]) s+='A';
    }
    v.pb(P(M,s));
  next4:;
    reverse(all(b));
  }
  sort(all(v));
  if(v.size()==0) v.pb(P(MAX,""));
  return v[0];
}

void Main() {
  ll T;
  R T;
  while(T--) {
    ll x,y,x2,y2;
    cin >> x >> y >> x2 >> y2;
    if(x+y>2000) continue;
    string s="Z";
    int l=0,r=x+y;
    rep(i,50) {
      ll m1=(l*2+r)/3,m2=(l+r*2)/3;
      P p1=S(x,y,m1),p2=S(x,y,m2);
      if(p1>p2) l=m1;
      else r=m2;
    }
    P ans=P(MAX,"");
    REP(i,-2,4) {
      if(l+i>=1) ans=min(ans,S(x,y,l+i));
    }
    REP(i,x2-1,y2) cout << ans.S[i];
    ln;
  }
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
