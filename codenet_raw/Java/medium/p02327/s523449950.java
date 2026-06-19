import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Main {
	static boolean debug = false;

	public static void main(String[] args) throws IOException {

		UserScanner scan = new UserScanner();
		PrintWriter pwriter = new PrintWriter(System.out);

		int h = scan.nextInt();
		int w = scan.nextInt();

		Rectangle rg = new Rectangle(h, w, debug);

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				rg.addTile(i, j, scan.nextInt());

		pwriter.println(rg.getMaxRect());

		pwriter.flush();
		scan.close();
		System.exit(0);
	}
}

class Rectangle {
	boolean debug;
	int[][] maxh;

	public Rectangle(int h, int w, boolean debug) {
		this.debug = debug;
		maxh = new int[h][w];
	}

	int maxArea = 0;

	public int getMaxRect() {
		setMaxh(); // set the number of upper continues clear tile

		for (int h = maxh.length - 1; h >= 0; h--)
			if ((h + 1) * maxh[0].length > maxArea)
				getMaxArea(h);
		return maxArea;
	}

	class Hbar {
		int height;
		int wstart;

		public Hbar(int h, int w) {
			height = h;
			wstart = w;
		}
	}

	private void getMaxArea(int line) {
		// get max rectangle which lower edge is on line
		List<Hbar> hbar = new ArrayList<Hbar>();

		for (int w = 0; w < maxh[0].length; w++)
			maxArea = Math.max(maxArea, addBar(hbar, maxh[line][w], w));

		maxArea = Math.max(maxArea, addBar(hbar, 0, maxh[0].length));
	}

	private int addBar(List<Hbar> hbar, int h, int w) {
		// calculate the area of rectangles which is higher than myself
		int area = 0;
		int start = w;
		while (!hbar.isEmpty() && hbar.get(0).height > h) {
			area = Math.max(area, (w - hbar.get(0).wstart) * hbar.get(0).height);
			start = Math.min(start, hbar.get(0).wstart);
			hbar.remove(0);
		}
		// and add myself as start point of new height bar
		if (h > 0 && h * (maxh[0].length - start) > maxArea)
			if (hbar.isEmpty() || h > hbar.get(0).height)
				hbar.add(0, new Hbar(h, start));

		return area;
	}

	private void setMaxh() {
		for (int h = 1; h < maxh.length; h++)
			for (int w = 0; w < maxh[0].length; w++)
				if (maxh[h][w] > 0)
					maxh[h][w] = maxh[h - 1][w] + 1;
	}

	public void addTile(int h, int w, int c) {
		// set 1 to clear tile
		if (c == 1)
			maxh[h][w] = 0;
		else
			maxh[h][w] = 1;
	}
}

class UserScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	private boolean read() throws IOException {
		ptr = 0;
		buflen = in.read(buffer);
		if (buflen <= 0)
			return false;
		else
			return true;
	}

	private byte getByte() throws IOException {
		if (ptr >= buflen)
			read();
		if (isCtlSpace(buffer[ptr])) {
			return -1;
		} else
			return buffer[ptr++];
	}

	private void skipCtlSpace() throws IOException {
		if (ptr >= buflen)
			read();
		if (isCtlSpace(buffer[ptr])) {
			ptr++;
			skipCtlSpace();
		}
	}

	private boolean isCtlSpace(byte b) {
		if (b <= ' ' || b > '~')
			return true;
		else
			return false;
	}

	public void close() throws IOException {
		in.close();
	}

	public String next() throws IOException {
		skipCtlSpace();
		StringBuilder sb = new StringBuilder();
		byte b;
		while ((b = getByte()) != -1) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() throws IOException {
		skipCtlSpace();
		int n = 0;
		boolean minus = false;
		byte b;
		while ((b = getByte()) != -1) {
			if (b == '-')
				minus = true;
			else {
				n *= 10;
				n += (b - '0');
			}
		}
		if (minus)
			return n * -1;
		else
			return n;
	}
}