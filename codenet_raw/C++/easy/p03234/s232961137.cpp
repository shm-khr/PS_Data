#include <bits/stdc++.h>

#define x first
#define y second
#define y1 Y1
#define y2 Y2
#define mp make_pair
#define pb push_back
#define DEBUG(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline T read ()
{
	T sum = 0, fl = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
	return sum * fl;
}

inline void proc_status ()
{
	ifstream t ("/proc/self/status");
	cerr << string (istreambuf_iterator <char> (t), istreambuf_iterator <char> ()) << endl;
}

const int Maxn = 600 + 10;
const int Mod = 1e9 + 7;

int N, K;
int A[Maxn];
int Dp[Maxn][Maxn], g[Maxn];
int Cnt[Maxn][Maxn];

inline void Add (int &a, int b) { if ((a += b) >= Mod) a -= Mod; }

inline void Init ()
{
	g[0] = 1;
	for (int i = 2; i <= N; i += 2) g[i] = (LL) g[i - 2] * (i - 1) % Mod;

	for (int i = 1; i <= N; ++i)
		for (int j = i; j <= N; ++j)
			Cnt[i][j] = Cnt[i][j - 1] + (A[j] ? 0 : 1);
}

inline void Solve ()
{
	Init ();

	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			if ((j - i + 1) & 1) continue ;
			for (int k = i; k <= j; ++k)
				if (A[k] && (A[k] < i || A[k] > j)) goto END;

//			cout << i << ' ' << j << ' ' << Cnt[i][j] << endl;
			Dp[i][j] = g[Cnt[i][j]];
			for (int k = i; k < j; ++k)
				Add (Dp[i][j], Mod - (LL) Dp[i][k] * g[Cnt[k + 1][j]] % Mod);
			Add (ans, (LL) Dp[i][j] * g[Cnt[1][i - 1] + Cnt[j + 1][N]]);
END:;
		}
	}

	cout << ans << endl;
}

inline void Input ()
{
	N = read<int>() * 2, K = read<int>();
	for (int i = 1; i <= K; ++i)
	{
		int x = read<int>(), y = read<int>();
		A[x] = y, A[y] = x;
	}
}

int main()
{

#ifdef hk_cnyali
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif

	Input ();
	Solve ();

	return 0;
}
