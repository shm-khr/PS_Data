#include <bits/stdc++.h>
#define M 1000005
#define PB push_back
#define MP std::make_pair
#define FI first
#define SE second
typedef long long ll;
int nxt[M], head[M], to[M], id[M], deg[M], n, tot = 1;
bool used[M], dir[M];
int read() {
	char c = getchar(); int ans = 0; bool flag = 1;
	while (c < '0' || c > '9') flag &= (c != '-'), c = getchar();
	while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	return flag ? ans : -ans;
}
void Write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + '0');
	else Write(x / 10), putchar(x % 10 + '0');
}
void add(int u, int v) {
	nxt[++tot] = head[u], head[u] = tot, to[tot] = v;
	nxt[++tot] = head[v], head[v] = tot, to[tot] = u;
}
void DFS(int x) {
	for (int &i = head[x]; i; i = nxt[i])
		if (!used[i]) used[i] = used[i ^ 1] = dir[i] = true, DFS(to[i]);
}
int main() {
	n = read(); int root1 = 0, root2 = 0;
	for (int i = 1, fa; i <= n; i++)
		if ((fa = read()) == -1) root1 = i; else add(fa, i), ++deg[fa];
	for (int i = 1, fa; i <= n; i++)
		if ((fa = read()) == -1) root2 = i + n; else add(fa + n, i + n), ++deg[fa + n];
	add(root1, root2);
	for (int i = 1; i <= n; i++)
		if ((deg[i] &= 1) != (deg[i + n] &= 1)) return puts("IMPOSSIBLE"), 0;
		else if (deg[i] % 2 == 0) add(i, i + n), id[i] = tot;
	puts("POSSIBLE");
	for (int i = 1; i <= n * 2; i++) DFS(i);
	for (int i = 1; i <= n; i++, putchar(' '))
		if (deg[i] & 1) Write(0); else Write(dir[id[i]] ? 1 : -1);
	return 0;
}
