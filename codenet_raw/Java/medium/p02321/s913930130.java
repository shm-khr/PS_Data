import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int N = sc.nextInt();
		long W = sc.nextLong();
		long[] v = new long[N];
		long[] w = new long[N];
		for(int i=0; i<N; i++) {
			v[i] = sc.nextLong();
			w[i] = sc.nextLong();
		}
		
		if(N <= 20) {
			long max = 0;
			for(int i=0; i<Math.pow(2, N); i++) {
				long vsum = 0;
				long wsum = 0;
				for(int j=0; j<N; j++) {
					if((i >> j & 1) == 1) {
						vsum += v[j];
						wsum += w[j];
					}
				}
				if(wsum <= W && vsum > max) {
					max = vsum;
				}
			}
			System.out.println(max);
		} else {
			ArrayList<Set> set1 = new ArrayList<>();
			for(int i=0; i<Math.pow(2, 20); i++) {
				long vsum = 0;
				long wsum = 0;
				for(int j=0; j<20; j++) {
					if((i >> j & 1) == 1) {
						vsum += v[j];
						wsum += w[j];
					}
				}
				set1.add(new Set(vsum, wsum));
			}
			ArrayList<Set> set2 = new ArrayList<>();
			for(int i=0; i<Math.pow(2, N-20); i++) {
				long vsum = 0;
				long wsum = 0;
				for(int j=0; j<N-20; j++) {
					if((i >> j & 1) == 1) {
						vsum += v[j+20];
						wsum += w[j+20];
					}
				}
				set2.add(new Set(vsum, wsum));
			}
			Collections.sort(set2, (a, b) -> a.wsum > b.wsum ? -1 : 1);
			long temp = 0;
			for(int i=0; i<set2.size(); i++) {
				if(set2.get(i).vsum > temp) {
					temp = set2.get(i).vsum;
				} else if(set2.get(i).vsum < temp) {
					set2.get(i).vsum = temp;
				}
			}
			long max = 0;
			for(int i=0; i<set1.size(); i++) {
				long wrest = W - set1.get(i).wsum;
				int l = 0;
				int r = set2.size() - 1;
				int m = (l + r) / 2;
				while(l < r) {
					if(set2.get(m).wsum > wrest) {
						r = m - 1;
					} else if(set2.get(m).wsum < wrest) {
						if(set2.get(m+1).wsum > wrest) {
							break;
						} else {
							l = m + 1;
						}
					} else {
						while(true) {
							if(set2.get(m+1).wsum == set2.get(m).wsum) {
								m++;
							} else {
								break;
							}
						}
						break;
					}
					m = (l + r) / 2;
				}
				if(set1.get(i).vsum + set2.get(m).vsum > max) {
					max = set1.get(i).vsum + set2.get(m).vsum;
				}
			}
			System.out.println(max);
		}
	}
	
	static class Set {
		long vsum;
		long wsum;
		Set(long vsum, long wsum) {
			this.vsum = vsum;
			this.wsum = wsum;
		}
	}
	
	static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
        public boolean hasNext() { skipUnprintable(); return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt(){
            return Integer.parseInt(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}