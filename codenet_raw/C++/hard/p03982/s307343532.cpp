#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;

int main() {
	int N;
	cin >> N;
	vector<LL> A, sumA;
	vector<LL> B, sumB;
	sumA.push_back(0);
	sumB.push_back(0);
	for(int i=0; i<N; i++) {
		LL p;
		cin >> p;
		A.push_back(p);
		sumA.push_back(sumA.back() + p);
	}
	for(int i=0; i<N; i++) {
		LL p;
		cin >> p;
		B.push_back(p);
		sumB.push_back(sumB.back() + p);
		B[i] -= A[i];
	}
	/*
	LL ans = 0;
	for(int i=0; i<=N; i++) {
		LL tmp= 0;
		tmp = max(tmp, sumB[i] - sumA[i]);
		tmp = max(tmp, (sumB.back() - sumB[i]) - (sumA.back() - sumA[i]));
		ans += tmp;
	}
	cout << ans << endl;
	*/
	for(int i=0 ;i<N ; i++)
		B.push_back(0);
	stack<PII> data;
	data.push(PII(-1000000000,-5000000));
	int nextPos = 0;
	LL ans = 0;
	for(int i=0; i<N; i++) {
		nextPos = max(nextPos, i);
		if(B[i] < 0) {
			data.push(PII(i, B[i]));
			continue;
		}
		while(B[i] > 0) {
			
			PII cur = data.top();
			int diff = i - cur.first;
			
			while(nextPos < i + diff ) {
				if(B[nextPos] < 0) {
					LL move = min(-B[nextPos], B[i]);
					B[i] -= move;
					B[nextPos] += move;
					ans += (LL)move * (LL)(nextPos - i);
//					cout <<i << " " << nextPos << " s"<< move << endl;
				}
				if(B[i] == 0) break; 
				nextPos++;
			}
			
			{
				data.pop();
				LL move = min( - cur.second, B[i]);
				B[i] -= move;
				cur.second += move;
				assert(cur.second <= 0);
				if(cur.second < 0) {
					data.push(cur);
				}
				ans += move * (LL) diff;
			}
			
			
		}
		
	}
	cout  << ans << endl;
	
	
	return 0;
}

