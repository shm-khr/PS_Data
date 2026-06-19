

import java.awt.Point;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.Serializable;
import java.util.AbstractCollection;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Locale;
import java.util.NoSuchElementException;
import java.util.function.UnaryOperator;

public class Main {

	public static void main(String[] args) {
		new Main();
	}

	public Main() {
		FastIO io = new FastIO();
		/*
		 * author: 31536000
		 * AGC035 B問題
		 * 考察メモ
		 * 1. 辺の個数が偶数でないといけない(出次数=辺の個数なので)
		 * 2. この時構成可能では？
		 * この時に必ず構成可能であると信じてみよう
		 * すると、なんか簡単な規則があるはず
		 * まず、グラフの中で葉になっている部分は必ず出次数=0にする
		 * そうすると、次の葉に関しても決め打っていけるのでサイクル以外全部消える
		 * サイクルは適当に一つを決め打つと解けるので解けます
		 */
		int N =io.nextInt(), M = io.nextInt();
		ArrayList<ArrayList<Integer>> graph = new ArrayList<>(N);
		for (int i = 0;i < N;++ i) graph.add(new ArrayList<>());
		int[] edge = new int[N];
		Arrays.fill(edge, 0);
		for (int i = 0;i < M;++ i) {
			int A = io.nextInt() - 1, B = io.nextInt() - 1;
			graph.get(A).add(B);
			graph.get(B).add(A);
			++ edge[A];
			++ edge[B];
		}
		boolean[] in = new boolean[N];
		Arrays.fill(in, false);

		BreadthFirstSearch<Integer> bfs = new BreadthFirstSearch<>();
		for (int i = 0;i < N;++ i) if (edge[i] == 1) bfs.push(i); // 最初の葉

		StringBuilder sb = new StringBuilder();
		for (int n = 0;n < N;++ n) {
			for (int i : bfs) {
				for (int j : graph.get(i)) {
					if (edge[j] != 0) {
						if (in[i]) {
							sb.append(String.format("%d %d\n", i + 1, j + 1));
							in[i] = !in[i];
						} else {
							sb.append(String.format("%d %d\n", j + 1, i + 1));
							in[j] = !in[j];
						}
						if (-- edge[j] == 1) bfs.push(j); // 次の葉
						-- edge[i];
					}
				}
			}
			bfs.push(n);
		}


		if (M % 2 != 0) io.print(-1);
		else io.print(sb);

		io.flush();
	}
	/**
	 * 端がもう片側の端と繋がり、循環する固定長配列を提供します。
	 * @author 31536000
	 *
	 * @param <T> 配列の型
	 */
	public class CircularArray<T> extends AbstractCollection<T> implements Serializable{

		private static final long serialVersionUID = 4505120414119274426L;
		final Object[] array;
		int first = 0;
		public CircularArray(int size) {
			array = new Object[size];
		}

		public CircularArray(T[] array) {
			this.array = array;
		}

		private int getIndex(int index) {
			index -= first;
			if (index >= array.length) index %= array.length;
			else if (index < 0) index = array.length + index % array.length;
			return index;
		}

		public void setFront(T value) {
			array[first] = value;
		}

		public void set(int index, T value) {
			array[getIndex(index)] = value;
		}

		public void setBack(T value) {
			array[first == 0 ? array.length - 1 : first - 1] = value;
		}

		public T get(int index) {
			@SuppressWarnings("unchecked")
			T ret = (T)array[getIndex(index)];
			return ret;
		}

		public T front() {
			@SuppressWarnings("unchecked")
			T ret = (T)array[first];
			return ret;
		}

		public T back() {
			@SuppressWarnings("unchecked")
			T ret = (T)(first == 0 ? array[array.length - 1] : array[first - 1]);
			return ret;
		}

		public void rotate(int rotate) {
			first = getIndex(rotate);
		}

		public void rotateNext() {
			if (++first >= array.length) first = 0;
		}

		public void rotatePrevious() {
			if (--first < 0) first = array.length - 1;
		}

		private class Iter implements Iterator<T> {
			private int index;
			private int count;
			Iter() {
				index = first;
				count = 0;
			}
			@Override
			public boolean hasNext() {
				return count < array.length;
			}

			@Override
			public T next() {
				@SuppressWarnings("unchecked")
				T ret = (T)array[index];
				if (++index >= array.length) index = 0;
				++ count;
				return ret;
			}
		}

		@Override
		public Iterator<T> iterator() {
			return new Iter();
		}

		@Override
		public int size() {
			return array.length;
		}
	}

	/**
	 * 幅優先探索を自動的に行うライブラリです。
	 * @author 31536000
	 *
	 * @param <T> 幅優先探索の対象となる型
	 */
	public class BreadthFirstSearch<T> implements Iterable<T>, Iterator<T>{
		CircularArray<Deque<T>> queue;
		HashSet<T> hash;
		int size;

		/**
		 * キューを1個用いるBFSを用意します。
		 */
		public BreadthFirstSearch() {
			this(1);
		}

		/**
		 * キューをn個用いるBFSを用意します。
		 * @param n 使うキューの数
		 */
		public BreadthFirstSearch(int n) {
			queue = new CircularArray<Deque<T>>(n);
			for (int i = 0;i < n;++ i) queue.set(i, new ArrayDeque<T>());
			hash = new HashSet<T>();
			size = 0;
		}

