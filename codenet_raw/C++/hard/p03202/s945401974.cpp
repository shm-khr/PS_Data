#include <cstdio>
#include <iostream>

using namespace std;

int n;

const int maxn = 2e5 + 5;

struct node{
	int l;
	int flag;
}s[maxn];

int a[maxn] , l = 1 , r , top;

void ins(int x , int f){
	while (s[top].l > x)
		top--;
	if(s[top].l == x) s[top].flag++;
	else s[++top].l = x , s[top].flag = 1;
	if(top > 1 && s[top].flag == f)
		top-- , ins(x - 1 , f);
		
}

//bool check(int k){
//	top = 1;
//	s[1].flag = 0 , s[1].l = 0;
//	for(int i = 2; i <= n; i++)
//		if(a[i] <= a[i - 1])
//			ins(a[i] , k);
//	return s[1].flag == 0;
//}

int check(int x) {
    s[top = 1].flag = 0 , s[1].l = 0;
    for(int i = 2; i <= n; i++)
        if(a[i] <= a[i - 1]) ins(a[i], x);
    return s[1].flag == 0;
}
int main(){
	cin >> n;
//	bool flag = 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
//	for(int i = 1; i <= n; i++)
//		flag &= (a[i] > a[i - 1]);
	l = 2 , r = n;
//	if(flag){
//		cout << 1;
//		return 0;
//	}
	int ans = 1;
	while (l <= r){
		int mid = (l + r) >> 1;
//		top = 1;
		if(check(mid))
			r = mid - 1 , ans = mid;
		else
			l = mid + 1;
	}
	cout << ans;
	return 0;
}