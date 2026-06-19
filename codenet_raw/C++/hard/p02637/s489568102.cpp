#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int K;
int A[111];

bool valid() {
    int ma = *max_element(A, A+K);
    if (ma == 0) return true;
    int mi = *min_element(A, A+K);
    return mi * 2 >= ma;
}

void MAIN() {
    scanf("%d", &K);
    REP (i, K) {
	int a;
	scanf("%d", &a);
	A[i] = a;
    }

    if (!valid()) {
	puts("-1");
	return;
    }

    VI ans;
    while (1) {
	int ma = *max_element(A, A+K);
	int mii = min_element(A, A+K) - A;
	int mi = A[mii];

	// rprintf("%d", ans.begin(), ans.end());
	if (ma == 0) break;

	if (A[0] >= 2) {
	    REP (i, K) A[i]--;
	    A[0]--;
	    if (valid()) {
		REP (i, K) ans.push_back(i);
		ans.push_back(0);
		continue;
	    } else {
		REP (i, K) A[i]++;
		A[0]++;
	    }
	}

	if (ma == mi) {
	    REP (i, K) A[i]--;
	    if (valid()) {
		REP (i, K) ans.push_back(i);
		continue;
	    } else {
		REP (i, K) A[i]++;
	    }
	}
		
	int last_max = 0;
	REP (i, K) if (A[i] == ma) last_max = i;

	VI once, twice;

	REP (i, K) {
	    if (A[i] == ma) {
		twice.push_back(i);
		A[i] -= 2;
	    } else if (A[i] == mi) {
		once.push_back(i);
		A[i]--;
	    } else if (i < mii || i < last_max) {
		twice.push_back(i);
		A[i] -= 2;
	    } else {
		once.push_back(i);
		A[i]--;
	    }
	}


	//rprintf("%d.", A, A+K);
	assert(valid());
	ans.insert(ans.end(), twice.begin(), twice.end());
	ans.insert(ans.end(), once.begin(), once.end());
	ans.insert(ans.end(), twice.begin(), twice.end());
    }

    EACH (e, ans) (*e)++;
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

