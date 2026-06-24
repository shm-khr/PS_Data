#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
ld eps=1e-9;

struct aa {
	int x;
	int y;
	int n;
	int w;
};
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
class Compare {
public:
	//aa?????????????????¶
	bool operator()(const aa&l, const aa&r) {
		return l.n> r.n;
	}
};

#define Seg_Max_N (1<<20) 
using Value = vector<int>;
Value dat[2 * Seg_Max_N];
struct segtree {
	int N;
	const Value ini = vector<int>(4,1e9);
	segtree() {}
	segtree(int n) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	// update k th element
	void update(int k, int place,int num) {
		k += N - 1; // leaf
		dat[k][num] = place;
		while (k > 0) {
			k = (k - 1) / 2;
			const Value al(dat[k * 2 + 1]);
			const Value ar(dat[k * 2 + 2]);
			vector<int>ndat(4);
			for (int i = 0; i < 4; ++i) {
				ndat[i] = min(al[i], ar[i]);
			}
			dat[k] = ndat;
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		const Value al(query(a, b, k * 2 + 1, l, m));
		const Value ar(query(a, b, k * 2 + 2, m, r));
		vector<int>ndat(4);
		for (int i = 0; i < 4; ++i) {
			ndat[i] = min(al[i], ar[i]);
		}
		return ndat;
	}
};

int main() {
	while (1) {
		int H, W, N; cin >> H >> W >> N;
		segtree seg(N+1);
		if (!H)break;
		string st;
		cin >> st;
		seg.update(0, 0,0);
		int way = 3;
		vector<int>ways;
		ways.push_back(way);
		for (int i = 0; i < N; ++i) {
			if (st[i] == 'L') {
				way = (way + 1) % 4;
			}
			else {
				way = (way + 3) % 4;
			}
			ways.push_back(way);
			seg.update(i + 1, i+1,way);
		}
		vector<vector<int>>next;
		for (int i = 0; i < N; ++i) {
			vector<int>v(seg.query(i + 1, N + 1));
			for (int j = 0; j < ways[i]; ++j) {
				rotate(v.begin(), v.end(),v.end());
			}
			next.push_back(v);
		}
		vector<vector<int>>field(H + 2, vector<int>(W + 2, 0));
		for (int x = 0; x <= W + 1; ++x) {
			int y = 0;
			field[y][x] = 1;
			y = H + 1;
			field[y][x] = 1;
		}
		for (int y = 0; y <= H + 1; ++y) {
			int x = 0;
			field[y][x] = 1;
			x = W + 1;
			field[y][x] = 1;
		}
		vector<vector<vector<int>>>memo(H + 2, vector<vector<int>>(W + 2,vector<int>(4,1e8)));
		int gx, gy;
		int sx, sy;
		for (int i = 0; i < H; ++i) {
			string ast; cin >> ast;
			for (int j = 0; j < W; ++j) {
				if (ast[j] == 'G') {
					gx = j + 1; gy = i + 1;
				}
				else if (ast[j] == 'S') {
					sx = j + 1; sy = i + 1;
				}
				else if (ast[j] == '#') {
					field[i + 1][j+1] = true;
				}
			}
		}
		priority_queue<aa, vector<aa>, Compare>que;
		que.push(aa{ sx,sy,0 ,3});
		memo[sy][sx][3] = 0;
		string ans = "No";
		while (!que.empty()) {
			aa atop(que.top());
			que.pop();
			const int px = atop.x;
			const int py = atop.y;
			const int pn = atop.n;
			const int pw = atop.w;
			if (px == gx&&py == gy) {
				ans = "Yes"; break;
			}
			{
				const int nx = px + dx[pw];
				const int ny = py + dy[pw];
				if (!field[ny][nx]) {
					if (memo[ny][nx][pw] > pn) {
						memo[ny][nx][pw] = pn;
						que.push(aa{ nx,ny,pn,pw });
					}
				}
			}
			
			if (pn != N) {
				for (int i = 0; i<4; ++i) {
					if (next[pn][i]<1e8) {
						if (memo[py][px][i] >next[pn][i]) {
							memo[py][px][i] = next[pn][i];
							que.push(aa{ px,py,next[pn][i],i });
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}