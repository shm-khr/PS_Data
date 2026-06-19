#include <array>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int turn[128];
	turn['L'] = -1;
	turn['R'] = 1;

	for(int h, w, n; cin >> h >> w >> n && h;) {
		string command;
		cin >> command;

		vector<int> dir(n + 1, 0);
		array<vector<int>, 4> get_d;

		for(int i = 0; i < n; ++i) {
			get_d[dir[i]].emplace_back(i);
			dir[i + 1] = (dir[i] + turn[command[i]] + 4) % 4;
		}

		get_d[dir.back()].emplace_back(n);

		vector<string> field(h);
		for(auto &e : field) cin >> e;

		typedef pair<int, int> P;
		priority_queue<P, vector<P>, greater<P>> que;
		vector<vector<int>> dist(h, vector<int>(w, n + 1));

		for(int i = 0; i < h; ++i) {
			for(int j = 0; j < w; ++j) {
				if(field[i][j] == 'S') {
					dist[i][j] = 0;
					que.push({j, i});
					goto unloop;
				}
			}
		}

	unloop:;

		while(!que.empty()) {
			const int x = que.top().first;
			const int y = que.top().second;
			que.pop();

			for(int d = 0; d < 4; ++d) {
				const int nx = x + dx[d];
				const int ny = y + dy[d];

				if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

				const auto it = lower_bound(get_d[d].begin(), get_d[d].end(), dist[y][x]);
				if(it == get_d[d].end()) continue;

				if(dist[ny][nx] > *it) {
					if(field[ny][nx] == 'G') goto ok;
					dist[ny][nx] = *it;
					que.push({nx, ny});
				}
			}	
		}

		cout << "No" << endl;
		continue;

	ok:;
		cout << "Yes" << endl;
	}

	return EXIT_SUCCESS;
}