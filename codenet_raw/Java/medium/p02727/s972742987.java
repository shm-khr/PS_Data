import java.util.*;
import static java.lang.System.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		PriorityQueue<Apple> que = new PriorityQueue<>();
		ArrayList<Integer> list = new ArrayList<>();
		int X = sc.nextInt();  //食べる個数
		int Y = sc.nextInt();  //食べる個数
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		for(int i = 0; i < a; i++) {
			Apple apple = new Apple('R', sc.nextInt());
			que.offer(apple);
		}
		for(int i = 0; i < b; i++) {
			Apple apple = new Apple('G', sc.nextInt());
			que.offer(apple);			
		}
		for(int i = 0; i < c; i++) {
		list.add(sc.nextInt());
		}
		
		Collections.sort(list);
		int cntRed = 0; int cntGreen = 0;
		long sum = 0;
		while(!(cntRed == X && cntGreen == Y)) {
			Apple apple = que.poll();
			if (apple.color == 'R' && cntRed == X || apple.color == 'G' && cntGreen == Y) continue;
			char eatColor = apple.color;
			int whiteNum = 0;
			if ( list.size() == 0) whiteNum = -1;
			else  whiteNum = list.get(list.size() - 1);
			if (apple.number >= whiteNum) {
				sum += apple.number;
			} else {
				sum += whiteNum;
				list.remove(list.size() - 1);
			}
			if (eatColor == 'R') cntRed++;
			else if (eatColor == 'G') cntGreen++;
		}
		
		out.println(sum);
		
		out.close();
	}

static class Apple implements Comparable<Apple>{
		char color;
		Integer number;
		
		Apple(char color, int number){
			this.color = color;
			this.number = number;
		}

		@Override
		public int compareTo(Apple o) {			
			return - ( this.number.compareTo(o.number) );
		}
		
}

static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
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
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}
}