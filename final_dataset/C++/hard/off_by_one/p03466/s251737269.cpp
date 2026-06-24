#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>
#include <valarray>
#include <fstream>

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i,a,n) for(LL i = (a); i < (LL)(n); ++i)
#define REM(i,a,n) for(LL i = ((n) - 1); i >= (a); --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(0); ios::sync_with_stdio(false);}
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const string INFSTR = "\x7f";
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template<class T>
T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }
// all_of
// partial_sum, adjacent_difference

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "Union_Find.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "Flow_Solver.h"
#include "Tree.h"
#include "Suffix_Array.h"
#include "Geometry.h"
#include "Matrix.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }
ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

#if 1234567891
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

int Q;

string strA(int i) {
	string ret;
	REP(k, 0, i) ret += "A";
	return ret;
}

string strB(int i) {
	string ret;
	REP(k, 0, i) ret += "B";
	return ret;
}

string Query(int a, int b, int c, int d) {

	if (a == b) {
		string ret;
		REP(i, c, d) {
			ret += (i % 2 == 0 ? 'A' : 'B');
		}
		return ret;
	}

	int u = (a - 1) / (b + 1) + 1;
	int a_group = (a - 1) / u + 1;

	if (b < a_group) {
		// aabaabaaba
		string ret;
		REP(i, c, d) {
			ret += ((i + 1) % (u + 1) == 0 ? 'B' : 'A');
		}
		return ret;
	}

	string ret;
	do {
		ret += strA(u) + 'B';
		a -= u;
		--b;
	} while (a * u > b && a >= u);
	ret += strA(a - b / u) + strB(b - b / u * u);
	REP(z, 0, (b / u)) {
		ret += strA(1) + strB(u);
	}
	return ret.substr(c, d - c);
}

string rev(const string& str) {
	string ret;
	REM(i, 0, str.size()) {
		ret += (str[i] == 'A' ? 'B' : 'A');
	}
	return ret;
}

int main() {
	cin >> Q;
	REP(i, 0, Q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (b > 10000) {
			cout << "a" << endl;
			continue;
		}
		if (a >= b) {
			cout << Query(a, b, c - 1, d) << endl;
		} else {
			cout << rev(Query(b, a, (a + b) - d, (a + b) - (c - 1))) << endl;
		}
	}
	return 0;
}