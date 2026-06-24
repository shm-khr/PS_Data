#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define xprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(auto cnt=0ll;(cnt)<(l);++(cnt))
#define iterate(cnt,b,e) for(auto cnt=(b);(cnt)!=(e);++(cnt))
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
#define EPS 1e-12
template<typename T1, typename T2> ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }
template<typename iterator> inline size_t argmin(iterator begin, iterator end) { return distance(begin, min_element(begin, end)); }
template<typename iterator> inline size_t argmax(iterator begin, iterator end) { return distance(begin, max_element(begin, end)); }
template<typename T> T& maxset(T& to, const T& val) { return to = max(to, val); }
template<typename T> T& minset(T& to, const T& val) { return to = min(to, val); }
void bye(string s, int code = 0) { cout << s << endl; exit(0); }
mt19937_64 randdev(8901016);
inline ll rand_range(ll l, ll h) {
    return uniform_int_distribution<ll>(l, h)(randdev);
}

#ifdef __MAI
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#ifdef __VSCC
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
namespace {
#define isvisiblechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        inline MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiblechar(cc); cc = getchar_unlocked());
            for (; isvisiblechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
            return *this;
        }
        template<typename IT> void in(IT begin, IT end) {
            for (auto it = begin; it != end; ++it) *this >> *it;
        }
    };
}
MaiScanner scanner;


ll n;
int dd[55];


inline int diff(int t1, int t2) {
    return min({ abs(t2 - t1), abs(t2 - t1 - 24),abs(t2 - t1 + 24) });
}

// N<=24にバウンドされる．
void zipp() {
    map<int, int> zip;
    repeat(i, n) {
        zip[dd[i]]++;
    }

    int m = 0;
    for (auto p : zip) {
        if (p.second >= 3) // 3人が同じ時刻の差であるとき，必ず2人は同じ時差に含まれるはず，よってどの組み合わせにおいても差は必ず0
            bye("0");
        repeat(i, min(2, p.second))
            dd[m++] = p.first;
    }

    n = m;
}


void guchoku() {
    int ww[30];
    int best = 0;
    ww[0] = ww[24] = 1;
    for (int bit = 0; bit < 1 << n; ++bit) {
        int b = bit;
        fill(ww+1, ww + 24, 0);
        repeat(i, n) {
            ww[(b & 1) ? dd[i] : 24 - dd[i]] = 1;
            b >>= 1;
        }
        int nice = 25;
        int last = 0;
        iterate(i, 1, 25) {
            if (!ww[i]) continue;
            minset(nice, int(i)-last);
            last = i;
        }
        maxset(best, nice);
    }
    cout << best << endl;
}

void my_nice_solution() {
    // ochazuke
}


int main() {

    scanner >> n;
    scanner.in(dd, dd + n);

    if (n == 1) {
        cout << diff(0, dd[0]) << endl;
        return 0;
    }

    zipp();

    if (n <= 26) {
        guchoku();
    }
    else {
        abort();
        my_nice_solution();
    }


    return 0;
}