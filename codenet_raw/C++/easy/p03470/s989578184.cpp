#include<iostream>
using namespace std;

int change(int *array, int n){
	int tmp = array[n];
	array[n] = array[n - 1];
	array[n - 1] = tmp;
}
int main(){
	int N;
	cin >> N;
	int d[N];
	for(int i = 0; i < N; i++) cin >> d[i];
	
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(d[j] >=d[j - 1]) change(d, j);
		}
	}
	
	int n = 0;
	for(int i = 1; i < N; i++){
		if(d[i - 1] == d[i]) n++;
	}
	N -= n;
	cout << N - 1 << endl;
}
