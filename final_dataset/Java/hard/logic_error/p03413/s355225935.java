import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;

class Main{

    static long getmax(List<Long> array){
        long res = Long.MIN_VALUE;
        long min = 0;
        maxIndex=0;
        minIndex=-1;
        for(int i=0;i<array.size();++i){
            long n = array.get(i);
            if(n-min > res){
                res = n-min;
                maxIndex=i;
            }
            if(n < min){
                min=n;
                minIndex=i;
            }
        }
        return res;
    }
    static int maxIndex=0;
    static int minIndex=0;

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long[] a = new long[N];
        for(int i=0;i<N;++i)a[i]=scan.nextLong();
        List<Long> evenSum = new ArrayList<>();
        List<Long> oddSum = new ArrayList<>();
        for(int i=0;i<N;++i){
            if(i==0)evenSum.add(a[i]);
            else if(i==1)oddSum.add(a[i]);
            else if(i%2==0)evenSum.add(evenSum.get(evenSum.size()-1)+a[i]);
            else oddSum.add(oddSum.get(oddSum.size()-1)+a[i]);
        }
        long ans = 0;
        if(getmax(evenSum) < getmax(oddSum)){
            ans = getmax(oddSum);
            maxIndex = maxIndex*2+1;
            minIndex = Math.min(minIndex*2+3, maxIndex);
        }
        else{
             ans = getmax(evenSum);
             maxIndex=maxIndex*2;
             minIndex=Math.min(minIndex*2+2 , maxIndex);
        }
        System.out.println(ans);
        List<Integer> list = new ArrayList<>();
        for(int i=N-1;i>maxIndex;--i)list.add(i+1);
        for(int i=0;i<minIndex;++i)list.add(1);
        for(int i=0;i<(maxIndex-minIndex)/2;++i)list.add(2);
        System.out.println(list.size());
        for(int i : list)System.out.println(i);

    }
}