import java.util.*;

class Main {
  static final int MAX = 10000;
  static int[] rank = new int[MAX];
  static int[] par = new int[MAX];
  static int[] weight = new int[MAX];
  static ArrayList<Integer> ansArr = new ArrayList<Integer>();

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int q = sc.nextInt();

    for(int i = 0 ; i < n ; i++) {
      rank[i] = 0;
      weight[i] = 0;
      par[i] = i;
    }

    int com, x, y, z;
    for(int i = 0 ; i < q ; i++) {
      com = sc.nextInt();
      if(com == 0) {
        x = sc.nextInt();
        y = sc.nextInt();
        z = sc.nextInt();
        realte(x, y, z);
      } else {
        //System.out.println("diff : ");
        x = sc.nextInt();
        y = sc.nextInt();
        diff(x, y);
      }
    }

    // 答え出力
    for(Integer ans: ansArr) {
      if(ans < 0) {
        System.out.println("?");
      } else System.out.println(ans);
    }
  }

  static int find(int x) {
    if(x == par[x]) return x;
    else return par[x] = find(par[x]);
  }

  static int weight(int x) {
    find(x);
    return weight[x];
  }

  static void realte(int x, int y, int z) {
    z += weight(x);
    z -= weight(y);
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) {
      int swap = x;
      x = y;
      y = swap;
      z = -z;
    }
    if(rank[x] == rank[y]) {
      ++rank[x];
    }
    par[y] = x;
    weight[y] = z;
  }

  static void diff(int x, int y) {
    ansArr.add(weight(y) - weight(x));
  }
}

