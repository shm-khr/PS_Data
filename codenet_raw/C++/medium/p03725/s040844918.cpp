#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define inf 0x3f3f3f3f
#define PI acos(double(-1))
using namespace std;

typedef long long ll;
const int maxn=1000;
int minn,h,w,k,vis[maxn][maxn],lock[maxn][maxn],sx,sy;
char a[maxn][maxn];
const int m[4][2]={-1,0,1,0,0,-1,0,1};
struct node
{
    int x,y,cnt,ans;
}e;

void bfs()
{
    queue<node> q;
    e.x=sx,e.y=sy,e.cnt=0,e.ans=0;
    q.push(e);
    while(!q.empty())
    {
        e=q.front();
        q.pop();
        vis[e.x][e.y]=1;
        if(e.cnt>k||e.ans>k)
            continue;
        if(e.x==0||e.x==h-1||e.y==0||e.y==w-1)
            minn=min(e.cnt,minn);
        for(int i=0;i<4;i++)
        {
            node s;
            s.x=e.x+m[i][0];
            s.y=e.y+m[i][1];
            if(!vis[s.x][s.y]&&s.x>=0&&s.x<h&&s.y>=0&&s.y<w)
            {
                if(a[s.x][s.y]=='#')
                {
                    s.ans=e.ans+1;
                    s.cnt=e.cnt+1;
                    q.push(s);
                }
                else
                {
                    s.cnt=e.cnt+1;
                    q.push(s);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&h,&w,&k);
    for(int i=0;i<h;i++)
    {
        scanf("%s",a[i]);
        for(int j=0;j<w;j++)
        {
            if(a[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
        }
    }
    minn=k;
    bfs();
    cout << minn << endl;
    return 0;
}
