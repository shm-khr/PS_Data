#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };



int main() {
	string n;
	cin >> n;
	int len = n.size();
	int len2 = (len - 1) / 2;
	int len3 = (len + 3) / 2;
	cout << len << ' ' << len2 << ' ' << len3 << endl;
	bool check1 = false;
	rep(i, len / 2) {
		if (n.at(i) == n.at(n.size() - 1 - i)) {
			if (i == (len / 2) - 1) {
				check1 = true;
			}
		}
		else {
			break;
		}
	}
	string n2;
	n2 = n.substr(0, len2);
	bool check2 = false;
	rep(i, len2 / 2) {
		if (n2.at(i) == n2.at(n2.size() - 1 - i)) {
			if (i == (len2 / 2) - 1) {
				check2 = true;
			}
		}
		else {
			break;
		}
	}
	
	string n3;
	n3 = n.substr(len3 - 1);
	bool check3 = false;
	rep(i, len3 / 2) {
		if (n3.at(i) == n3.at(n3.size() - 1 - i)) {
			if (i == (len3 / 2) - 1) {
				check3 = true;
			}
		}
		else {
			break;
		}
	}

	if (check1 == true && check2 == true && check3 == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}