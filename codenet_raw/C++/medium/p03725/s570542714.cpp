#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define dis(a) dist[(a).x][(a).y]
using namespace std;
const int N=890;
const int DX[]={-1,0,1,0},DY[]={0,1,0,-1};
struct state
{
	int x,y;
}now,q[N],start,temp;
char c[N][N];
int h,w,k,dist[N][N],di;
void Init()
{
	string str;
	scanf("%d%d%d",&h,&w,&k);
	for(int i=1;i<=h;i++)
	{
		cin>>str;
		for(int j=1;j<=w;j++)
		{
			c[i][j]=str[j-1];
			if(c[i][j]=='S')start.x=i,start.y=j;
		}
	}
}
void bfs()
{
	int l,r;
	l=r=1;
	q[l]=start;
	dis(start)=1;
	for(;l<=r;l++)
	{
		di=dis(q[l]);
		now=q[l];
		for(int j=1;j<=k;j++)
		{
			for(int i=0;i<4;i++)
			{
				/*if(now.x+DX[i]>0&&now.x+DX[i]<=w)*/now.x+=DX[i];
				/*else continue;*//**/
				/*if(now.y+DY[i]>0&&now.y+DY[i]<=h)*/now.y+=DY[i];
				/*else continue;*/
				for(int j=1;j<=k;j++)
				{
					if(c[now.x][now.y]=='.')
					{
						if(!dis(now))
						{
							dis(now)=di+1;
							q[++r]=now;
						}
					}
				}
			}
		}
		temp=now;
		for(int i=0;i<4;i++)
		{
			for(int j=1;j<=k;j++)
			{
				now.x+=DX[i];
				now.y+=DY[i];
				if(c[now.x][now.y]=='#')
				{
					c[now.x][now.y]='.';
				}
			}
		}
		now=temp;
		dis(now)=di+1;/**/
		/*for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				printf("%d ",dist[i][j]);
			}
			puts("");
		}*/
		/*for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				printf("%c ",c[i][j]);
			}
			puts("");
		}*/
	}
}
int main()
{
	//freopen("qc.in","r",stdin);
	Init();
	bfs();
	int ans=1e9;
	for(int i=1;i<=h;i++)
	{
		if(dist[i][1])ans=min(ans,dist[i][1]);
	}
	for(int i=1;i<=w;i++)
	{
		if(dist[1][i])ans=min(ans,dist[1][i]);
	}
	for(int i=1;i<=h;i++)
	{
		if(dist[i][w])ans=min(ans,dist[i][w]);
	}
	for(int i=1;i<=w;i++)
	{
		if(dist[h][i])ans=min(ans,dist[h][i]);
	}
	printf("%d\n",ans/k);
	return 0;
}