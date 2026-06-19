#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const int maxn = 100 + 5;
const int mod = 998244353; 

int k;
int a[maxn], p[1000 + 10], q[maxn];
int last[maxn];

bool check(int sz){
	int mnm = *min_element(a+1,a+k+1), mxm = *max_element(a+1,a+k+1);
	if (mxm < 2*mnm+1)
		return true;
	if (mxm > 2*mnm+1)
		return false;
	for (int i = sz; i >= sz-k+1; i--)
		last[p[i]] = i;
	int m1 = sz, m2 = sz-k+1;
	for (int i = 1; i <= k; i++){
		if (a[i] == mnm)
			m1 = min(m1, last[i]);
		if (a[i] == mxm)
			m2 = max(m2, last[i]);
	}
	return m2 < m1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> k;
	int sum = 0;
	for (int i = 1; i <= k; i++){
		cin >> a[i];
		sum += a[i];
	}
	if (*max_element(a+1,a+k+1) > 2 * (*min_element(a+1,a+k+1)))
		return cout << -1 << endl, 0;
	int sz = 0;
	for (int i = 1; i <= k; i++)
		p[++sz] = i;
	if (*max_element(a+1,a+k+1) == 2 * (*min_element(a+1,a+k+1))){
		sz = 0;
		for (int i = 1; i <= k; i++)
			if (a[i] == *max_element(a+1,a+k+1))
				p[++sz] = i;
		for (int i = 1; i <= k; i++)
			if (a[i] != *max_element(a+1,a+k+1))
				p[++sz] = i;
	}
	for (int i = 1; i <= k; i++)
		a[i] --;
	while (sz < sum){
		for (int i = sz-k+1; i <= sz; i++)
			q[i-(sz-k)] = p[i];
		vector<int> then;
		for (int i = 1; i <= k; i++){
			vector<int> A;
			for (int j = 1; j <= i; j++){
				a[q[j]] --;
				A.push_back(q[j]);
			}
			sort(A.begin(), A.end());
			int now = sz;
			int mnm = *min_element(a+1,a+k+1), mxm = *max_element(a+1,a+k+1);
			vector<int> me;
			if (2*mnm+1 == mxm){
				int idx = -1;
				for (int j = 0; j < i; j++)
					if (a[A[j]] == mxm)
						idx = j;
				for (int j = 0; j <= idx; j++){
					if (a[A[j]] == mnm)
						continue;
					p[++now] = A[j];
					me.push_back(A[j]);
				}
				for (int j = 0; j < i; j++)
					if (j > idx or a[A[j]] == mnm)
						p[++now] = A[j], me.push_back(A[j]);
			}
			else
				me = A;
			if (check(now) and (then.empty() or me < then))
				then = me;
			for (int j = 1; j <= i; j++)
				a[q[j]] ++;
		}
		for (auto it : then){
			p[++sz] = it;
			a[it] --;
		}
	}
	for (int i = 1; i <= sz; i++)
		cout << p[i] << " \n"[i == sz];
}
