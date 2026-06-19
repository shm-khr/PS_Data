#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
//[const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[] = { 0, -1, 1, -1, 1, 0, -1, 1 };
bool valid(int x, int y, int h, int w) { return (x >= 0 && y >= 0 && x < h&&y < w); }
int place(int x, int y, int w) { return w*x + y; }

vector<vector<vi>> dist;
vector<vector<vi>> todir;
vs fld;

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int h, w, n;
	string s;
	while (cin >> h >> w >> n, n)
	{
		dist.clear(), todir.clear();
		dist.resize(h, vector<vi>(w, vi(4, INF)));
		todir.resize(n + 1, vector<vi>(4, vi(4, INF)));
		fld.clear();
		fld.resize(h);
		cin >> s;
		REP(i, 4) todir[n][i][i] = n;
		for (int i = n - 1; i >= 0; i--)REP(j, 4)REP(k, 4)
		{
			if (j == k)
			{
				todir[i][j][k] = i;
				continue;
			}
			int nx;
			if (s[i] == 'L') nx = (j + 1) % 4;
			else nx = (j + 3) % 4;
			todir[i][j][k] = todir[i + 1][nx][k];
		}
		REP(i, h) cin >> fld[i];
		pii go;
		priority_queue<tuple<int, int, int, int>> que;
		REP(i, h)REP(j, w)
		{
			if (fld[i][j] == 'S')
			{
				que.emplace(0, i, j, 0);
				dist[i][j][0] = 0;
				fld[i][j] = '.';
			}
			if (fld[i][j] == 'G')
			{
				go = pii(i, j);
				fld[i][j] = '.';
			}
		}
		bool f = false;
		while (!que.empty())
		{
			int p, x, y, dir;
			tie(p, x, y, dir) = que.top();
			que.pop();
			if (pii(x, y) == go)
			{
				f = true;
				break;
			}
			int nx = x + dx[dir], ny = y + dy[dir];
			if (valid(nx, ny, h, w) && fld[nx][ny] != '#' && dist[nx][ny][dir] == INF)
			{
				dist[nx][ny][dir] = p;
				que.push(make_tuple(p, nx, ny, dir));
			}
			REP(i, 4)
			{
				int tmp = todir[p][dir][i];
				if (tmp < INF && dist[x][y][i] == INF)
				{
					dist[x][y][i] = tmp;
					que.push(make_tuple(tmp, x, y, i));
				}
			}
		}
		if (f) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}