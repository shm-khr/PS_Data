#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//int i,n;
//#define REP(i,n) for(int i = 0; i < (int n); i++)
typedef long long ll;



int main(void){

	int N;
	int i,tmp;
	int A[1000];

	tmp = 0;
	cin >> N ;

	for(i = 0; i < N; i++){
		cin >> A[i];

		if(A[i] % 2 == 0){
			if(A[i] % 3 == 0 || A[i] % 5 == 0 ){
				tmp = A[i];
			} else {
				tmp = 0;
				break ;
			}
		}
	}

	if(tmp == 0) cout << "DENIED";
	if(tmp > 0) cout << "APPROVED";

}
