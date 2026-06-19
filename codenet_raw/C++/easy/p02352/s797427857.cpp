#define NDEBUG
#include <cassert>
#include <utility>
#include <vector>

template <typename ValueMonoid, typename OperatorMonoid, class Modify>
class LazySegmentTree {
public:
	using value_type = ValueMonoid;
	using reference = value_type &;
	using const_reference = const value_type &;
	using operator_type = OperatorMonoid;

private:
	using container_type = std::vector<std::pair<value_type, operator_type>>;

public:
	using size_type = typename container_type::size_type;

private:
	const Modify m;
	const size_type size_, height, capacity;
	container_type tree;
	static size_type getheight(const size_type &size) noexcept {
		size_type ret = 0;
		while (static_cast<size_type>(1) << ret < size)
			++ret;
		return ret;
	}
	value_type reflect(const size_type &index) {
		return m(tree[index].first, tree[index].second);
	}
	void recalc(const size_type &index) {
		tree[index].first = reflect(index << 1) + reflect(index << 1 | 1);
	}
	void assign(const size_type &index, const operator_type &data) {
		tree[index].second = tree[index].second + data;
	}
	void push(const size_type &index) {
		assign(index << 1, tree[index].second);
		assign(index << 1 | 1, tree[index].second);
		tree[index].second = operator_type();
	}
	void propagate(const size_type &index) {
		for (size_type i = height; i; --i)
			push(index >> i);
	}
	void thrust(const size_type &index) {
		tree[index].first = reflect(index);
		push(index);
	}
	void evaluate(const size_type &index) {
		for (size_type i = height; i; --i)
			thrust(index >> i);
	}
	void build(size_type index) {
		while (index >>= 1)
			recalc(index);
	}

public:
	explicit LazySegmentTree(const size_type &size, const Modify &m = Modify())
		: m(m), size_(size), height(getheight(size_)),
		capacity(static_cast<size_type>(1) << height), tree(capacity << 1) {}
	void update(size_type begin, size_type end, const operator_type &data) {
		assert(begin <= end);
		assert(begin <= size());
		assert(end <= size());
		begin += capacity;
		end += capacity;
		propagate(begin);
		propagate(end - 1);
		for (size_type left = begin, right = end; left < right;
			left >>= 1, right >>= 1) {
			if (left & 1)
				assign(left++, data);
			if (right & 1)
				assign(right - 1, data);
		}
		build(begin);
		build(end - 1);
	}
	void update(size_type index,
		const std::function<value_type(const_reference)> &f) {
		assert(index < size());
		index += capacity;
		propagate(index);
		tree[index].first = f(reflect(index));
		tree[index].second = operator_type();
		build(index);
	}
	void update(const size_type index, const_reference data) {
		assert(index < size());
		update(index, [&data](const_reference d) { return data; });
	}
	value_type range(size_type begin, size_type end) {
		assert(begin <= end);
		assert(begin <= size());
		assert(end <= size());
		begin += capacity;
		end += capacity;
		evaluate(begin);
		evaluate(end - 1);
		value_type retL, retR;
		for (; begin < end; begin >>= 1, end >>= 1) {
			if (begin & 1)
				retL = retL + reflect(begin++);
			if (end & 1)
				retR = reflect(end - 1) + retR;
		}
		return retL + retR;
	}
	size_type search(const std::function<bool(const_reference)> &b) {
		if (b(value_type()))
			return 0;
		if (!b(reflect(1)))
			return size() + 1;
		value_type acc;
		size_type i = 1;
		while (i < capacity) {
			thrust(i);
			if (!b(acc + reflect(i <<= 1)))
				acc = acc + reflect(i++);
		}
		return i - capacity + 1;
	}
	const_reference operator[](const size_type &index) {
		assert(index < size());
		index += capacity;
		evaluate(index);
		tree[index].first = reflect(index);
		tree[index].second = operator_type();
		return tree[index].first;
	}
	size_type size() const noexcept { return size_; }
	bool empty() const noexcept { return !size_; }
};

template <typename V, typename O, class F>
auto make_Lazy(const typename LazySegmentTree<V, O, F>::size_type &size,
	const F &f) {
	return LazySegmentTree<V, O, F>(size, f);
}

template <typename T> struct Add {
	using value_type = T;
	T a;
	explicit Add(const T &x = T(0)) : a(x) {}
	Add operator+(const Add &o) const { return Add(a + o.a); }
};

#include <algorithm>
#include <limits>
template <typename T> struct Mini {
	using value_type = T;
	T a;
	explicit Mini(const T &x = std::numeric_limits<T>::max()) : a(x) {}
	Mini operator+(const Mini &o) const { return Mini(std::min(a, o.a)); }
};
#include<iostream>
int main() {
	using M = Mini<int>;
	using A = Add<int>;
	int n, q;
	std::cin >> n >> q;
	auto T = make_Lazy<M,A>(n, [](const M &x, const A &y) {return M(x.a + y.a);});
	for (int i = 0;i < T.size();++i)
		T.update(i, M(0));
	while (q--) {
		int c, s, t, x;
		std::cin >> c >> s >> t;
		if (c) {
			std::cout << T.range(s, t + 1).a << std::endl;
		}
		else {
			std::cin >> x;
			T.update(s, t + 1, A(x));
		}
	}
	return 0;
}
