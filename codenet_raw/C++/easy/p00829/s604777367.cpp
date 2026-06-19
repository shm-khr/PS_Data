#include<bits/stdc++.h>
using namespace std;

long long data[9];
int main(){
	int S;
	cin >> S;
	while(S--){
		for(int i = 0; i < 9; i++){
			string str;
			cin >> str;
			data[i] = stoll(str, nullptr, 16);
		}
		int K = 0;
		int prev = 0;
		for(int i = 0; i <= 32; i++){
			int sum = prev;
			for(int j = 0; j < 8; j++){
				sum += (data[j] >> i) & 1;
			}
			//cout << "sum" << sum << endl;
			if((sum & 1) == ((data[8] >> i) & 1)){
				prev = sum / 2;
			}else{
				K |= (1 << i);
				sum = prev;
				for(int j = 0; j < 8; j++){
					sum += (~(data[j] >> i)) & 1;
				}
				
				prev = sum/2;
			}
		}
		printf("%x\n", K);
	}
}