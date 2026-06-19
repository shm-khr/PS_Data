//ID:computerbox --> Hajiyev Huseyn
#include <bits/stdc++.h>
//#pragma comment(linker, "/vector:200000000")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define _CRT_SECURE_NO_WARNINGS
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;
#define FAST_READ ios_base::sync_with_stdio(0);/*cin.tie(0); cout.tie(0);*/
#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define COUT(n, a) cout<< fixed << setprecision(a) << n<<endl
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#define DTIME(ccc) __begin = clock(); ccc; cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<endl;
#define MAXN 10010

using namespace std;

#define debug(args...)(Debugger()) , args
class Debugger
{
  public:
  Debugger(const std::string& _separator=", ") :
  first(true),separator(_separator){}
  template<typename ObjectType>
  Debugger& operator,(const ObjectType& v)
  {
        if(!first)cerr<<separator;
        cerr<<v;
        first=false;
        return *this;
  }
  ~Debugger() {cerr<<endl;}
  private:
    bool first;
    string separator;
};

template <typename T1, typename T2>
inline ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
   return os<<"("<<p.first<<", "<<p.second<<")";
}
template<typename T>
inline ostream &operator<<(ostream & os,const vector<T>& v)
{
    bool first=true;
    os<<"[";
    for(unsigned ll i=0;i<v.size();i++)
    {
        if(!first)os<<", ";
        os<<v[i];
        first=false;
    }
        return os<<"]";
}
template<typename T>
inline ostream &operator<<(ostream & os,const set<T>&v)
{
    bool first=true;
    os<<"[";
    for(typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii)
    {
        if(!first)os<<", ";
        os<<*ii;
        first=false;
    }
    return os<<"]";
}
template<typename T1, typename T2>
inline ostream &operator<<(ostream & os,const map<T1, T2>&v)
{
        bool first=true;
        os<<"[";
        for(typename map<T1,T2>::const_iterator ii=v.begin(); ii!=v.end();++ii)
        {
            if(!first)os<<", ";
            os<<*ii;
            first=false;
        }
        return os<<"]";
}

ll a,b;

ll poww(ll a,ll b)
{
    ll res=1;
    for(;b;b>>=1)
    {
     if(b&1)res=(res*a);
     a=a*a;
    }
    return res;
}

ll massiv[MAXN];

ll check(ll n)
{
  ll cnt=0;
  for(ll i=1;i<=n;i++)
  {
     if(massiv[i]%2==0)cnt++;
  }
  if(cnt==0)return 0;
  else return 1;
}
ll n;

ll cmp(ll a,ll b)
{
    return a>b;
}

int main(){
FAST_READ;
cin>>n;
ll nec=0;
for(ll i=1;i<=n;i++)
{
  cin>>massiv[i];
  if(massiv[i]%2!=0)nec++;
}
sort(massiv+1,massiv+(n+1),cmp);
ll ans=0;
ll usl=12;
ll del=0;

while(nec!=n)
{
  ans++;
  del=0;
  nec=0;
  for(ll i=1;i<=n;i++)
  {
     if(massiv[i]%2==0 && del==0)
     {
       massiv[i]/=2;
       del++;
     }
     else if(massiv[i]%2!=0)massiv[i]*=3;
     else massiv[i]*=3;
     if(massiv[i]%2!=0)nec++;
  }
  //arr(massiv,n);
}
cout<<ans<<endl;



return 0;
}
