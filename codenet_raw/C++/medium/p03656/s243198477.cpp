#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
/*	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;*/

	int x;
	cin >> x;

	return x;
}

const int MaxN = 100000;
const int MaxNV = MaxN * 2 + 1;
const int MaxNE = MaxNV + MaxN;

int n;
int r1, r2;

int parity[MaxNV + 1];

struct halfEdge
{
	int v;
	bool used;
	halfEdge *next;
};
halfEdge adj_pool[MaxNE * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxNV + 1];

inline halfEdge *oppo(const halfEdge *e)
{
	return adj_pool + ((e - adj_pool) ^ 1);
}

inline void addEdge(const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->next = adj[u];
	adj[u] = adj_tail++;
}

inline void build(int &root, int d)
{
	for (int u = 1; u <= n; ++u)
	{
		int v = getint();
		if (v == -1)
			root = u + d;
		else
		{
			int p = u + d, q = v + d;
			addEdge(p, q);
			addEdge(q, p);
		}
	}
}

void dfs(const int &u, const int &fa)
{
	parity[u] = 1;
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != fa)
		{
			dfs(e->v, u);
			parity[u] ^= 1;
		}
}

int tour_n = 0;
int tour[MaxNV + 1];

void euler(const int &u)
{
	halfEdge *&e = adj[u];
	while (e)
	{
		if (e->used)
			e = e->next;
		else
		{
			e->used = oppo(e)->used = true;
			euler(e->v);
		}
	}

	tour[++tour_n] = u;
}

int lab[MaxN + 1];

int main()
{
	cin >> n;
	build(r1, 0), dfs(r1, 0);
	build(r2, n), dfs(r2, 0);

	for (int u = 1; u <= n; ++u)
		if (parity[u] != parity[u + n])
		{
			puts("IMPOSSIBLE");
			return 0;
		}

	puts("POSSIBLE");

	int sv = n * 2 + 1;
	addEdge(r1, sv), addEdge(sv, r1);
	addEdge(r2, sv), addEdge(sv, r2);
	for (int u = 1; u <= n; ++u)
		if (parity[u])
		{
			addEdge(u, u + n);
			addEdge(u + n, u);
		}

	euler(sv);

	for (int u = 1; u <= n; ++u)
		if (parity[u])
			lab[u] = -1;
	for (int i = 1; i < tour_n; ++i)
	{
		int u = tour[i];
		if (u != sv && u <= n && tour[i + 1] == u + n)
			lab[u] = 1;
	}

	for (int u = 1; u <= n; ++u)
		printf("%d ", lab[u]);
	puts("");

	return 0;
}