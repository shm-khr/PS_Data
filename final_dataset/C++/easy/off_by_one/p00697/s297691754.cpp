#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

string s[9], t[3][3];
int dx[]{ -1,0,1,0 }, dy[]{ 0,1,0,-1 };
int dfs(int p) {
	int res = 0;
	rep(i, 3)rep(j, 3) {
		if (!t[i][j].empty())continue;
		rep(k, 4) {
			rep(l, 4) {
				int nx = i + dx[l], ny = j + dy[l];
				if (nx < 0 || 3 <= nx || ny < 0 || 3 <= ny || t[nx][ny].empty())continue;
				char c = t[nx][ny][(l + 2) % 4];
				if (isupper(s[p][(l + k) % 4])) {
					if (isupper(c) || toupper(c) != s[p][(l + k) % 4])goto g;
				}
				else if (islower(c) || tolower(c) != s[p][(l + k) % 4])goto g;
			}
			if (p == 8) {
				res++; goto g;
			}
			rep(l, 4)t[i][j] += s[p][(l + k) % 4]; t[i][j].clear(); g:;
		}
	}
	return res;
}
int main() {
	int n; scanf("%d", &n);
	rep(i, n) {
		rep(j, 9)cin >> s[j];
		printf("%d\n", dfs(0));
	}
}