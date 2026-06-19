#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200100;

int n, k, arr[MAXN];
int bias, ans; map<int, int> mp;

int md(int val){return (val % k + k) % k;}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for(int i = 1; i <= n; i++) arr[i] = (arr[i] - 1) % k;
	bias = ans = 0;
	for(int i = 1; i <= n; i++){
		if(arr[i] == 0) ans++;
		ans = ans + mp[md((k - arr[i]) - bias)];
		bias = md(bias + arr[i]);
		if(i >= k) mp[md(arr[i - k + 1] - bias)] = mp[md(arr[i - k + 1] - bias)] - 1;
		mp[md(arr[i] - bias)] = mp[md(arr[i] - bias)] + 1;
		// for(int i = 0; i < k; i++) printf("%d ", mp[md(i - bias)]); printf("\n");
	}
	printf("%d\n", ans);
	return 0;
}
