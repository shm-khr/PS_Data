

import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		int N=sc.nextInt();
		int K=sc.nextInt();
		int ichikan=0;
		int kaisu=1;
		int[] waku=new int[N];
		for(int i=0; i<N; i++) {
			waku[i]=sc.nextInt();
			if(waku[i]==0) {
				ichikan=i;
			}
		}
		kaisu=N/(K-1);
		if(N==K) {
			kaisu=1;
		}
		if(N%(K-1)!=0 && N!=K) {
			kaisu++;
		}
		System.out.println(kaisu);

		//そもそもこの問題(K+1)番目以降に1があると、少なくとも1番目の数字が1にならないので、実際に計算しなくても分かる、
	}
}