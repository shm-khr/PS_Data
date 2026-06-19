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

int main() {
	while (1) {
		int H, W, N; cin >> H >> W >> N;
		if (!H)break;
		string st;
		for (int i = 0; i < N; ++i) {
			char c; cin >> c;
			st.push_back(c);
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
			string st; cin >> st;
			for (int j = 0; j < W; ++j) {
				if (st[j] == 'G') {
					gx = j + 1; gy = i + 1;
				}
				else if (st[j] == 'S') {
					sx = j + 1; sy = i + 1;
				}
				else if (st[j] == '#') {
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
				const int nw = st[pn] == 'L' ? (pw + 1) % 4 : (pw + 3) % 4;
				if (memo[py][px][nw] > pn+1) {
					memo[py][px][nw] = pn+1;
					que.push(aa{ px,py,pn+1,nw });
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}