		/**
		 * キューを1個用いて、最初に調べる場所がtのBFSを作成します。
		 * @param t 最初に調べる値
		 */
		public BreadthFirstSearch(T t) {
			this(1, t);
		}

		/**
		 * キューをn個用いて、最初に調べる場所がtのBFSを作成します。
		 * @param n 使うキューの数
		 * @param t 最初に調べる値
		 */
		public BreadthFirstSearch(int n, T t) {
			this(n);
			push(t);
		}

		/**
		 * 第n番目のキューに新しくtを調べる対象に追加します。
		 * @param n 使うキューの場所(0はstackとして処理される)
		 * @param t 調べる値
		 * @return 既にtを調べたことがあるならfalse、まだ調べてないならtrue
		 */
		public boolean push(int n, T t) {
			if (n < 0 || n > queue.size()) throw new IndexOutOfBoundsException();
			if (n == 0) { // stackとして使う
				Deque<T> que = queue.front();
				if (!hash.add(t)) return false;
				que.addFirst(t);
			} else { // queueとして使う
				Deque<T> que = queue.get(n - 1);
				if (!hash.add(t)) return false;
				que.addLast(t);
			}
			++ size;
			return true;
		}

		/**
		 * 1番目のキューに新しくtを調べる対象に追加します。
		 * @param t 調べる値
		 * @return 既にtを調べたことがあるならfalse、まだ調べてないならtrue
		 */
		public boolean push(T t) {
			if (!hash.add(t)) return false;
			queue.front().addLast(t);
			++ size;
			return true;
		}

		/**
		 * 既にその要素を調べているか返します。
		 * @param t 調べる値
		 * @return 既に調べていたらtrue
		 */
		public boolean contains(T t) {
			return hash.contains(t);
		}

		/**
		 * BFSを初期化します。
		 */
		public void clear() {
			for (Deque<T> i : queue) i.clear();
			hash.clear();
			size = 0;
		}

		@Override
		public Iterator<T> iterator() {
			return this;
		}

		@Override
		public boolean hasNext() {
			return size > 0;
		}

		@Override
		public T next() {
			if (size <= 0) throw new NoSuchElementException();
			while (queue.front().isEmpty()) queue.rotateNext();
			-- size;
			return queue.front().pollFirst();
		}
	}

	public class FastIO {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int read = 0;
		private int length = 0;
		public final PrintWriter out = new PrintWriter(System.out, false);
		public final PrintWriter err = new PrintWriter(System.err, false);

