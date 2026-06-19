////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <regex>
#include <type_traits>
#include <mutex>
#include <array>
using namespace std;

//// MACRO ////
#define countof(a) (sizeof(a)/sizeof(a[0]))

#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define RFOR(i,s,n) for (int i = (n)-1; i >= (s); i--)
#define pos(c,i) c.being() + (i)
#define allof(c) c.begin(), c.end()
#define aallof(a) a, countof(a)
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)
#define apartof(a,i,n) a + (i), a + (i) + (n)
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
#define long long long

#define EPS 1e-9
#define INF (1L << 28)
#define LINF (1LL << 60)

#define PREDICATE(t,a,exp) [&](const t & a) -> bool { return exp; }
#define COMPARISON_T(t) bool(*)(const t &, const t &)
#define COMPARISON(t,a,b,exp) [&](const t & a, const t & b) -> bool { return exp; }
#define CONVERTER(TSrc,t,TDest,exp) [&](const TSrc &t)->TDest { return exp; }

#define PRED(a,exp) [&](const auto & a) -> bool { return exp; }
#define COMP(a,b,exp) [&](const auto & a, const auto & b) -> bool { return exp; }
#define CONV2(a,b,exp) [&](const auto & a, const auto & b) -> auto { return exp; }
#define CONV3(a,b,c,exp) [&](const auto & a, const auto & b, const auto & c) -> auto { return exp; }

inline int sign_of(double x) { return abs(x) < EPS ? 0 : x > 0 ? 1 : -1; }
inline bool inRange(int val, int min, int max) { return val >= min && val < max; }
inline bool inRange(double val, double min, double max) { return val - min > -EPS && val - max < EPS; }
inline bool inRange(int x, int y, int W, int H) { return x >= 0 && x < W && y >= 0 && y < H; } // W,H含まない

