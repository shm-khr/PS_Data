#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B, M;
	cin >> A >> B >> M;
	vector<int> a(A), b(B);
	for (int i = 0; i < A; ++i) cin >> a[i];
	for (int i = 0; i < B; ++i) cin >> b[i];
	
	int x[M], y[M], c[M];
	int max = -1, max_index = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> x[i] >> y[i] >> c[i];
		if (max < c[i])
		{
			max = c[i];
			max_index = i;
		}
	}
	
	int min_next = a[x[max_index]-1] + b[y[max_index]-1] - c[max_index];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	cout << min(a[0] + b[0], min_next) << endl;
	
	return 0;
}
