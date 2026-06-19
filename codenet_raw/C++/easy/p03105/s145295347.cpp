#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<utility> //pair
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main() {
	//入力;
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= b * c) cout << c << endl;
	else cout << a / b << endl;


	//小数点以下の桁数表示;
	//cout << fixed << setprecision(15);

	return 0;
}