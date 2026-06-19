#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using ll = long long;
using ull = unsigned long long;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<ll>> vvl;
typedef vector<vector<string>> vvs;
typedef vector<vector<ull>> vvul;
typedef vector<bool> vb;
const ll md = 1000000009;

ll add(ll a, ll b, ll mod = md) {
    return (a%mod + b%mod + mod)%mod;
}

ll mul(ll a, ll b, ll mod = md) {
    return (a%mod * b%mod)%mod;
}

ll fn(ll st, ll d, ll tm, ll mod = md) {
    ll res = 1, x = d%mod;
    ll ans = 0;
    while(tm) {
        if(tm&1) ans = (x*ans + res)%mod;
        res = ((res*x)%mod + res%mod)%mod;
        x = (x*x)%mod;
        tm = tm/2;
    }
    ans = (ans*st)%mod;
    return ans;
}

ll C(vl &fact, vl &invfact, ll n, ll r, ll mod = md) {
    if(r == 0) return 1;
    ll num = fact[n];
    ll den = mul(invfact[r], invfact[n-r], mod);
    return mul(num, den, mod);
}

ll mulm(ll a, ll b, ll mod = md) {
    ll r = 0;
    a %= mod;
    while (b) {
        if (b & 1) r = (r+a)%mod;
        a = (a+a)%mod;
        b = (b >> 1);
    }
    r %= mod;
    return r;
}

ll power(ll x, ll n, ll mod = md) {
	if(x == 0 && n == 0) return 1%mod;
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = (res*x)%mod;
        n = (n >> 1);
        x = (x*x)%mod;
    }
    res %= mod;
    return res;
}

ll power2(ll x, ll n) {
    ll res = 1;
    while (n) {  
        if (n & 1) res = (res*x);
        n = (n >> 1);
        x = (x*x);
    }  
    return res;
}

bool is_prime(ll x) {
    if(x == 1 || x == 0) return false;
    for(int i=2; i*i <= x; i++) {
        if(x%i == 0) return false;
    }
    return true;
}

ll Phi(ll n, vector<ll> const &primes) { 
    ll res = n; 
    for (ll i=0; primes[i]*primes[i] <= n; i++) {
        if (n % primes[i]== 0) { 
            res -= (res / primes[i]); 
            while (n%primes[i]== 0) {
               n/=primes[i]; 
            }
        } 
    } 
    if (n > 1) {
       res -= (res / n); 
    }
    return res; 
}

void sieve(vector<ll> &primes, ll lim) {
	vector<bool> prime(lim+1, true);
    for(int i = 2; i*i <= lim; i++) {
        if(prime[i]) {
            for(int j = 2; j*i <= lim; j++) {
                prime[j*i] = false;
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= lim; i+=2) {
        if(prime[i]) {
            primes.push_back(i);
        }
    }
}

void sieveGCD(ll lim, vector<ll> &tab, vector<ll> const &primes) {
    for(int  i = 1; i <= lim; i++) {
        tab[i] = i;
    }
    for(int i = 0; i<primes.size() && primes[i] <= lim; i++) {
        tab[primes[i]] = primes[i]-1;
        for(int j = 2; primes[i]*j <= lim; j++) {
            tab[primes[i]*j] = (tab[primes[i]*j]/primes[i])*(primes[i]-1);
        }
    }
}

ll LC(vl &fac, vl &ifac, ll n, ll r, ll p = md) {
	if(r > n || r < 0) {
		return 0;
	}
	if(r == 0 || r == n) {
		return 1;
	}
	if (n >= p) {
		return mul(LC(fac, ifac, n/p, r/p, p), LC(fac, ifac, n%p, r%p, p), p);
	}
	return mul(fac[n], mul(ifac[r], ifac[n-r], p), p);
}

void cachefact(vector<ll>& fac, vector<ll> &ifac, ll bound, ll mod = md) {
	fac[0] = 1;
	ifac[0] = power(1, mod-2)%mod;
	for(ll i = 1; i <= bound; i++) {
		fac[i] = (fac[i-1] % mod * i % mod)%mod;
		ifac[i] = power(fac[i], mod-2)%mod;
	}
}

void multiply(vvl &F, vvl &R, ll N) {
	vvl temp(N, vl (N, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				temp[i][j] = add(temp[i][j], mul(F[i][k], R[k][j]));
			}
		}
	}
	F = temp;
}

void mpow(vvl &F, ll N, ll n) {
	vvl R(N, vl (N, 0));
	for(int i = 0; i < N; i++) R[i][i] = 1;
	while(n) {
		if(n&1) multiply(R, F, N);
		multiply(F, F, N);
		n = (n >> 1);
	}
	F = R;
}

ll lg(ll b, ll e) {
	ll i, x = b;
	for(i = 0; ; i++, x *= b) {
		if(x > e) {
			break;
		}
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> freq(1e6+5, 0), mark(1e6+5, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}
	ll count = 0;
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		for(ll j = 2*a[i]; j <= 1e6; j += a[i]) {
			mark[j] = true;
		}
		if(!mark[a[i]] && freq[a[i]] == 1) {
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}