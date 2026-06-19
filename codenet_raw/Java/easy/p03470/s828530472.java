package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner s = new Scanner(System.in);
        int N = Integer.parseInt(s.next());
        int[] a = new int[100];
        for(int i=0;i<100;i++) a[i] = 0;
        for (int i = 0; i < N; i++) a[Integer.parseInt(s.next()) - 1] += 1;
        int count = 0;
        for (int i = 0; i < 100; i++) {
            if (a[i] != 0){
                count ++;
            }
        }
        System.out.println(count);
    }
}
