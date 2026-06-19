#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
typedef long long LL;
const int N = 600050;
 
int head[N], to[N], nex[N], tot = 1, vis[N], ans[N], oe[N], oe2[N], n;
void addedge(int u, int v){
	tot ++; to[tot] = v, nex[tot] = head[u], head[u] = tot;
	tot ++; to[tot] = u, nex[tot] = head[v], head[v] = tot;
}
void dfs(int x){
	for(int i = head[x]; i; i = head[x] = nex[i]){
		if(vis[i] == 0){
			vis[i] = 1;
			vis[i ^ 1] = 1;
			if(to[i] == x + n)
				ans[x] = 1;
			else if(to[i] == x - n)
				ans[x - n] = -1;
			dfs(to[i]);
		}
	}
}
	
int main()
{
 
	int i, j, k, ra, rb;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++){
		scanf("%d", &j), oe[j] ^= 1;
		if(j != -1)addedge(i, j);
		else ra = i;
	}
	for(i = 1; i <= n; i ++){
		scanf("%d", &k), oe2[k] ^= 1;
		if(k != -1)addedge(i + n, k + n);
		else rb = i + n;
	}
	for(i = 1; i <= n; i ++){
		if(oe2[i] != oe[i]){
			puts("IMPOSSIBLE");
			return 0;
		}else if(oe[i] == 0)
			addedge(i, i + n); 
	}
	addedge(ra, 2 * n + 1);
	addedge(rb, 2 * n + 1);
	puts("POSSIBLE"), dfs(1);
	for(i = 1; i <= n; i ++)
		printf("%d ", ans[i]);
 
	return 0;
}