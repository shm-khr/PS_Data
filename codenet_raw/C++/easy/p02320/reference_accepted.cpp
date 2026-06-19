
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;


template<typename T, typename U>
std::enable_if_t<std::rank<T>::value == 0> fill_all(T& arr, const U& v) {
	arr = v;
}
template<typename ARR, typename U>
std::enable_if_t<std::rank<ARR>::value != 0> fill_all(ARR& arr, const U& v) {
	for (auto& i : arr) {
		fill_all(i, v);
	}
}

int32_t N;
int32_t w[3000];
int32_t v[3000];

int32_t dp[3000][10001];
int32_t func(int i, int32_t W)
{
	if (W < 0) {
		return -2000000000;
	}
	if (i == N) {
		return 0;
	}
	if (dp[i][W] != -1) {
		return dp[i][W];
	}

	return dp[i][W] = std::max(func(i + 1, W), func(i + 1, W - w[i]) + v[i]);
}


int main()
{
	fill_all(dp, -1);
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	int32_t W;
	in >> N>>W;
	int32_t w_iter = 0;
	for (int32_t i = 0; i < N; i++)
	{
		int32_t tmpw, tmpv;
		int32_t m;
		in  >> tmpv >> tmpw;
		in >> m;
		auto w_iter_old = w_iter;

		w[w_iter] = tmpw;
		v[w_iter] = tmpv;
		++w_iter;

		int32_t count = 1;
		while (m >= ((1<< (count+1)) - 1)) {
			w[w_iter] = w[w_iter - 1] * 2;
			v[w_iter] = v[w_iter - 1] * 2;
			if (w[w_iter] > W) { m = 0; count = 0; break; }
			++w_iter;
			++count;
		}
		m = m - ((1 << (count)) - 1);
		while (m > 0) {
			if (m & 1) {
				w[w_iter] = tmpw;
				v[w_iter] = tmpv;
				++w_iter;
			}
			tmpw *= 2;
			tmpv *= 2;
			if (tmpw > W) { break; }
			m /= 2;
		}

		assert(w_iter - w_iter_old <= 30);
	}
	assert(w_iter <= 3000);
	N = w_iter;

	out << func(0, W) << endl;


	return 0;
}
#endif

