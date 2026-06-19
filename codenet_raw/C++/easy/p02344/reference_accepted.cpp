#include <cassert>
#include <utility>

template <class Abelian, template <class T> class Container>
class potentialized_union_find {
	class node_type;

public:
	using value_structure = Abelian;
	using value_type = typename value_structure::value_type;
	using container_type = Container<node_type>;
	using size_type = typename container_type::size_type;

protected:
	value_structure vfo;
	container_type c;

private:
	class node_type {
	public:
		typename potentialized_union_find::size_type par, siz;
		typename potentialized_union_find::value_type val;
	};
	value_type potential(size_type x) {
		value_type ret = vfo.identity();
		while (x != c[x].par) {
			c[x].val = vfo(c[x].val, c[c[x].par].val);
			ret = vfo(ret, c[x].val);
			x = c[x].par = c[c[x].par].par;
		}
		return ::std::move(ret);
	}

public:
	potentialized_union_find() : vfo(), c() {}
	explicit potentialized_union_find(
		const size_type size, const value_structure &x = value_structure())
		: vfo(x), c(size, { 0, 1, vfo.identity() }) {
		for (size_type i = 0; i < size; ++i) {
			c[i].par = i;
		}
	}

	size_type size() const { return c.size(); }
	bool empty() const { return c.empty(); }

	size_type find(size_type x) {
		assert(x < size());
		while (x != c[x].par) {
			c[x].val = vfo(c[x].val, c[c[x].par].val);
			x = c[x].par = c[c[x].par].par;
		}
		return x;
	}
	value_type diff(const size_type x, const size_type y) {
		assert(x < size());
		assert(y < size());
		assert(same(x, y));
		return vfo(potential(y), vfo.inverse(potential(x)));
	}
	bool same(const size_type x, const size_type y) {
		assert(x < size());
		assert(y < size());
		return find(x) == find(y);
	}
	size_type size(const size_type x) {
		assert(x < size());
		return c[find(x)].siz;
	}

	::std::pair<size_type, size_type> unite(size_type x, size_type y,
		value_type d) {
		assert(x < size());
		assert(y < size());
		d = vfo(vfo(d, potential(x)), vfo.inverse(potential(y)));
		x = find(x);
		y = find(y);
		if (x != y) {
			if (c[x].siz < c[y].siz) {
				::std::swap(x, y);
				d = vfo.inverse(d);
			}
			c[x].siz += c[y].siz;
			c[y].par = x;
			c[y].val = ::std::move(d);
		}
		return ::std::pair<size_type, size_type>(x, y);
	}
};

template <class T> class plus_abelian {
public:
	using value_type = T;
	value_type operator()(const value_type &x, const value_type &y) const {
		return x + y;
	}
	value_type identity() const { return value_type(0); }
	value_type inverse(const value_type &x) { return -x; }
	value_type reverse(const value_type &x) const { return x; }
};

#include<iostream>
#include<vector>
template<class T>
using vec = ::std::vector<T>;

int main() {
	int n, q;
	std::cin >> n >> q;
	potentialized_union_find<plus_abelian<int>, vec> T(n);
	while (q--) {
		int t, x, y, z;
		std::cin >> t >> x >> y;
		if (t) {
			if (T.same(x, y))
				::std::cout << T.diff(x, y) << ::std::endl;
			else
				::std::cout << "?" << ::std::endl;
		}
		else {
			::std::cin >> z;
			T.unite(x, y, z);
		}
	}
	return 0;
}

