import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        l:while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int p = sc.nextInt();
            if (n + m + p == 0)
                break;
            int[][][] f = new int[n][n][n];
            for (int i = 0; i < f.length; i++) {
                for (int j = 0; j < f.length; j++) {
                    for (int j2 = 0; j2 < f.length; j2++) {
                        f[i][j][j2] = -1;
                    }
                }
            }
            String winner = "Draw";
            int turn = -1;
            for (int i = 0; i < p; i++) {
                int x = sc.nextInt() - 1;
                int y = sc.nextInt() - 1;
                if(turn!=-1)continue;
                int z = 0;
                while (z < n && f[x][y][z] != -1) {
                    z++;
                }
                f[x][y][z] = i % 2;
                int b, w;
                b = seq(f, m, 0);
                w = seq(f, m, 1);
                if(b+w==0)continue;
                if(b > w) {
                    winner = "Black";
                    turn = i+1;
                } else {
                    winner = "White";
                    turn = i+1;
                }
            }
            if(turn==-1)
                System.out.println("Draw");
            else{
                System.out.println(winner+" "+turn);
            }
        }
    }

    static int seq(int[][][] f, int m, int color) {
        int res = 0;
        int[] vx = { 1, 0, 0, 1, 1, 0, 1 };
        int[] vy = { 0, 1, 0, 0, 1, 1, 1 };
        int[] vz = { 0, 0, 1, 1, 0, 1, 1 };
        for (int i = 0; i < f.length; i++) {
            for (int j = 0; j < f.length; j++) {
                for (int k = 0; k < f.length; k++) {
                    for (int k2 = 0; k2 < vx.length*2; k2++) {
                        int x = i;
                        int y = j;
                        int z = k;
                        boolean flg = true;
                        for (int l = 0; l < m; l++) {
                            try {
                                f[x][y][z] = f[x][y][z]*1;
                            } catch (Exception e) {
                                flg = false;
                                break;
                            }
                            if (f[x][y][z] != color)
                                flg = false;
                            if(k2<vx.length){
                                x += vx[k2];
                                y += vy[k2];
                                z += vz[k2];
                            } else {
                                x -= vx[k2-vx.length];
                                y -= vy[k2-vx.length];
                                z -= vz[k2-vx.length];
                            }
                        }
                        if (flg){
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
}