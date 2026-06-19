#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<pair<int, int> > arr;
	for (int i = 0; i < n; ++i) arr.pb(mp(v[i], i));

	sort(all(arr));

	if (2*arr[0].first < arr.back().first) {
		cout << -1;
		exit(0);
	}

	while (2*arr[0].first > arr.back().first) {
		for (int i = 0; i < n; ++i) {
			cout << i+1 << " ";
			arr[i].first--;
		}
	}

	int u = 0;
	while (true) {

		auto kek = arr;
		for (int i = 0; i < n; ++i) if (kek[i].second == u) {
			kek[i].first--;
		}

		auto minimum = *min_element(kek.begin(), kek.begin() + n); 
		auto maximum = *max_element(kek.begin(), kek.begin() + n);

		if (2*minimum.first < maximum.first) break;
		cout << u+1 << " ";
		u = (u+1)%n;

		for (int i = n-2; i > 0; i--) if (kek[i] > kek[i+1]) swap(kek[i], kek[i+1]);
		arr = kek; 

	}


	int steps = arr[0].first;
	for (int i = 0; i < steps; ++i) {

		vector<int> big, small;

		int Q = arr[0].first;

		for (int j = 0; j < n; ++j) {
			if (2*Q == arr[j].first) {
				big.push_back(arr[j].second);
				arr[j].first -= 2;
			}
			else {
				small.push_back(arr[j].second);
				arr[j].first--;
			}
		}


		for (int e = 0; e < big.size(); ++e) cout << big[e]+1 << " ";
		for (int e = 0; e < small.size(); ++e) cout << small[e]+1 << " ";
		for (int e = 0; e < big.size(); ++e) cout << big[e]+1 << " ";

	}


}
