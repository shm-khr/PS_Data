import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		List<Point> goods = new ArrayList<>(), bads = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			Point point = new Point(A, B);
			if (A < B) goods.add(point);
			else bads.add(point);
		}
		Collections.sort(goods, (p1, p2) -> Long.compare(p1.B, p2.B));
		Collections.sort(bads, (p1, p2) -> Long.compare(p1.A, p2.A));
		int left = 0, right = N;
		while (left + 1 < right) {
			int med = (left + right) / 2;
			long sum = 0;
			int i, fromGood = 0;
			for (i = 0; i < med && i < bads.size(); i++) {
				sum += bads.get(i).A;
			}
			for (; i < med; i++) {
				sum += goods.get(i - bads.size()).A;
				fromGood = i - bads.size() + 1;
			}
			for (int j = fromGood; j < goods.size(); j++) {
				Point point = goods.get(j);
				sum += point.A - point.B;
			}
			boolean can = false;
			if (sum <= 0) can = true;
			int lastBad = Math.min(med, bads.size()) - 1;
			while (lastBad >= 0 && fromGood < goods.size() && !can) {
				sum -= bads.get(lastBad).A;
				Point tmp = goods.get(fromGood);
				sum += tmp.A;
				sum -= tmp.A - tmp.B;
				if (sum <= 0) can = true;
				lastBad--; fromGood++;
			}
			if (can) left = med;
			else right = med;
		}
		int med = left;
		long sumBad = 0, sumRec = 0;
		int i, fromGood = 0;
		for (i = 0; i < med && i < bads.size(); i++) {
			sumBad += bads.get(i).A;
		}
		for (; i < med; i++) {
			sumBad += goods.get(i - bads.size()).A;
			fromGood = i - bads.size() + 1;
		}
		for (int j = fromGood; j < goods.size(); j++) {
			Point point = goods.get(j);
			sumRec += point.A - point.B;
		}
		boolean can = false;
		if (sumBad + sumRec <= 0) can = true;
		int lastBad = Math.min(med, bads.size()) - 1;
		while (lastBad >= 0 && fromGood < goods.size() && !can) {
			sumBad -= bads.get(lastBad).A;
			Point tmp = goods.get(fromGood);
			sumBad += tmp.A;
			sumRec -= tmp.A - tmp.B;
			if (sumBad + sumRec <= 0) can = true;
			lastBad--; fromGood++;
		}
		Fraction ans = new Fraction(med, N);
		if (sumBad + sumRec < 0) {
			for (int j = 0; j < bads.size(); j++) {
				Point tmp = bads.get(j);
				if (j <= lastBad) {
					if (lastBad + 1 >= bads.size()) continue;
					sumBad += bads.get(lastBad + 1).A;
					sumBad -= bads.get(j).A;
				}
				long num = -(sumBad + tmp.A + sumRec) + tmp.B;
				if (num > 0) {
					Fraction val = new Fraction(num + tmp.B * med, tmp.B * N);
					if (ans.compareTo(val) < 0) ans = val;
				}
				if (j <= lastBad) {
					sumBad -= bads.get(lastBad + 1).A;
					sumBad += bads.get(j).A;
				}
			}
			if (fromGood < goods.size()) {
				Point tmp = goods.get(fromGood);
				sumRec -= tmp.A - tmp.B;
				long num = -(sumBad + tmp.A + sumRec) + tmp.B;
				if (num > 0) {
					Fraction val = new Fraction(num + tmp.B * med, tmp.B * N);
					if (ans.compareTo(val) < 0) ans = val;
				}
			}
			
		}
		out.println(ans);
		
		out.flush();
	}
	
	
	static class Point{
		long A, B;
		
		public Point(long a, long b) {
			A = a;
			B = b;
		}
	}
	
	static class Fraction implements Comparable<Fraction> {
		long num, den;
		
		public Fraction(long num, long den) {
			long gcd = gcd(num, den);
			this.num = num / gcd;
			this.den = den / gcd;
		}
		
		@Override
		public String toString() {
			return num + " " + den;
		}
		
		@Override
		public int compareTo(Fraction o) {
			long me = num * o.den;
			long other = o.num * den;
			return Long.compare(me, other);
		}
	}
	
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a%b);
	}
	
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
