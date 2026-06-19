import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Collections;
public class Main {
	public static ArrayList<Long> primes = new ArrayList<>();
	public static ArrayList<Long> squares = new ArrayList<>();
	public static ArrayList<Long> cubes = new ArrayList<>();

	private static class Pair implements Comparable<Pair> {
		long red;
		int a;
		public Pair(long v) {
			red = v;
			a = 1;
		}
		public int compareTo(Pair p) {
			return p.a-a;
		}
	}
	public static void main(String args[]) {
		Sc sc = new Sc(System.in);
		int n = sc.nI();
		HashMap<Long,Pair> map = new HashMap<>();
		ArrayList<Pair> pairs = new ArrayList<>();
		primes.add(2L);
		squares.add(4L);
		cubes.add(8L);
		for(long i = 3; i<=100000; i+=2) {
			long sqrt = (long) Math.sqrt(i);
			boolean prime = true;
			for(int j = 1; j<primes.size(); j++) {
				long p = primes.get(j);
				if(p>sqrt) break;
				if(i%p == 0) {
					prime = false;
					break;
				}
			}
			if(prime) {
				primes.add(i);
				squares.add(i*i);
				cubes.add(i*i*i);
			}
		}
		for(int i = 0; i<n; i++) {
			long v = reduce(sc.nL());
			if(map.containsKey(v)) {
				Pair p = map.get(v);
				p.a++;
			} else {
				Pair p = new Pair(v);
				map.put(v,p);
				pairs.add(p);
			}
		}
		
		Collections.sort(pairs);
		HashSet<Long> set = new HashSet<>();
		int picked = 0;
		boolean pickedc = false;
		for(Pair p:pairs) {
			if(p.red == 1) {
				if(!pickedc)
					picked++;
				pickedc = true;
				continue;
			}
			if(!set.contains(p.red)) {
				picked+=p.a;
				long inv = inv(p.red);
				if(inv != -1) {
					if(!set.contains(inv)) set.add(inv);
				}
			}
		}

		System.out.println(picked);
	}
	public static long inv(long v) {
		long ret = 1;
		for(int i = 0; i<primes.size() ; i++) {
			long p = primes.get(i);
			long sq = squares.get(i);
			if(sq>v) break;
			if(v%sq == 0) {
				ret *= p;
				v /= sq;
			} else if(v%p == 0) {
				ret *= sq;
				v /= p;
			}
			if(ret>10000000000L) return -1;
		}
		return (v>100000) ? -1 : ret*v*v;
	}
	public static long reduce(long v) {
		for(int i = 0; i<primes.size(); i++) {
			long cube = cubes.get(i);
			if(cube>v) break;
			while(v%cube == 0) {
				v /= cube;
			}
		}
		return v;
	}
}
class Sc {
    public Sc(InputStream i) {
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasM() {
        return peekToken() != null;
    }

    public int nI() {
        return Integer.parseInt(nextToken());
    }

    public double nD() { 
        return Double.parseDouble(nextToken());
    }

    public long nL() {
        return Long.parseLong(nextToken());
    }

    public String n() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null) 
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}