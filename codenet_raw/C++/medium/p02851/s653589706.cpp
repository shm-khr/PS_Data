#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=2e5;
long long n,k,a[maxn],ans;
long long num[maxn],sum[maxn];
multiset<long long> p;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		num[i]=(sum[i]-i+k)%k;
	}
	p.insert(0);
	for(int i=1;i<=n;i++)
	{
		if(i>=k)
			p.erase(p.find(num[i-k]));
		ans+=p.count(num[i]);
		p.insert(num[i]);
	}
	printf("%lld",ans);
	return 0;
}