#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	long long n;
	cin >> n;
	vector<long long> a;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		a[i] -= tmp;
	}
	long long ans = 0;
	for (long long i = 0;i < n;++i) {
		if (a[i] < 0) {
			for (long long q = 1;q >= 0;++q) {
				if (i - q >= 0) {
					if (a[i-q] > 0) {
						if (llabs(a[i]) > a[i - q]) {
							a[i] += a[i - q];
							ans += llabs(a[i - q]) * q;
							a[i - q] = 0;
						}
						else {
							a[i - q] += a[i];
							ans += llabs(a[i]) * q;
							a[i] = 0;
							goto ok;
						}
					}
				}
				if (i + q < n) {
					if (a[i + q] > 0) {
						if (llabs(a[i]) > a[i + q]) {
							a[i] += a[i + q];
							ans += llabs(a[i + q])*q;
							a[i + q] = 0;
						}
						else {
							a[i + q] += a[i];
							ans += llabs(a[i]) * q;
							a[i] = 0;
							goto ok;
						}
					}
				}
			}
		ok:;
		}
	}
	cout << ans << endl;
	return 0;
}