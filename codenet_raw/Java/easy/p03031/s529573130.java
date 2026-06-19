import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

import static java.util.Comparator.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        Solver solver = new Solver(System.in, out);
        solver.solve();
        out.close();
    }
}
class Solver {
	Scanner sc;
	PrintWriter out;
    public Solver(InputStream in, PrintWriter out) {
    	sc = new Scanner(in);
    	this.out = out;
    }
    // ======================================================================
    public void solve() {
    	int N = ni();					// スイッチの数
    	int M = ni();					// 電球の数
    	int[] K = new int[M];			// 電球がつながっているスイッチの数
    	int[][] S = new int[M][N];		// 電球がつながっているスイッチ
    	int[] P = new int[M];			// 電球がつく条件
    	for (int i = 0; i < M; i++) {
			K[i] = ni();
			for (int j = 0; j < K[i]; j++) {
				S[i][j] = ni() - 1;
			}
		}
    	for (int i = 0; i < M; i++) {
			P[i] = ni();
		}
    	int ans = 0, cnt;
    	LOOP:
    	for (int i = 1; i < (1 << N); i++) {
			for (int j = 0; j < M; j++) {
				cnt = 0;
				for (int j2 = 0; j2 < K[j]; j2++) {
//					out.println(" i = " + Integer.toBinaryString(i) 
//							+ "  &  " + Integer.toBinaryString(1 << S[j][j2]));
					if((i & (1 << S[j][j2])) != 0) {
						cnt++;
//						out.println(" cnt = " + cnt);
					}
				}
//				out.println(" i = " + i + "  j = " + j 
//						+ "  cnt = " + cnt + "  P[j] = " + P[j]);
				if(cnt % 2 != P[j])		continue LOOP;
			}
			ans++;
//			out.println(" ans = " + ans);
    	}
    	out.println(ans);
    }
    // ------------------------------------------
    // 入力
    // ------------------------------------------
    public int ni() {
    	return sc.nextInt();
    }
    public long nl() {
    	return sc.nextLong();
    }
    public String ns() {
    	return sc.next();
    }
    public char[] nc() {
    	return sc.next().toCharArray();
    }
    public int[] ndi(int N) {
    	int[] ans = new int[N];
    	for (int i = 0; i < N; i++) {
			ans[i] = ni();
		}
    	return ans;
    }
    public long[] ndl(int N) {
    	long[] ans = new long[N];
    	for (int i = 0; i < N; i++) {
			ans[i] = nl();
		}
    	return ans;
    }
    public String[] nds(int N) {
    	String[] ans = new String[N];
    	for (int i = 0; i < N; i++) {
			ans[i] = ns();
		}
    	return ans;
    }
    public char[][] ndc(int N) {
    	char[][] ans = new char[N][];
    	for (int i = 0; i < N; i++) {
			ans[i] = nc();
		}
    	return ans;
    }
    public int[][] nddi(int N, int S) {
    	int[][] ans = new int[N][S];
    	for (int i = 0; i < N; i++) {
			for (int j = 0; j < S; j++) {
				ans[i][j] = ni();
			}
		}
    	return ans;
    }
}
