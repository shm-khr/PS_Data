#include<iostream>
#define SIZE 1000

using namespace std;

int main(void) {
	
	int n,c,v;
	int G[SIZE][SIZE];
	int A[SIZE][SIZE];

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> v;
		cin >> c;
		for (int j = 0; j < c; j++) {
			cin >> G[i][j];
			int tmp = G[i][j];
			if (tmp > 0) {
				A[i][tmp - 1] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

}

