
///****************************Bismillahir Rahmanir Rahim***************************///

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) a.length()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i); }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int dx4[] = {0, 0, +1, -1};
int dy4[] = {+1, -1, 0, 0};
int dx8[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy8[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline bool isIntege(double num) { return (num==(int)num); }
inline bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);}
inline double coDist(double x1,double y1,double x2,double y2) { return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))); }
inline double TriangleAreaWithSide(double a,double b,double c){double s =(a+b+c)/2; double area=sqrt(s*(s-a)*(s-b)*(s-c));return area;}
inline double area3(double x1,double y1,double x2,double y2,double x3,double y3){double A=abs((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1));A/=2.0;return A;}
inline ld degreetoradian(ld x){ld val=PI*x;val/=(180.0);return val;}
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
template<typename T> inline T gcd(T a, T b){T c;while(b){c=b;b=a%b;a = c;}return a;}
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
inline bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
inline bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
inline bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
inline bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
inline bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
inline string to_s(int t){stringstream ss;ss << t;return ss.str();}

struct edge{int p, q, w;};
bool cmp (  edge &a, edge &b ){return a.w < b.w;}

//
//debug
//#ifdef
//#else
//#define dbg(args...)
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ){return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ){os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ){os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ){os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ){os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () {cerr << endl;}
template <typename T>
void faltu( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {cerr << arg << ' '; faltu(rest...);}
/*
************************************************************************************
    transform(s.begin(),s.end(),s.begin(),::tolower);///change of uppercase to lowercase of any string
     cout << setprecision(12) << fixed; //main(_) er 1st line
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
*/
/*
bool seive[1010000];
vi prime;
void seiveGen(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
            if(!seive[i>>1]) {
                    for(int j = i * i; j < limit; j += i + i) {
                            seive[j>>1] = 1;
                    }
            }
    }
    prime.PB(2);
    for(int i = 3; i < limit; i += 2) {
            if(!seive[i>>1]) prime.PB(i);
    }
}
*/
/*
vi PrimeF;

void primeFactorize( int n ) {

    for( int i = 0; prime[i]*prime[i] <=n ; i++ ) {
        if( n % prime[i] == 0 ) {
            while( n % prime[i] == 0 ) {
                n /= prime[i];
                PrimeF.PB( prime[i] );
            }
        }
    }
    if( n > 1 ) {
        PrimeF.PB(n);
    }
}
*/
/*======================= TEMPLATE =======================*/


vl ra,ga,la;

stack<ll>p,q,r;

int main()
{
    optimize();


    int x,y,a,b,c;

    cin >> x >> y >> a >> b >> c;

    for( int i=0; i<a; i++ ){

        int o;
        cin >> o;

        ra.PB(o);
    }

    for( int i=0; i<b; i++ ){

        int o;

        cin >> o;

        ga.PB(o);
    }

    for( int i=0; i<c; i++ ){

        int o;

        cin >> o;

        la.PB(o);
    }

    sort(all(ra),greater<ll>());
    sort(all(ga),greater<ll>());
    sort(all(la),greater<ll>());

    //dbg(ra);

    ll sum=0;

    for( int i=0; i<x; i++ ){

        sum+=ra[i];
        p.push(ra[i]);
    }

    for( int i=0; i<y; i++ ){
        sum+=ga[i];
        q.push(ga[i]);
    }

    //dbg(sum);

    for( int i=0; i<c; i++ ){

        if( !p.empty() && !q.empty() && sum-p.top()+la[i]>sum-q.top()+la[i] && sum-p.top()+la[i]>sum ){

            sum=sum-p.top()+la[i];
            p.pop();
        }
        else if(!p.empty() && !q.empty() &&  sum-p.top()+la[i]<sum-q.top()+la[i] && sum-q.top()+la[i]>sum ){

            sum=sum-q.top()+la[i];
            q.pop();
        }
        else if( !p.empty() && q.empty() && sum-p.top()+la[i]>sum ){

            sum=sum-p.top()+la[i];
            p.pop();

        }
        else if( p.empty() && !q.empty() && sum-q.top()+la[i]>sum ){

            sum=sum-q.top()+la[i];
            q.pop();
        }
        else
            break;

    }

    cout<<sum<<endl;









}