		private boolean hasNextByte() {
			if (read < length) return true;
			read = 0;
			try {
				length = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			return length > 0;
		}

		private int readByte() {
			return hasNextByte() ? buffer[read++] : -1;
		}

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private boolean isNumber(int c) {
			return '0' <= c && c <= '9';
		}

		public boolean hasNext() {
			while (hasNextByte() && !isPrintableChar(buffer[read])) read++;
			return hasNextByte();
		}

		public char nextChar() {
			if (!hasNextByte())  throw new NoSuchElementException();
			return (char)readByte();
		}

		public char[][] nextChar(int height) {
			char[][] ret = new char[height][];
			for (int i = 0;i < ret.length;++ i) ret[i] = next().toCharArray();
			return ret;
		}

		public String next() {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b;
			while (isPrintableChar(b = readByte())) sb.appendCodePoint(b);
			return sb.toString();
		}

		public long nextLong() {
			if (!hasNext()) throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (!isNumber(b)) throw new NumberFormatException();
			while (true) {
				if (isNumber(b)) {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) return minus ? -n : n;
				else throw new NumberFormatException();
				b = readByte();
			}
		}

		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
			return (int) nl;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextInt(int width) {
			int[] ret = new int[width];
			for (int i = 0;i < width;++ i) ret[i] = nextInt();
			return ret;
		}

		public long[] nextLong(int width) {
			long[] ret = new long[width];
			for (int i = 0;i < width;++ i) ret[i] = nextLong();
			return ret;
		}

		public int[][] nextInt(int width, int height) {
			int[][] ret = new int[height][width];
			for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[i][j] = nextInt();
			return ret;
		}

		public long[][] nextLong(int width, int height) {
			long[][] ret = new long[height][width];
			for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[j][i] = nextLong();
			return ret;
		}

		public boolean[] nextBoolean(char T) {
			char[] s = next().toCharArray();
			boolean[] ret = new boolean[s.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = s[i] == T;
			return ret;
		}

		public boolean[][] nextBoolean(char T, int height) {
			boolean[][] ret = new boolean[height][];
			for (int i = 0;i < ret.length;++ i) {
				char[] s = next().toCharArray();
				ret[i] = new boolean[s.length];
				for (int j = 0;j < ret[i].length;++ j) ret[i][j] = s[j] == T;
			}
			return ret;
		}

		public Point nextPoint() {
			return new Point(nextInt(), nextInt());
		}

		public Point[] nextPoint(int width) {
			Point[] ret = new Point[width];
			for (int i = 0;i < width;++ i) ret[i] = nextPoint();
			return ret;
		}

		@Override
		protected void finalize() throws Throwable {
			try {
				super.finalize();
			} finally {
				in.close();
				out.close();
				err.close();
			}
		}

		public void print(boolean b) {
			out.print(b);
		}

		public void print(char c) {
			out.print(c);
		}

		public void print(char[] s) {
			out.print(s);
		}

		public void print(double d) {
			out.print(d);
		}

		public void print(double d, int length) {
			if (d < 0) {
				out.print('-');
				d = -d;
			}
			d += Math.pow(10, -length) / 2;
			out.print((long)d);
			out.print('.');
			d -= (long)d;
			for (int i = 0;i < length;++ i) {
				d *= 10;
				out.print((int)d);
				d -= (int)d;
			}
		}

		public void print(float f) {
			out.print(f);
		}

		public void print(int i) {
			out.print(i);
		}

		public void print(long l) {
			out.print(l);
		}

		public void print(Object obj) {
			out.print(obj);
		}

		public void print(String s) {
			out.print(s);
		}

		public void print(Object[] obj, String perse) {
			print(obj[0]);
			for (int i = 1;i < obj.length;++ i) {
				print(perse);
				print(obj[i]);
			}
		}

		public void print(Object[][] obj, String perse1, String perse2) {
			print(obj[0], perse1);
			for (int i = 1;i < obj.length;++ i) {
				print(perse2);
				print(obj[i], perse1);
			}
		}

		public void printf(String format, Object... args) {
			out.printf(format, args);
		}

		public void printf(Locale l, String format, Object... args) {
			out.printf(l, format, args);
		}

		public void println() {
			out.println();
		}

		public void println(boolean b) {
			out.println(b);
		}

		public void println(char c) {
			out.println(c);
		}

		public void println(char[] s) {
			out.println(s);
		}

		public void println(double d) {
			out.println(d);
		}

		public void println(double d, int length) {
			print(d, length);
			println();
		}

		public void println(float f) {
			out.println(f);
		}

		public void println(int i) {
			out.println(i);
		}

		public void println(long l) {
			out.println(l);
		}

		public void println(Object obj) {
			out.println(obj);
		}

		public void println(String s) {
			out.println(s);
		}

		public void println(Object[] obj, String perse) {
			print(obj, perse);
			println();
		}

		public void println(Object[][] obj, String perse1, String perse2) {
			print(obj, perse1, perse2);
			println();
		}

		public void flush() {
			out.flush();
			err.flush();
		}
	}

	public enum BoundType {
		CLOSED, OPEN;
	}

	public static class Range<C> implements Serializable{

		private static final long serialVersionUID = -4702828934863023392L;
		protected C lower;
		protected C upper;
		protected BoundType lowerType;
		protected BoundType upperType;
		private Comparator<? super C> comparator;

		protected Range(C lower, BoundType lowerType, C upper, BoundType upperType) {
			this(lower, lowerType, upper, upperType, null);
		}

		protected Range(C lower, BoundType lowerType, C upper, BoundType upperType, Comparator<? super C> comparator) {
			this.lower = lower;
			this.upper = upper;
			this.lowerType = lowerType;
			this.upperType = upperType;
			this.comparator = comparator;
		}

		public static <C extends Comparable<? super C>> Range<C> range(C lower, BoundType lowerType, C upper, BoundType upperType) {
			if (lower != null && upper != null) {
				int comp = lower.compareTo(upper);
				if (comp > 0) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED);
				else if (comp == 0 && (lowerType == BoundType.OPEN || upperType == BoundType.OPEN))return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED);
			}
			return new Range<C>(lower, lowerType, upper, upperType);
		}

