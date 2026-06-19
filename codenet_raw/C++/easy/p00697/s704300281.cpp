#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

string s[9], t[3][3];
int dx[]{ -1,0,1,0 }, dy[]{ 0,1,0,-1 };
int dfs(int p) {
	if (p == 9)return 1;
	int res = 0;
	rep(i, 3)rep(j, 3) {
		if (t[i][j] != "")continue;
		rep(k, 4) {
			rotate(s[p].begin(), s[p].begin() + 1, s[p].end());
			rep(l, 4){
				int nx = i + dx[l], ny = j + dy[l];
				if (nx < 0 || 3 <= nx || ny < 0 || 3 <= ny || t[nx][ny] == "")continue;
				if (isupper(s[p][l])) {
					if (isupper(t[nx][ny][(l + 2) % 4]) || toupper(t[nx][ny][(l + 2) % 4]) != s[p][l])goto g;
				}
				if (islower(s[p][l])) {
					if (islower(t[nx][ny][(l + 2) % 4]) || tolower(t[nx][ny][(l + 2) % 4]) != s[p][l])goto g;
				}
			}
			t[i][j] = s[p]; res += dfs(p + 1); g:;
		}
		t[i][j] = "";
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