template <class T> struct vevector : public vector<vector<T>> { vevector(int n = 0, int m = 0, const T &initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };
template <class T> struct vevevector : public vector<vevector<T>> { vevevector(int n = 0, int m = 0, int l = 0, const T &initial = T()) : vector<vevector<T>>(n, vevector<T>(m, l, initial)) { } };
template <class T> struct vevevevector : public vector<vevevector<T>> { vevevevector(int n = 0, int m = 0, int l = 0, int k = 0, const T &initial = T()) : vector<vevevector<T>>(n, vevevector<T>(m, l, k, initial)) { } };

//// i/o helper ////

namespace std {
	template <class T1, class T2> inline istream & operator >> (istream & in, pair<T1, T2> &p) { in >> p.first >> p.second; return in; }
	template <class T1, class T2> inline ostream & operator << (ostream &out, const pair<T1, T2> &p) { out << p.first << " " << p.second; return out; }
}
template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; v.reserve(n); REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; v.reserve(n); REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T> struct iter_pair_t { T beg, end; };
template <class T> iter_pair_t<T> iter_pair(T beg, T end) { return iter_pair_t<T>{beg, end}; }
template <class T> ostream & operator << (ostream &out, const iter_pair_t<T> &v)
{
	std::copy(v.beg, v.end, ostream_iterator<typename decltype(v.beg)::reference>(out, " "));
	return out;
}
template <class T1> ostream & operator << (ostream &out, const vector<T1> &v) { return out << iter_pair(begin(v), end(v)); }
template <class T1> ostream & operator << (ostream &out, const set<T1> &v) { return out << iter_pair(begin(v), end(v)); }
template <class T1, class T2> ostream & operator << (ostream &out, const map<T1, T2> &v) { return out << iter_pair(begin(v), end(v)); }

struct _Reader { istream &cin; template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
struct _Writer { ostream &cout; bool f{ false }; template <class T> _Writer operator ,(const T &rhs) { cout << (f ? " " : "") << rhs; f = true; return *this; } };
#define READ(t,...) t __VA_ARGS__; (_Reader{cin}), __VA_ARGS__
#define WRITE(...) (_Writer{cout}), __VA_ARGS__; cout << '\n'
#define DEBUG(...) (_Writer{cerr}), __VA_ARGS__; cerr << '\n'

void solve();
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//auto temp = ctype<char>::classic_table();
	//vector<ctype<char>::mask> bar(temp, temp + ctype<char>::table_size);
	//bar[':'] |= ctype_base::space;
	//cin.imbue(locale(cin.getloc(), new ctype<char>(bar.data())));

	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(std::numeric_limits<double>::max_digits10);
	solve();

	return 0;
}

template <class T>
struct RangeSegTrees
{

	template<class TUpdater, class TResolver, class TAccumulator>
	struct Tree
	{
		Tree(int count, TUpdater updator, TResolver resolver, TAccumulator accumulator, T initialValue)
			: size(msb(count - 1) << 1)
			, data(size * 2), lazy(size * 2)
			, updator(updator), resolver(resolver), accumulator(accumulator), initialValue(initialValue)
		{
			lazy[1] = { true, initialValue };
		}

		void update_range(int begin, int end, T value)
		{
			update_range(begin, end, 1, 0, size, value);
		}

		T query(int begin, int end)
		{
			return query(begin, end, 1, 0, size);
		}

	private:
		int size;
		vector<T> data;
		struct LAZY { bool use; T val; };
		vector<LAZY> lazy;

		TUpdater updator;
		TResolver resolver;
		TAccumulator accumulator;

		T initialValue;
		void update_lazy(LAZY &value, LAZY newValue) { if (value.use) { value.val = updator(value.val, newValue.val); } else { value = newValue; } }
		void update_value(T &v, LAZY lazy, llong n) { if (lazy.use) { v = resolver(v, lazy.val, n); } }
		T accumulate_value(T v, T v2) { return accumulator(v, v2); }
		static constexpr unsigned int msb(unsigned int v) { REP(i, 5) v |= v >> (1 << i); return (v >> 1) + 1; }

		void propergate(int i, int l, int r)
		{
			if (lazy[i].use)
			{
				update_value(data[i], lazy[i], r - l);
				if (i < size)
				{
					update_lazy(lazy[i * 2], lazy[i]);
					update_lazy(lazy[i * 2 + 1], lazy[i]);
				}
				lazy[i] = { false, initialValue };
			}
		}

		void update_range(int s, int e, int i, int l, int r, T value)
		{
			
			if (r <= s || e <= l) { propergate(i, l, r); return; }
			if (s <= l && r <= e)
			{
				update_lazy(lazy[i], { true, value });
				propergate(i, l, r);
				return;
			}

			propergate(i, l, r); 
			int m = (l + r) / 2;
			update_range(s, e, i * 2, l, m, value);
			update_range(s, e, i * 2 + 1, m, r, value);
			data[i] = accumulate_value(data[i * 2], data[i * 2 + 1]);
		}

		T query(int s, int e, int i, int l, int r)
		{
			propergate(i, l, r);

			if (r <= s || e <= l) { return initialValue; }
			if (s <= l && r <= e) { return data[i]; }

			int m = (l + r) / 2;
			if (s < m && e > m)
			{
				return accumulate_value(query(s, e, i * 2, l, m), query(s, e, i * 2 + 1, m, r));
			}
			else if (s < m)
			{
				return query(s, e, i * 2, l, m);
			}
			else
			{
				return query(s, e, i * 2 + 1, m, r);
			}
		}
	};

	template <class TUpdater, class TResolver, class TAccumulator>
	static auto RangeSegTree(int n, TUpdater upd, TResolver res, TAccumulator acm, T initial)
	{
		return Tree<TUpdater, TResolver, TAccumulator>(n, upd, res, acm, initial);
	}

	static auto RangeUpdateQuery(int n, T initial = numeric_limits<int>::max())
	{
		return RangeSegTree(n, CONV2(,b,b), CONV3(,b,,b), CONV2(,b,b), initial);
	}

	static auto RangeAddQuery(int n, T initial = 0)
	{
		return RangeSegTree(n, CONV2(a,b,a+b), CONV3(a,b,c,a+b*c), CONV2(a,b,a+b), initial);
	}

	static auto RMQnRUQ(int n, T initial = numeric_limits<int>::max())
	{
		return RangeSegTree(n, CONV2(,b,b), CONV3(,b,,b), CONV2(a, b, min(a, b)), initial);
	}

	static auto RSQnRAQ(int n, T initial = 0)
	{
		return RangeSegTree(n, CONV2(a,b,a+b), CONV3(a,b,c,a+b*c), CONV2(a,b,a+b), initial);
	}

	static auto RMQnRAQ(int n, T initial = 0)
	{
		return RangeSegTree(n, CONV2(a,b,a+b), CONV3(a,b,,a+b), CONV2(a,b,min(a,b)), initial);
	}
};


////////////////////
/// template end ///
////////////////////

void solve()
{
	READ(int, n, q);
	auto tree = RangeSegTrees<llong>::RMQnRAQ(n);
	int origin = 0;
	REP(qq, q)
	{
		READ(int, c);
		if (c == 0)
		{
			READ(int, s, t, x);
			tree.update_range(s - origin, t + 1 - origin, x);
		}
		else
		{
			READ(int, s, t);
			llong v = tree.query(s - origin, t + 1 - origin);
			WRITE(v);
		}
	}
}