		public static <C> Range<C> range(C lower, BoundType lowerType, C upper, BoundType upperType, Comparator<? super C> comparator) {
			if (lower != null && upper != null) {
				int comp = comparator.compare(lower, upper);
				if (comp > 0) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, comparator);
				else if (comp == 0 && (lowerType == BoundType.OPEN || upperType == BoundType.OPEN)) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, comparator);
			}
			return new Range<C>(lower, lowerType, upper, upperType, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> all() {
			return range(null, BoundType.OPEN, null, BoundType.OPEN);
		}

		public static <C> Range<C> all(Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, null, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> atMost(C upper) {
			return range(null, BoundType.OPEN, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> atMost(C upper, Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, upper, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> lessThan(C upper) {
			return range(null, BoundType.OPEN, upper, BoundType.OPEN);
		}

		public static <C> Range<C> lessThan(C upper, Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, upper, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> downTo(C upper, BoundType boundType) {
			return range(null, BoundType.OPEN, upper, boundType);
		}

		public static <C> Range<C> downTo(C upper, BoundType boundType, Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, upper, boundType, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> atLeast(C lower) {
			return range(lower, BoundType.CLOSED, null, BoundType.OPEN);
		}

		public static <C> Range<C> atLeast(C lower, Comparator<? super C> comparator) {
			return range(lower, BoundType.CLOSED, null, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> greaterThan(C lower) {
			return range(lower, BoundType.OPEN, null, BoundType.OPEN);
		}

		public static <C> Range<C> greaterThan(C lower, Comparator<? super C> comparator) {
			return range(lower, BoundType.OPEN, null, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> upTo(C lower, BoundType boundType) {
			return range(lower, boundType, null, BoundType.OPEN);
		}

		public static <C> Range<C> upTo(C lower, BoundType boundType, Comparator<? super C> comparator) {
			return range(lower, boundType, null, BoundType.OPEN, comparator  );
		}

		public static <C extends Comparable<? super C>> Range<C> open(C lower, C upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN);
		}

		public static <C> Range<C> open(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> openClosed(C lower, C upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> openClosed(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> closedOpen(C lower, C upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN);
		}

		public static <C> Range<C> closedOpen(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> closed(C lower, C upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> closed(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> singleton(C value) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED);
		}

		public static <C> Range<C> singleton(C value, Comparator<? super C> comparator) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> empty() {
			return range(null, BoundType.CLOSED, null, BoundType.CLOSED);
		}

		public static <C> Range<C> empty(Comparator<? super C> comparator) {
			return range(null, BoundType.CLOSED, null, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> encloseAll(Iterable<C> values) {
			C lower = values.iterator().next();
			C upper = lower;
			for (C i : values) {
				if (lower.compareTo(i) > 0) lower = i;
				if (upper.compareTo(i) < 0) upper = i;
			}
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> encloseAll(Iterable<C> values, Comparator<? super C> comparator) {
			C lower = values.iterator().next();
			C upper = lower;
			for (C i : values) {
				if (comparator.compare(lower, i) > 0) lower = i;
				if (comparator.compare(upper, i) < 0) upper = i;
			}
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, comparator);
		}

		protected int compareLower(C value) {
			return compareLower(value, BoundType.CLOSED);
		}

		protected int compareLower(C value, BoundType boundType) {
			return compareLower(lower, lowerType, value, boundType);
		}

		protected int compareLower(C lower, BoundType lowerType, C value) {
			return compareLower(lower, lowerType, value, BoundType.CLOSED);
		}

		protected int compareLower(C lower, BoundType lowerType, C value, BoundType boundType) {
			if (lower == null) return value == null ? 0 : -1;
			else if (value == null) return 1;
			int compare;
			if (comparator == null) {
				@SuppressWarnings("unchecked")
				Comparable<C> comp = (Comparable<C>)lower;
				compare = comp.compareTo(value);
			} else compare = comparator.compare(lower, value);
			if (compare == 0) {
				if (lowerType == BoundType.CLOSED) -- compare;
				if (boundType == BoundType.CLOSED) ++ compare;
			}
			return compare;
		}

		protected int compareUpper(C value) {
			return compareUpper(value, BoundType.CLOSED);
		}

		protected int compareUpper(C value, BoundType boundType) {
			return compareUpper(upper, upperType, value, boundType);
		}

		protected int compareUpper(C upper, BoundType upperType, C value) {
			return compareUpper(upper, upperType, value, BoundType.CLOSED);
		}

		protected int compareUpper(C upper, BoundType upperType, C value, BoundType boundType) {
			if (upper == null) return value == null ? 0 : 1;
			if (value == null) return -1;
			int compare;
			if (comparator == null) {
				@SuppressWarnings("unchecked")
				Comparable<C> comp = (Comparable<C>)upper;
				compare = comp.compareTo(value);
			} else compare = comparator.compare(upper, value);
			if (compare == 0) {
				if (upperType == BoundType.CLOSED) ++ compare;
				if (boundType == BoundType.CLOSED) -- compare;
			}
			return compare;
		}

		public boolean hasLowerBound() {
			return lower != null;
		}

		public C lowerEndpoint() {
			if (hasLowerBound()) return lower;
			throw new IllegalStateException();
		}

		public BoundType lowerBoundType() {
			if (hasLowerBound()) return lowerType;
			throw new IllegalStateException();
		}

		public boolean hasUpperBound() {
			return upper != null;
		}

		public C upperEndpoint() {
			if (hasUpperBound()) return upper;
			throw new IllegalStateException();
		}

		public BoundType upperBoundType() {
			if (hasUpperBound()) return upperType;
			throw new IllegalStateException();
		}

		/**
		 * この区間が空集合か判定します。
		 * @return 空集合ならばtrue
		 */
		public boolean isEmpty() {
			return lower == null && upper == null && lowerType == BoundType.CLOSED;
		}

		/**
		 * 与えられた引数が区間の左側に位置するか判定します。<br>
		 * 接する場合は区間の左側ではないと判定します。
		 * @param value 調べる引数
		 * @return 区間の左側に位置するならtrue
		 */
		public boolean isLess(C value) {
			return isLess(value, BoundType.CLOSED);
		}

		protected boolean isLess(C value, BoundType boundType) {
			return compareLower(value, boundType) > 0;
		}

		/**
		 * 与えられた引数が区間の右側に位置するか判定します。<br>
		 * 接する場合は区間の右側ではないと判定します。
		 * @param value 調べる引数
		 * @return 区間の右側に位置するならtrue
		 */
		public boolean isGreater(C value) {
			return isGreater(value, BoundType.CLOSED);
		}

		private boolean isGreater(C value, BoundType boundType) {
			return compareUpper(value, boundType) < 0;
		}

		/**
		 * 与えられた引数が区間内に位置するか判定します。<br>
		 * 接する場合も区間内に位置すると判定します。
		 * @param value 調べる引数
		 * @return 区間内に位置するならtrue
		 */
		public boolean contains(C value) {
			return !isLess(value) && !isGreater(value) && !isEmpty();
		}

		/**
		 * 与えられた引数すべてが区間内に位置するか判定します。<br>
		 * 接する場合も区間内に位置すると判定します。
		 * @param value 調べる要素
		 * @return 全ての要素が区間内に位置するならtrue
		 */
		public boolean containsAll(Iterable<? extends C> values) {
			for (C i : values) if (!contains(i)) return false;
			return true;
		}

		/**
		 * 与えられた区間がこの区間に内包されるか判定します。<br>
		 *
		 * @param other
		 * @return 与えられた区間がこの区間に内包されるならtrue
		 */
		public boolean encloses(Range<C> other) {
			return !isLess(other.lower, other.lowerType) && !isGreater(other.upper, other.upperType);
		}

		/**
		 * 与えられた区間がこの区間と公差するか判定します。<br>
		 * 接する場合は公差するものとします。
		 * @param value 調べる引数
		 * @return 区間が交差するならtrue
		 */
		public boolean isConnected(Range<C> other) {
			if (this.isEmpty() || other.isEmpty()) return false;
			C lower, upper;
			BoundType lowerType, upperType;
			if (isLess(other.lower, other.lowerType)) {
				lower = other.lower;
				lowerType = other.lowerType;
			} else {
				lower = this.lower;
				lowerType = this.lowerType;
			}
			if (isGreater(other.upper, other.upperType)) {
				upper = other.upper;
				upperType = other.upperType;
			} else {
				upper = this.upper;
				upperType = this.upperType;
			}
			if (lower == null || upper == null) return true;
			int comp = compareLower(lower, lowerType, upper, upperType);
			return comp <= 0;
		}
		/**
		 * この区間との積集合を返します。
		 * @param connectedRange 積集合を求める区間
		 * @return 積集合
		 */
		public Range<C> intersection(Range<C> connectedRange) {
			if (this.isEmpty() || connectedRange.isEmpty()) {
				if (comparator == null) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED);
				return empty(comparator);
			}
			C lower, upper;
			BoundType lowerType, upperType;
			if (isLess(connectedRange.lower, connectedRange.lowerType)) {
				lower = connectedRange.lower;
				lowerType = connectedRange.lowerType;
			} else {
				lower = this.lower;
				lowerType = this.lowerType;
			}
			if (isGreater(connectedRange.upper, connectedRange.upperType)) {
				upper = connectedRange.upper;
				upperType = connectedRange.upperType;
			} else {
				upper = this.upper;
				upperType = this.upperType;
			}
			if (comparator == null) {
				return new Range<C>(lower, lowerType, upper, upperType);
			}
			return range(lower, lowerType, upper, upperType, comparator);
		}

		/**
		 * この区間との和集合を返します。
		 * @param other 和集合を求める区間
		 * @return 和集合
		 */
		public Range<C> span(Range<C> other) {
			if (other.isEmpty()) return new Range<C>(lower, lowerType, upper, upperType);
			C lower, upper;
			BoundType lowerType, upperType;
			if (isLess(other.lower, other.lowerType)) {
				lower = this.lower;
				lowerType = this.lowerType;
			} else {
				lower = other.lower;
				lowerType = other.lowerType;
			}
			if (isGreater(other.upper, other.upperType)) {
				upper = this.upper;
				upperType = this.upperType;
			} else {
				upper = other.upper;
				upperType = other.upperType;
			}
			return new Range<C>(lower, lowerType, upper, upperType, comparator);
		}

		@Override
		public boolean equals(Object object) {
			if (this == object) return true;
			if (object instanceof Range) {
				@SuppressWarnings("unchecked")
				Range<C> comp = (Range<C>) object;
				return compareLower(comp.lower, comp.lowerType) == 0 && compareUpper(comp.upper, comp.upperType) == 0 && lowerType == comp.lowerType && upperType == comp.upperType;
			}
			return false;
		}

		@Override
		public int hashCode() {
			if (lower == null && upper == null) return 0;
			else if (lower == null) return upper.hashCode();
			else if (upper == null) return lower.hashCode();
			return lower.hashCode() ^ upper.hashCode();
		}

		@Override
		public String toString() {
			if (isEmpty()) return "()";
			return (lowerType == BoundType.OPEN ? "(" : "[") + (lower == null ? "" : lower.toString()) + ".." + (upper == null ? "" : upper.toString()) + (upperType == BoundType.OPEN ? ")" : "]");
		}
	}

	public static class IterableRange<C> extends Range<C> implements Iterable<C>{

		private static final long serialVersionUID = 9065915259748260688L;
		protected UnaryOperator<C> func;

		protected IterableRange(C lower, BoundType lowerType, C upper, BoundType upperType, UnaryOperator<C> func) {
			super(lower, lowerType, upper, upperType);
			this.func = func;
		}

		public static <C extends Comparable<? super C>> IterableRange<C> range(C lower, BoundType lowerType, C upper, BoundType upperType, UnaryOperator<C> func) {
			if (lower == null || upper == null) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			int comp = lower.compareTo(upper);
			if (comp > 0) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			else if (comp == 0 && (lowerType == BoundType.OPEN || upperType == BoundType.OPEN)) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			return new IterableRange<C>(lower, lowerType, upper, upperType, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> open(C lower, C upper, UnaryOperator<C> func) {
			if (lower == null) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			return range(func.apply(lower), BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> openClosed(C lower, C upper, UnaryOperator<C> func) {
			if (lower == null) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			return range(func.apply(lower), BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> closedOpen(C lower, C upper, UnaryOperator<C> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> closed(C lower, C upper, UnaryOperator<C> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> singleton(C value, UnaryOperator<C> func) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED, func);
		}

		protected class Iter implements Iterator<C> {
			C now;
			Iter() {
				now = lower;
			}
			@Override
			public final boolean hasNext() {
				return !isGreater(now);
			}

			@Override
			public final C next() {
				C ret = now;
				now = func.apply(now);
				return ret;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}
		}

		protected class EmptyIter implements Iterator<C> {

			@Override
			public boolean hasNext() {
				return false;
			}

			@Override
			public C next() {
				return null;
			}

		}

		@Override
		public Iterator<C> iterator() {
			return lower == null || upper == null ? new EmptyIter() : new Iter();
		}

		public int getDistance() {
			C check = upper;
			int ret = 0;
			while (lower != check) {
				check = func.apply(check);
				++ ret;
			}
			return ret;
		}
	}

	public static class IntRange extends IterableRange<Integer>{

		private static final long serialVersionUID = 5623995336491967216L;
		private final boolean useFastIter;

		private static class Next implements UnaryOperator<Integer> {

			@Override
			public Integer apply(Integer value) {
				return value + 1;
			}
		}

		protected IntRange() {
			super(null, BoundType.CLOSED, null, BoundType.CLOSED, new Next());
			useFastIter = true;
		}

		protected IntRange(UnaryOperator<Integer> func) {
			super(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			useFastIter = false;
		}

		protected IntRange(int lower, BoundType lowerType, int upper, BoundType upperType) {
			super(lower, lowerType, upper, upperType, new Next());
			useFastIter = true;
		}

		protected IntRange(int lower, BoundType lowerType, int upper, BoundType upperType, UnaryOperator<Integer> func) {
			super(lower, lowerType, upper, upperType, func);
			useFastIter = false;
		}

		public static IntRange range(int lower, BoundType lowerType, int upper, BoundType upperType) {
			if (lower > upper) return new IntRange();
			if (lowerType == BoundType.OPEN) ++ lower;
			if (upperType == BoundType.OPEN) -- upper;
			return new IntRange(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static IntRange range(int lower, BoundType lowerType, int upper, BoundType upperType, UnaryOperator<Integer> func) {
			if (lower > upper) return new IntRange(func);
			if (lowerType == BoundType.OPEN) ++ lower;
			if (upperType == BoundType.OPEN) -- upper;
			return new IntRange(lower, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static IntRange open(int lower, int upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN);
		}

		public static IntRange open(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN, func);
		}

		public static IntRange open(int upper) {
			return range(0, BoundType.CLOSED, upper, BoundType.OPEN);
		}

		public static IntRange open(int upper, UnaryOperator<Integer> func) {
			return range(0, BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static IntRange openClosed(int lower, int upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED);
		}

		public static IntRange openClosed(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED, func);
		}

		public static IntRange closedOpen(int lower, int upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN);
		}

		public static IntRange closedOpen(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static IntRange closed(int lower, int upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static IntRange closed(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static IntRange closed(int upper) {
			return range(0, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static IntRange closed(int upper, UnaryOperator<Integer> func) {
			return range(0, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static IntRange singleton(int value) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED);
		}

		public static IntRange singleton(int value, UnaryOperator<Integer> func) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED, func);
		}

		private class FastIter implements Iterator<Integer> {
			int now;
			public FastIter() {
				now = lower;
			}
			@Override
			public final boolean hasNext() {
				return now <= upper;
			}

			@Override
			public final Integer next() {
				return now++;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}
		}

		private class Iter implements Iterator<Integer> {
			int now;
			public Iter() {
				now = lower;
			}
			@Override
			public final boolean hasNext() {
				return now <= upper;
			}

			@Override
			public final Integer next() {
				int ret = now;
				now = func.apply(now);
				return ret;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}
		}

		@Override
		public Iterator<Integer> iterator() {
			return lower == null || upper == null ? new EmptyIter() : useFastIter ? new FastIter() : new Iter();
		}

		@Override
		public int getDistance() {
			int ret = upper - lower;
			if (upperType == BoundType.CLOSED) ++ ret;
			return ret;
		}

		public int getClosedLower() {
			return lower;
		}

		public int getOpenLower() {
			return lower - 1;
		}

		public int getClosedUpper() {
			return upperType == BoundType.CLOSED ? upper : upper - 1;
		}

		public int getOpenUpper() {
			return upperType == BoundType.CLOSED ? upper + 1 : upper;
		}
	}

	public interface Ring<T> {
		public T add(T left, T right);
		public T addUnit();
		public T addInverse(T element);
		public T multiply(T left, T right);
		public T multiplyUnit();
		public T multiplyInverse(T element);
	}

	public class ModInteger extends Number implements Ring<ModInteger>{

		private static final long serialVersionUID = -8595710127161317579L;
		private final int mod;
		private int num;

		public ModInteger(int mod) {
			this.mod = mod;
			num = 0;
		}

		public ModInteger(int mod, int num) {
			this.mod = mod;
			this.num = validNum(num);
		}

		public ModInteger(ModInteger n) {
			mod = n.mod;
			num = n.num;
		}

		private ModInteger(ModInteger n, int num) {
			mod = n.mod;
			this.num = num;
		}

		private int validNum(int n) {
			n %= mod;
			if (n < 0) n += mod;
			return n;
		}

		protected int inverse(int n) {
			 int m = mod, u = 0, v = 1, t;
			 while(n != 0) {
				 t = m / n;
				 m -= t * n;
				 u -= t * v;
				 if (m != 0) {
					 t = n / m;
					 n -= t * m;
					 v -= t * u;
				 } else {
					 v %= mod;
					 if (v < 0) v += mod;
					 return v;
				 }
			 }
			 u %= mod;
			 if (u < 0) u += mod;
			 return u;
		}

		public boolean isPrime(int n) {
			if ((n & 1) == 0) return false; // 偶数
			for (int i = 3, j = 8, k = 9;k <= n;i += 2, k += j += 8) if (n % i == 0) return false;
			return true;
		}

		@Override
		public int intValue() {
			return num;
		}

		@Override
		public long longValue() {
			return num;
		}

		@Override
		public float floatValue() {
			return num;
		}

		@Override
		public double doubleValue() {
			return num;
		}

		public ModInteger add(int n) {
			return new ModInteger(this).addEqual(n);
		}

		public ModInteger add(ModInteger n) {
			return new ModInteger(this).addEqual(n);
		}

		public ModInteger addEqual(int n) {
			num = validNum(num + n);
			return this;
		}

		public ModInteger addEqual(ModInteger n) {
			if ((num += n.num) >= mod) num -= mod;
			return this;
		}

		public ModInteger subtract(int n) {
			return new ModInteger(this).subtractEqual(n);
		}

		public ModInteger subtract(ModInteger n) {
			return new ModInteger(this).subtractEqual(n);
		}

		public ModInteger subtractEqual(int n) {
			num = validNum(num - n);
			return this;
		}

		public ModInteger subtractEqual(ModInteger n) {
			if ((num -= n.num) < 0) num += mod;
			return this;
		}

		@Override
		public ModInteger add(ModInteger left, ModInteger right) {
			return new ModInteger(left).addEqual(right);
		}

		@Override
		public ModInteger addUnit() {
			return new ModInteger(mod, 0);
		}

		@Override
		public ModInteger addInverse(ModInteger element) {
			return new ModInteger(element, element.mod - element.num);
		}

		public ModInteger multiply(int n) {
			return new ModInteger(this).multiplyEqual(n);
		}

		public ModInteger multiply(ModInteger n) {
			return new ModInteger(this).multiplyEqual(n);
		}

		public ModInteger multiplyEqual(int n) {
			num = (int)((long)num * n % mod);
			if (num < 0) num += mod;
			return this;
		}

		public ModInteger multiplyEqual(ModInteger n) {
			num = (int)((long)num * n.num % mod);
			return this;
		}

		public ModInteger divide(int n) {
			return new ModInteger(this).divideEqual(n);
		}

		public ModInteger divide(ModInteger n) {
			return new ModInteger(this).divideEqual(n);
		}

		public ModInteger divideEqual(int n) {
			num = (int)((long)num * inverse(validNum(n)) % mod);
			return this;
		}

		public ModInteger divideEqual(ModInteger n) {
			num = (int)((long)num * n.inverse(n.num) % mod);
			return this;
		}

		@Override
		public ModInteger multiply(ModInteger left, ModInteger right) {
			return new ModInteger(left).multiplyEqual(right);
		}

		@Override
		public ModInteger multiplyUnit() {
			return new ModInteger(this, 1);
		}

		@Override
		public ModInteger multiplyInverse(ModInteger element) {
			return new ModInteger(element, element.inverse(element.num));
		}

		public ModInteger pow(int n) {
			return new ModInteger(this).powEqual(n);
		}

		public ModInteger pow(ModInteger n) {
			return new ModInteger(this).powEqual(n);
		}

		public ModInteger powEqual(int n) {
			long ans = 1, num = this.num;
			if (n < 0) {
				n = -n;
				while (n != 0) {
					if ((n & 1) != 0) ans = ans * num % mod;
					n >>>= 1;
					num = num * num % mod;
				}
				this.num = inverse((int)ans);
				return this;
			}
			while (n != 0) {
				if ((n & 1) != 0) ans = ans * num % mod;
				n >>>= 1;
				num = num * num % mod;
			}
			this.num = (int)ans;
			return this;
		}

		public ModInteger powEqual(ModInteger n) {
			long num = this.num;
			this.num = 1;
			int mul = n.num;
			while (mul != 0) {
				if ((mul & 1) != 0) this.num *= num;
				mul >>>= 1;
				num *= num;
				num %= mod;
			}
			return this;
		}

		public ModInteger equal(int n) {
			num = validNum(n);
			return this;
		}

		public ModInteger equal(ModInteger n) {
			num = n.num;
			return this;
		}

		public int toInt() {
			return num;
		}

		public int getMod() {
			return mod;
		}

		@Override
		public boolean equals(Object x) {
			if (x instanceof ModInteger) return ((ModInteger)x).num == num && ((ModInteger)x).mod == mod;
			return false;
		}

		@Override
		public int hashCode() {
			return num ^ mod;
		}

		@Override
		public String toString() {
			return String.valueOf(num);
		}

		@Deprecated
		public String debug() {
			int min = num, ans = 1;
			for (int i = 2;i < min;++ i) {
				int tmp = multiply(i).num;
				if (min > tmp) {
					min = tmp;
					ans = i;
				}
			}
			return min + "/" + ans;
		}
	}

	/**
	 * 素数を法とする演算上で、組み合わせの計算を高速に行います。
	 * @author 31536000
	 *
	 */
	public class ModUtility {
		private final int mod, totient;
		private int[] fact, inv, invfact;
		/**
		 * modを法とする
		 * @param mod
		 */
		public ModUtility(int mod) {
			this(mod, 2);
		}

		public ModUtility(int mod, int calc) {
			if (mod <= 0) throw new IllegalArgumentException("illegal mod: " + mod);
			this.mod = mod;
			int totient = mod;
			for (int i = 2;i * i <= mod;++ i) {
				if (mod % i == 0) {
					totient = totient / i * (i - 1);
					while ((mod %= i) % i == 0);
				}
			}
			this.totient = totient;
			precalc(calc);
		}

		public void precalc(int calc) {
			if (calc < 2) calc = 2;
			fact = new int[calc];
			inv = new int[calc];
			invfact = new int[calc];
			fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
			for (int i = 2;i < calc;++ i) {
				fact[i] = (int)((long)fact[i - 1] * i % mod);
				inv[i] = (int)(mod - (long)inv[mod % i] * (mod / i) % mod);
				invfact[i] = (int)((long)invfact[i - 1] * inv[i] % mod);
			}
		}

		public ModInteger create() {
			return create(0);
		}

		public ModInteger create(int n) {
			return new ModInt(n);
		}

		private class ModInt extends ModInteger {

			private static final long serialVersionUID = -2435281861935422575L;

			public ModInt(int n) {
				super(mod, n);
			}

			@Override
			protected int inverse(int n) {
				return ModUtility.this.inverse(n);
			}
		}

		public int inverse(int n) {
			try {
				if (inv.length > n) return inv[n];
				 int m = mod, u = 0, v = 1, t;
				 while(n != 0) {
					 t = m / n;
					 m -= t * n;
					 u -= t * v;
					 if (m != 0) {
						 t = n / m;
						 n -= t * m;
						 v -= t * u;
					 } else {
						 v %= mod;
						 if (v < 0) v += mod;
						 return v;
					 }
				 }
				 u %= mod;
				 if (u < 0) u += mod;
				 return u;
			} catch (ArrayIndexOutOfBoundsException e) {
				throw new IllegalArgumentException();
			}
		}

		public int factorial(int n) {
			try {
				if (fact.length > n) return fact[n];
				long ret = fact[fact.length - 1];
				for (int i = fact.length;i <= n;++ i) ret = ret * i % mod;
				return (int)ret;
			} catch (ArrayIndexOutOfBoundsException e) {
				throw new IllegalArgumentException();
			}
		}

		public int permutation(int n, int k) {
			if (k < 0) throw new IllegalArgumentException();
			if (n < k) return 0;
			if (fact.length > n) return (int)((long)fact[n] * invfact[n - k] % mod);
			long ret = 1;
			for (int i = n - k + 1;i <= n;++ i) ret = ret * i % mod;
			return (int)ret;
		}

		public int combination(int n, int k) {
			if (k < 0) throw new IllegalArgumentException();
			if (n < k) return 0;
			if (fact.length > n) return (int)((long)fact[n] * invfact[k] % mod * invfact[n - k] % mod);
			long ret = 1;
			if (n < 2 * k) k = n - k;
			if (invfact.length > k) ret = invfact[k];
			else ret = inverse(factorial(k));
			for (int i = n - k + 1;i <= n;++ i) ret = ret * i % mod;
			return (int)ret;
		}

		public int multinomial(int n, int... k) {
			int sum = 0;
			for (int i : k) sum += i;
			long ret = factorial(n);
			if (fact.length > n) {
				for (int i : k) {
					if (i < 0) throw new IllegalArgumentException();
					ret = ret * invfact[i] % mod;
					sum += i;
				}
				if (sum > n) return 0;
				ret = ret * invfact[n - sum] % mod;
			} else {
				for (int i : k) {
					if (i < 0) throw new IllegalArgumentException();
					if (invfact.length > i) ret = ret * invfact[i] % mod;
					else ret = ret * inverse(factorial(i)) % mod;
					sum += i;
				}
				if (sum > n) return 0;
				if (invfact.length > n - sum) ret = ret * invfact[n - sum] % mod;
				else ret = ret * inverse(factorial(n - sum)) % mod;
			}
			return (int)ret;
		}

		public int multichoose(int n, int k) {
			return combination(n + k - 1, k);
		}

		public int pow(int n, int m) {
			long ans = 1, num = n;
			if (m < 0) {
				m = -m;
				while (m != 0) {
					if ((m & 1) != 0) ans = ans * num % mod;
					m >>>= 1;
					num = num * num % mod;
				}
				return inverse((int)ans);
			}
			while (m != 0) {
				if ((m & 1) != 0) ans = ans * num % mod;
				m >>>= 1;
				num = num * num % mod;
			}
			return (int)ans;
		}

		public int pow(long n, long m) {
			return pow((int)(n % mod), (int)(n % (mod - 1)));
		}

		public int totient() {
			return totient;
		}

		public boolean isPrime() {
			return totient == mod - 1;
		}

		public int mod(int n) {
			return (n %= mod) < 0 ? n + mod : n;
		}

		public int add(int n, int m) {
			return mod(n + m);
		}

		public int subtract(int n, int m) {
			return mod(n - m);
		}

		public int multiply(int n, int m) {
			int ans = (int)((long)n * m % mod);
			return ans < 0 ? ans + mod : ans;
		}

		public int divide(int n, int m) {
			return multiply(n, inverse(m));
		}
	}
}
