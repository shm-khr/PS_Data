#include <bits/stdc++.h>

using namespace std;

struct Set {
	multiset<int> taken;
	multiset<int, greater<int>> available;
	
	long long leftOver = 0;
	
	void add(int a, int b);
	pair<uint64_t, uint64_t> get();
};

void Set::add(int a, int b) {
	available.insert(b);
	leftOver += a;
	
	while (available.empty() == false) {
		int b = *available.begin();
		if (leftOver >= b) {
			available.erase(available.begin());
			taken.insert(b);
			leftOver -= b;
			continue;
		}
		
		if (taken.empty() == false) {
			int B = *taken.begin();
			if (B < b) {
				taken.erase(taken.begin());
				available.insert(B);
				leftOver += B;
				continue;
			}
		}
		
		break;
	}
}

pair<uint64_t, uint64_t> Set::get() {
	if (available.empty()) return {0, 1};
	
	int b = *available.begin();
	
	uint64_t p = available.size() * 1LL * b - leftOver;
	uint64_t q = b;
	
	return {p, q};
}

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	vector<pair<int, int>> vec;
	for (int i = 0, a, b; i < n; i++) {
		ignore = scanf("%d %d", &a, &b);
		vec.emplace_back(a, b);
	}
	
	auto comp = [](const pair<int, int>& L, const pair<int, int>& R) {
		return L.first - L.second < R.first - R.second;
	};
	
	sort(vec.begin(), vec.end(), comp);
	
	Set S;
	uint64_t pAns = 0, qAns = 1;
	for (int i = 0; i < n; i++) {
		S.add(vec[i].first, vec[i].second);
		
		uint64_t p, q;
		tie(p, q) = S.get();
		q *= n;
		
		__int128_t P = p, Q = q;
		if (P * qAns > Q * pAns) {
			pAns = p;
			qAns = q;
		}
	}
	
	long long g = __gcd(pAns, qAns);
	pAns /= g;
	qAns /= g;
	
	printf("%lld %lld\n", pAns, qAns);
	
	return 0;
}
