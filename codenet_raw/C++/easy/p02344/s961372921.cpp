#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

long long int INF = 1e18;
long long int MOD = 1000000007;
using namespace std;

typedef pair<long long int, long long int> P;

#define MAX_N 200000

using namespace std;

int par[MAX_N];
int rnk[MAX_N];
long long int diff[MAX_N];

// 初期化
void init(int n){
	for(int i = 0; i < n; i++){
		par[i] = i;
		rnk[i] = 0;
		diff[i] = 0;
	}
}

// x の親を返す
P find(int x){
	P p;
	if(par[x] == x){
		p.first = x;
		p.second = 0;
		return p;
	}
	p = find(par[x]);
	diff[x] += p.second;
	p.second = diff[x];
	par[x] = p.first;
	return p;
}

// x と y を併合する
void unite(int x, int y, int z){
	P px = find(x);
	P py = find(y);
	int x_par = px.first;
	int y_par = py.first;
	if(x_par == y_par){
		return;
	}
	
	if(rnk[x_par] < rnk[y_par]){
		par[x_par] = y_par;
		diff[x] = diff[y] + z;
	}else{
		par[y_par] = x_par;
		diff[y] = diff[x] - z;
		if(rnk[x_par] == rnk[y_par]){
			rnk[x_par]++;
		}
	}
}

// x, y が同じグループか判定
bool same(int x, int y){
	P px = find(x);
	P py = find(y);
	int x_par = px.first;
	int y_par = py.first;
	return (x_par == y_par);
}

int main(){
	
	int n, q;
	cin >> n >> q;
	
	init(n);
	
	for(int i = 0; i < q; i++){
		int num, a, b, c;
		cin >> num >> a >> b;
		if(num == 0){
			cin >> c;
			unite(a, b, c);
		}else{
			if(!same(a, b)){
				cout << "?" << endl;
			}else{
				cout << abs(diff[a] - diff[b]) << endl;
			}
		}
		/*
		for(int j = 0; j < n; j++){
			cout << par[j] << " ";
		}
		cout << endl;
		for(int j = 0; j < n; j++){
			cout << diff[j] << " ";
		}
		cout << endl;
		*/
	}
	
	return 0;
}
