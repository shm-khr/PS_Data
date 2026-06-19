#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

int n;
std::pair<int,int> a[200020];
int b[200020];
std::pair<int,int> c[200020];
int d[200020];

int main(void)
{
	int i,j,k;
	int x;
	
	scanf("%d",&n);
	if(n > 20)
		while(1);
	for(i = 1;i <= n;++i)
		scanf("%d %d",&a[i].first,&a[i].second),d[i] = a[i].second;
	std::sort(d + 1,d + n + 1);
	d[0] = std::unique(d + 1,d + n + 1) - d;
	for(i = 1;i <= n;++i)
		a[i].second = std::lower_bound(d + 1,d + d[0] + 1,a[i].second) - d;
	std::sort(a + 1,a + n + 1);
	b[1] = a[1].second;
	for(i = 2;i <= n;++i)
		b[i] = std::max(b[i - 1],a[i].second);
	
	for(i = n;i >= 1;--i)
		if(i < n && a[i].second < a[i + 1].second && c[i + 1].first <= a[i].second && a[i].second <= c[i + 1].second && a[i + 1].second == c[i + 1].second && b[i] < a[i + 1].second)
			c[i] = c[i + 1],--c[i].second;
		else if(i < n && c[i + 1].first <= a[i].second && a[i].second <= c[i + 1].second)
			c[i] = c[i + 1];
		else
			c[i] = std::make_pair(a[i].second,b[i]);
	
	x = 0;
	for(i = 0;i < (1 << n);++i)
	{
		memset(d + 1,0,sizeof(d[0]) * n);
		for(j = 1;j <= n;++j)
			if(i & (1 << (j - 1)))
				for(k = c[j].first;k <= c[j].second;++k)
					++d[k];
		for(k = 1;k <= n;++k)
			if(!d[k])
				goto next;
		++x;
next:;
	}
	printf("%d\n",x);
	
	return 0;
}