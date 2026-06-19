#include <bits/stdc++.h>
#define XOX
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ldb long double 
#define db double
#define int long long

#define fr first
#define se second
#define lb lower_bound 
#define ub upper_bound 
#define pb push_back
#define mpr make_pair

#define pi pair<int,int>
#define pdb pair<db,db>
#define pldb pair<ldb,ldb>

#define vi vector<int>
#define vdb vector<db>
#define vldb vector<ldb>
#define vpi vector< pi >

#define mi map<int,int>
#define mdb map<db,db>
#define mldb map<ldb,ldb>


#define forr(a,b) for (int i = (a); i < (b); ++i)
#define rrof(a,b) for (int i = (b)-1; i >= (a); --i)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int md = 1e9+7;
const int MX = 2e5+5;
const int INF = 1e18; 
const ldb PI = 4*atan((ldb)1);

int power_md(int a,int n)
{
 int res=1;
 while(n)
{
 if(n%2)
  res=(res%md*a%md)%md;
  a=(a%md*a%md)%md;
  n/=2;
}
res%=md;
return res;
}

int power(int a,int n)
{
 int res=1;
 while(n)
{
 if(n%2)
  res*=a;
  a=a*a;
  n/=2;
}
return res;
}

int abst(int a)
{
 return ((a<0)?(-1*a):(a));
}

class cmp_set{
public:
	bool operator() (int a, int b){
		return a > b;
	}
};

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

int32_t main()
{
    int n;
    cin>>n;
    int sum=0;
    int maxn=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        maxn=max(maxn,x);
        sum+=x;
    }
    int res=sum-maxn+(maxn/2);
     return 0;
}