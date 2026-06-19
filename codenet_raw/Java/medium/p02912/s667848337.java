import java.util.Scanner;

class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

	int N, M;
	N = sc.nextInt();
	M = sc.nextInt();
	int A[] = new int[N];
	for (int i = 0; i < N; i++)
	    A[i] = sc.nextInt();

	int max = 0;
	for (int i = 0; i < M; i++) {
	    for (int j = 1; j < N; j++) {
		if (A[max] < A[j])
		    max = j;
	    }

	    A[max] /= 2;
	}

	long ans = 0;
	for (int i = 0; i < N; i++)
	    ans += A[i];

	System.out.println(ans);
    }
}