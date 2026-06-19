import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.lang.ArrayIndexOutOfBoundsException;

/**
 * @author yoshikyoto
 */
class Main extends MyUtil{
	public static ArrayList<ArrayList<Integer>> g;
	public static void main(String[] args) throws Exception{
		
		while(true){
			int n = readInt();
			if(n == 0) return;
			
			int[][] islands = new int[n][2];
			for(int i = 0; i < n; i++) islands[i] = readIntMap();
			Arrays.sort(islands, new ArrayComparator());
			
			int sum = 0;
			boolean flag = true;
			for(int i = 0; i < n; i++){
				sum += islands[i][0];
				if(sum > islands[i][1]){
					flag = false;
					break;
				}
			}
			p(flag ? "Yes" : "No");
		}
	}
}

class ArrayComparator implements Comparator<int[]>{
	public int compare(int[] a, int[] b){
		for(int i = a.length-1; i >= 0; i--){
			if(a[i] == b[i]) continue;
			return a[i] - b[i];
		}
		return 0;
	}
}

class ArrayListData extends ArrayList<Data>{
	void sort(){
		Collections.sort(this, new DataComparator());
	}
}

class Data extends MyUtil{
	int takara, hashi;
	Data(String str){
		String strs[] = str.split(" ");
		takara = parseInt(strs[0]);
		hashi = parseInt(strs[1]);
	}
}


class DataComparator implements Comparator<Data>{
    //比較メソッド（データクラスを比較して-1, 0, 1を返すように記述する）
    public int compare(Data a, Data b) {
        // a > b ? 1 で昇順、a < b ? 1 で降順
        if (a.hashi > b.hashi) {
            return 1;
        } else if (a.hashi < b.hashi) {        	
            return -1;
        } else {
        	return 0;
        }
    }
}

class Regex{
	Pattern p; Matcher m; String str;
	Regex(String regex_str){p = Pattern.compile(regex_str);}
	void setStr(String str){m = p.matcher(str);}
	boolean find(){return m.find();}
	String group(int i){return m.group(i);}
	String group(){return m.group();}
}

/**
 * UnionFindTree Set周りは未実装
 * @author yoshikyoto
 */
class UnionFindTree{
    public int[] parent, rank;
    public int n;
    public Set<Integer> set;
    // 初期化
    UnionFindTree(int _n){
        n = _n;
        for(int i = 0; i < n; i++){
        	parent = new int[n];
        	rank = new int[n];
            parent[i] = i;
            rank[i] = 0;
        }
    }
    // 根を求める
    int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            return parent[x] = find(parent[x]);
        }
    }
    // xとyの集合を結合
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            return;
        }
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    // xとyが同じ集合か
    boolean same(int x, int y){
        return find(x) == find(y);
    }
};


/**
 * 整数を数え上げたりするクラス
 * new Prime(int n) でnまでエラトステネスの篩を実行。
 * @author yoshikyoto
 * @param a[i] iが素数の時true
 * @param count[i] i以下の素数の数
 */
class Prime{
	boolean[] a;
	int[] count;
	Prime(int n){
		a = new boolean[n+1];
		a[0] = false; a[1] = false;
		for(int i = 2; i <= n; i++) a[i] = true;
		// ふるい
		for(int i = 2; i < (n - 3) / 2; i++)
			if(a[i]) for(int j = 2; j * i <= n; j++)
					a[j * i] = false;
		
		// 数え上げ
		count = new int[n+1];
		count[0] = 0;
		for(int i = 1; i <= n; i++){
			int gain = 0;
			if(a[i]) gain = 1;
			count[i] = count[i-1] + gain;
		}
	}
}

class AI extends ArrayList<Integer>{}
class SI extends Stack<Integer>{}

class CountHashMap<E> extends HashMap<E, Integer>{
	ArrayList<E> keyArray = new ArrayList<E>();
	public void add(E key){add(key, 1);}
	public void add(E key, Integer value){
		if(containsKey(key)){value += get(key);
		}else{keyArray.add(key);}
		put(key, value);
	}
}
class HM extends CountHashMap<String>{} 

class Q<E> extends ArrayDeque<E>{
	public void push(E item){add(item);}
	public E pop(){return poll();}
}
class QS extends Q<String>{}
class QI extends Q<Integer>{}

/**
 * MyUtil
 * @author yoshikyoto
 */
class MyUtil extends MyIO{
	public static Random rand = new Random();
	public static long start_time = 0;
	public static void start(){start_time = System.currentTimeMillis();}
	public static void end(){
		if(start_time == 0) return;
		long time = System.currentTimeMillis() - start_time;
		if(DEBUG) p(time + "ms");
	}
	public static int digit(int n){return String.valueOf(n).length();}
	public static String reverse(String s){
		StringBuffer sb = new StringBuffer(s);
		return sb.reverse().toString();
	}
	public static void sort(int[] a){Arrays.sort(a);}
	public static void dsort(int[] a){
		Arrays.sort(a);
		int l = a.length;
		for(int i = 0; i < l/2; i++){
			int tmp = a[i]; a[i] = a[l-1-i]; a[l-1-i] = tmp;
		}
	}
	public static void sleep(int t){try{Thread.sleep(t);}catch(Exception e){}}
	public static int sum(int[] a){int s = 0; for(int i = 0; i < a.length; i++)s+=a[i]; return s;}
	public static int[] cp(int[] a){
		int[] b = new int[a.length];
		for(int i = 0; i < a.length; i++) b[i] = a[i];
		return b;
	}
	public static int randomInt(int min, int max){return min + rand.nextInt(max - min + 1);}
	static boolean inside(int y, int x, int h, int w){return 0 <= y && y <= (h-1) && 0 <= x && x <= (w-1);};
	public static boolean isUpper(char c){return 'A'<=c&&c<='Z';}
	public static boolean isLower(char c){return 'a'<=c&&c<='z';}
	public static char toUpper(char c){
		if(isLower(c)) return (char)(c - 'a' + 'A');
		return c;
	}
	public static char toLower(char c){
		if(isUpper(c)) return (char)(c - 'A' + 'a');
		return c;
	}
}

