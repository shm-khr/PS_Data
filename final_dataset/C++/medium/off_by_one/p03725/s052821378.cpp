#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 1010
#define INF 1<<30
using namespace std;
int h,w,k,x,y,x1,y1;
char A[maxn][maxn],s[maxn];
int dot[maxn][maxn],mindis;
bool v[maxn][maxn];
struct node {
	int e,f,step;
};
struct cmp {
	bool operator() (node a,node b) {
		return a.step>b.step;
	}
};
priority_queue<node,vector<node>,cmp> q;
void bfs(int a,int b,int c) {
	node a1,b1;
	a1.e=a; a1.f=b;
	a1.step=c;
	q.push(a1);
	while (!q.empty()) {
		a1=q.top();
		q.pop();
		if (a1.e<1||a1.f<1||a1.e>h||a1.f>w||a1.step>k)
			continue;
		if (A[a1.e][a1.f]=='#'||dot[a1.e][a1.f]!=-1)
			continue;
		dot[a1.e][a1.f]=a1.step;
		v[a1.e][a1.f]=1;
		b1.step=a1.step+1;
		b1.e=a1.e-1; b1.f=a1.f;
		if (!v[b1.e][b1.f])
			q.push(b1);
		b1.e=a1.e+1; b1.f=a1.f;
		if (!v[b1.e][b1.f])
			q.push(b1);
		b1.e=a1.e; b1.f=a1.f-1;
		if (!v[b1.e][b1.f])
			q.push(b1);
		b1.e=a1.e; b1.f=a1.f+1;
		if (!v[b1.e][b1.f])
			q.push(b1);
		
	}
}
int dis(int a,int b) {
	return min(a-1,min(b-1,min(h-a,w-b)));
}
int chu(int a) {
	if (a%k==0)
		return a/k;
	return a/k+1;
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d %d %d",&h,&w,&k);
	for (int i=1;i<=h;i++) {
		scanf("%s",s);
		for (int j=1;j<=w;j++) {
			A[i][j]=s[j-1];
			if (A[i][j]=='S') {
				x=i;
				y=j;
				A[i][j]='.';
			}
		}
	}
	if (dis(x,y)==0)
		printf("0\n");
	else {
		memset(dot,-1,sizeof(dot));
		bfs(x,y,1);
		mindis=INF;
		for (int i=1;i<=h;i++) {
			for (int j=1;j<=w;j++) {
				if (dot[i][j]==-1)
					continue;
				if (mindis>dis(i,j)) {
					mindis=dis(i,j);
					x1=i; y1=j;
				}
			}
		}
		printf("%d\n",1+chu(dis(x1,y1)));
	}
	return 0;
}