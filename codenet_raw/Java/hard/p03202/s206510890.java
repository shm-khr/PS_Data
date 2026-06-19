import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        a = ZahyouAssyuku(a);
        boolean flag = false;
        int k = 0;
        while(!flag){
            k++;
            int[] x = new int[n];
            Arrays.fill(x, 0);
            boolean flag2 = false;
            for(int i = 1; i < n; i++){
                if(a[i-1] >= a[i]){
                    int j = a[i];
                    while(j >= 0){
                        if(x[j] != k-1){
                            x[j]++;
                            flag2 = true;
                            break;
                        }
                        else
                            x[j] = 0;
                        j--;
                    }
                    Arrays.fill(x, a[i] + 1, n-1, 0);
                    if(!flag2)
                        break;
                }
            }
            if(flag2)
                flag = true;
        }
        System.out.println(k);
    }
    public static int[] ZahyouAssyuku(int[] a)
    {
        TreeSet<Integer> set = new TreeSet<>();
        for(int i = 0; i < a.length; i++){
            set.add(a[i]);
        }
        Integer[] x = set.toArray(new Integer[set.size()]);
        for(int i = 0; i < a.length; i++){
           a[i] = Arrays.binarySearch(x, a[i]);
        }
        return a;
    }
}