/**
 * MyIO
 * @author yoshikyoto
 */
class MyIO extends MyMath{
	static Scanner sc = new Scanner(new InputStreamReader(System.in));
	public static char scNextChar(){return sc.next().charAt(0);}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static boolean DEBUG = false;
	public static String line;
	public static void debug(){DEBUG = !DEBUG;};
	public static int[] readIntMap() throws IOException{return parseInt(readLine().split(" "));}
	public static int[] readNoDistIntMap() throws IOException{
		String[] strs = readLine().split("");
		int l = strs.length;
		int[] ret = new int[l-1];
		for(int i = 1; i < l; i++)
			ret[i-1] = parseInt(strs[i]);
		return ret;
	}
	public static boolean readToLine() throws IOException{return (line = br.readLine()) != null;}
	public static String readLine() throws IOException{return br.readLine();}
	public static int readInt() throws IOException{return Integer.parseInt(br.readLine());}
	public static void p(Object o){System.out.println(o.toString());}
	public static void pr(Object o){System.out.print(o.toString());}
	public static void d(Object o){if(DEBUG)System.out.println(o.toString());}
	public static void dr(Object o){if(DEBUG)System.out.print(o.toString());}
	public static void da(Object[] o){if(DEBUG)System.out.println(Arrays.toString(o));}
	public static void da(int[] arr){if(DEBUG)System.out.println(Arrays.toString(arr));}
	public static void da(double[] arr){if(DEBUG)System.out.println(Arrays.toString(arr));}
	public static void da(boolean[] arr){if(DEBUG)System.out.println(Arrays.toString(arr));}
	public static int[] parseInt(String[] arr){
		int[] res = new int[arr.length];
		for(int i = 0; i < arr.length; i++)res[i] = Integer.parseInt(arr[i]);
		return res;
	}
	public static double[] parseDouble(String[] arr){
		double[] res = new double[arr.length];
		for(int i = 0; i < arr.length; i++)res[i] = Double.parseDouble(arr[i]);
		return res;
	}
	public static boolean[] parseBool(String[] arr){
		int[] t = parseInt(arr);
		boolean[] res = new boolean[t.length];
		for(int i = 0; i < t.length; i++){
			if(t[i] == 1){res[i] = true;
			}else{res[i] = false;}
		}
		return res;
	}
	public static int parseInt(Object o){return Integer.parseInt(o.toString());}
	public static PrintWriter getFilePrintWriter(String file) throws IOException{
		FileWriter fw = new FileWriter(file);
		BufferedWriter bw = new BufferedWriter(fw);
		PrintWriter pw = new PrintWriter(bw);
		return pw;
	}
	public static BufferedReader getFileBufferdReader(String file) throws FileNotFoundException{
		FileReader fr = new FileReader(file);
		BufferedReader br = new BufferedReader(fr);
		return br;
	}
}

class MyMath{
	/**
	 * 弧度法の角度を入力してsinの値を返す（Math.sin の入力はラジアン）
	 */
	public static double sin(int r){return Math.sin(Math.toRadians(r));}

	/**
	 * 弧度法の角度を入力してcosの値を返す（Math.sin の入力はラジアン）
	 */
	public static double cos(int r){return Math.cos(Math.toRadians(r));}
	public static int max(int a, int b){return Math.max(a, b);}
	public static int min(int a, int b){return Math.min(a, b);}
	public static boolean isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	    // 並行な場合
	    int m = (x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
	    if(m == 0) return false;
	    // 媒介変数の値が0より大きく1以下なら交差する、これは問題の状況によって変わるかも。
	    double r =(double)((y4-y3)*(x3-x1)-(x4-x3)*(y3-y1))/m;
	    double s =(double)((y2-y1)*(x3-x1)-(x2-x1)*(y3-y1))/m;
	    return (0 < r && r <= 1 && 0 < s && s <= 1);
	}
	public static boolean isParallel(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	    if((x2-x1)*(y4-y3) == (y2-y1)*(x4-x3)) return true;
	    else return false;
	}
	public static double sq(double d){return d*d;}
	public static int sq(int i){return i*i;}
	public static int sqdist(int x1, int y1, int x2, int y2){
		return sq(x1-x2) + sq(y1-y2);}
	public static double sqdist(double x1, double y1, double x2, double y2){
		return sq(x1-x2) + sq(y1-y2);}
	public static double dist(int x1, int y1, int x2, int y2){
		return Math.sqrt(sqdist(x1, y1, x2, y2));}
	public static double dist(double x1, double y1, double x2, double y2){
		return Math.sqrt(sqdist(x1, y1, x2, y2));}
}