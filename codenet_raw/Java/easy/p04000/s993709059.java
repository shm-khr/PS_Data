import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		Map<String, Byte> map = new HashMap<String, Byte>();
		int n = scn.nextInt();
		int n2 = scn.nextInt();
		int m, m2;
		for(int i = scn.nextInt();i>0;i--) {
			m = scn.nextInt();
			m2 = scn.nextInt();
			if(m<=n-2&m2<=n2-2)map.put(m+" "+m2,(byte) (map.getOrDefault(m+" "+m2, (byte) 0)+1));
			if(m>1&m<=n-1&m2<=n2-2) map.put((m-1)+" "+m2,(byte) (map.getOrDefault((m-1)+" "+m2, (byte) 0)+1));
			if(m>2&m2<=n2-2) map.put((m-2)+" "+m2,(byte) (map.getOrDefault((m-2)+" "+m2, (byte) 0)+1));
			if(m2>1&m<=n-2&m2<=n2-1) map.put(m+" "+(m2-1),(byte) (map.getOrDefault(m+" "+(m2-1), (byte) 0)+1));
			if(m2>2&m<=n-2) map.put(m+" "+(m2-2),(byte) (map.getOrDefault(m+" "+(m2-2), (byte)0)+1));
			if(m>1&m2>1&m<=n-1&m2<=n2-1) map.put((m-1)+" "+(m2-1),(byte) (map.getOrDefault((m-1)+" "+(m2-1), (byte)0)+1));
			if(m>2&m2>2) map.put((m-2)+" "+(m2-2),(byte) (map.getOrDefault((m-2)+" "+(m2-2), (byte) 0)+1));
			if(m>1&m2>2&m<=n-1) map.put((m-1)+" "+(m2-2),(byte) (map.getOrDefault((m-1)+" "+(m2-2), (byte) 0)+1));
			if(m>2&m2>1&m2<=n2-1) map.put((m-2)+" "+(m2-1),(byte) (map.getOrDefault((m-2)+" "+(m2-1), (byte) 0)+1));
		}
		long[] cc = new long[9];
		for (Object value : map.values()) {
		    if(value.toString().equals("1"))cc[0]++;
		    if(value.toString().equals("2"))cc[1]++;
		    if(value.toString().equals("3"))cc[2]++;
		    if(value.toString().equals("4"))cc[3]++;
		    if(value.toString().equals("5"))cc[4]++;
		    if(value.toString().equals("6"))cc[5]++;
		    if(value.toString().equals("7"))cc[6]++;
		    if(value.toString().equals("8"))cc[7]++;
		    if(value.toString().equals("9"))cc[8]++;
		}
		System.out.println((long)(n-2)*(n2-2)-cc[0]-cc[1]-cc[2]-cc[3]-cc[4]-cc[5]-cc[6]-cc[7]-cc[8]);
		for(int i = 0;i<9;i++)System.out.println(cc[i]);
		scn.close();
	}
}