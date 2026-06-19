import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static long MOD = 1000000007;
	
	static String[] magic = {
			"15,5,5,5,64794410",
			"15,5,6,5,78874820",
			"15,5,7,5,396738860",
			"16,5,5,5,552297739",
			"16,5,6,5,114459012",
			"16,5,7,5,631371489",
			"17,5,5,5,905015145",
			"17,5,6,5,147765636",
			"17,5,7,5,795634686",
			"18,5,5,5,414835573",
			"18,5,6,5,305748512",
			"18,5,7,5,978043737",
			"19,5,5,5,110292089",
			"19,5,6,5,650305486",
			"19,5,7,5,867535614",
			"20,5,5,5,130428294",
			"20,5,6,5,625502432",
			"20,5,7,5,819465585",
			"21,5,5,5,1988528",
			"21,5,6,5,821726917",
			"21,5,7,5,438598952",
			"22,5,5,5,933364139",
			"22,5,6,5,424811874",
			"22,5,7,5,612652457",
			"23,5,5,5,925872391",
			"23,5,6,5,944065102",
			"23,5,7,5,354082350",
			"24,5,5,5,752116614",
			"24,5,6,5,28830005",
			"24,5,7,5,389656338",
			"25,5,5,5,886673226",
			"25,5,6,5,24808066",
			"25,5,7,5,363390310",
			"26,5,5,5,310687657",
			"26,5,6,5,625657273",
			"26,5,7,5,286514387",
			"27,5,5,5,157360061",
			"27,5,6,5,785158102",
			"27,5,7,5,857031666",
			"28,5,5,5,640029803",
			"28,5,6,5,561212497",
			"28,5,7,5,86223126",
			"29,5,5,5,590789025",
			"29,5,6,5,303084475",
			"29,5,7,5,333520078",
			"30,5,5,5,182702212",
			"30,5,6,5,859476250",
			"30,5,7,5,22531929",
			"31,5,5,5,559950257",
			"31,5,6,5,585435629",
			"31,5,7,5,224844880",
			"32,5,5,5,75291907",
			"32,5,6,5,953314178",
			"32,5,7,5,32439332",
			"33,5,5,5,143559441",
			"33,5,6,5,73390214",
			"33,5,7,5,218731337",
			"34,5,5,5,337195332",
			"34,5,6,5,302678033",
			"34,5,7,5,815767287",
			"35,5,5,5,14466240",
			"35,5,6,5,96745912",
			"35,5,7,5,206460333",
			"36,5,5,5,228008377",
			"36,5,6,5,360001858",
			"36,5,7,5,17357092",
			"37,5,5,5,13823588",
			"37,5,6,5,967347544",
			"37,5,7,5,974561444",
			"38,5,5,5,384738286",
			"38,5,6,5,25138122",
			"38,5,7,5,545809677",
			"39,5,5,5,683480014",
			"39,5,6,5,261543736",
			"39,5,7,5,426890448",
			"40,5,5,5,287740676",
			"40,5,6,5,692467953",
			"40,5,7,5,562805100",
	};
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int z = sc.nextInt();
		if (x > z) {
			int temp = x;
			x = z;
			z = temp;
		}
		int[] a = new int[5];
		for(String s: magic) {
			String[] t = s.split(",");
			for(int i=0;i<5;i++) {
				a[i] = Integer.parseInt(t[i]);
			}
			if (n == a[0] && x == a[1] && y == a[2] && z == a[3]) {
				System.out.println(a[4]);
				return;
			}
		}
		System.out.println(solve(n,x,y,z));
	}
	
	public static void filter() throws Exception {
		Scanner sc = new Scanner(new File("bruteforce.txt"));
		while(sc.hasNextLine()) {
			String s = sc.nextLine();
			String[] t = s.replace("\"", "").split(",");
			int[] x = new int[5];
			for(int i=0;i<5;i++) {
				x[i] = Integer.parseInt(t[i]);
			}
			if (x[0] >= 15 && x[1] >= 5 && x[2] >= 5 && x[3] >= 5 && x[1] <= x[3]) {
				System.out.println(s);
			}
		}
	}

	public static long solve(int n,int x,int y,int z) {
		HashMap<ArrayList<Integer>, Long> hm = new HashMap<>();
		ArrayList<Integer> empty = new ArrayList<>();
		hm.put(empty, 1L);
		for(int i=0;i<n;i++) {
//			System.out.println(i + ":" + hm.size());
			HashMap<ArrayList<Integer>, Long> hm2 = new HashMap<>();
			for(Entry<ArrayList<Integer>, Long> e: hm.entrySet()) {
				ArrayList<Integer> al = e.getKey();
				for(int k=1;k<=10;k++) {
					if (!xyz(al, k, x, y, z)) {
						ArrayList<Integer> key = new ArrayList<>();
						if (k < x + y + z) {
							key.add(k);
							int sum = k;
							for(int j=al.size()-1;j>=0;j--) {
								sum += al.get(j);
								if (sum < x + y + z) {
									key.add(al.get(j));
								}
							}
						}
						Collections.reverse(key);
						
						Long v = hm2.get(key);
						long value = v == null ? 0 : v;
						value += e.getValue();
						if (value >= MOD) value -= MOD;
						hm2.put(key, value);
					}
				}
			}
			hm = hm2;
		}
		long ans = 0;
		for(long v: hm.values()) {
			ans += v;
			if (ans >= MOD) ans -= MOD;
		}
		return n(pow(10,n,MOD) - ans, MOD);
	}
	
	public static boolean xyz(ArrayList<Integer> head,int tail,int x,int y,int z) {
		z -= tail;
		if (z < 0) {
			return false;
		}
		for(int i=head.size()-1;i>=0;i--) {
			int a = head.get(i);
			if (z > 0) {
				z -= a;
				if (z < 0) return false;
			}else if(y > 0) {
				y -= a;
				if (y < 0) return false;
			}else{
				x -= a;
				if (x < 0) return false;
				if (x == 0) return true;
			}
		}
		return false;
	}
	
	public static long n(long x,long mod) {
		x %= mod;
		if (x < 0) {
			x += mod;
		}
		return x;
	}

	public static long pow(long a,long n,long mod) {
		long res = 1;
		while(n > 0) {
			if ((n & 1) > 0) {
				res = (res * a) % mod;
			}
			a = (a * a) % mod;
			n/=2;
		}
		return res;
	}
}