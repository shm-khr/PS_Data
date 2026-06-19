#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <list>
#include <string>

typedef char                SINT8;
typedef unsigned char       UINT8;
typedef short               SINT16;
typedef unsigned short      UINT16;
typedef int                 SINT32;
typedef unsigned int        UINT32;
typedef long long           SINT64;
typedef unsigned long long  UINT64;
typedef double              DOUBLE;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)
#define rrep(i,a,b) for(int (i)=int(a);(i)>=int(b);(i)--)

#define put(a) cout << (a) << endl
#define puts(a) cout << (a) << " "
#define pute(a) cout << endl


#define INF 1000000001
#define MOD 1000000007
#define INF64 1000000000000000001

#define F first
#define S second

#define Pii  pair<SINT32,SINT32>
#define Pll  pair<SINT64,SINT64>
#define Piii pair<SINT32,pair<SINT32,SINT32>>
#define Plll pair<SINT64,pair<SINT64,SINT64>>

#define Vll(a,b,c)    vector<vector<SINT64>> (a)((b),vector<SINT64>((c))
#define Vlll(a,b,c,d) vector<vector<vector<SINT64>>> (a)((b),vector<vector<SINT64>>((c),vector<SINT64>((d)))


using namespace std;

int main() {

	SINT64 H,W,N;	cin >> H >> W >> N;

	vector<SINT64> ans(10,0);

	vector<Pll> data;
	
	rep(i,0,N) {
		SINT64 h,w;
		Pll buf;
		cin >> h >> w;
		h--;w--;
		rep(i,0,3) {
			rep(j,0,3) {
				if (((h-i) >= 0) && ((w-j) >= 0) && ((h-i) < H-2) && ((w-j) < W-2)) {
					buf.F = h-i;
					buf.S = w-j;
					data.emplace_back(buf);
				}
			}
		}	
	}
	sort(data.begin(),data.end());

	SINT64 cnt = 1;

	rep(i,1,data.size()) {
		if ((data[i].F == data[i-1].F) && (data[i].S == data[i-1].S)) {
			cnt++;
		} else {
			ans[cnt]++;
			cnt = 1;
		}
	}
	if (cnt >= 2) {
		ans[cnt]++;
	}

	ans[0] = (H-2)*(W-2);
	rep(i,1,10) {
		ans[0] -= ans[i];
	}
	rep(i,0,10) {
		put(ans[i]);
	}
	return 0;
}


//	vector<vector<SINT64>> data(N,vector<SINT32>(3));										//2次元配列
//	vector<vector<vector<SINT64>>> data(N,vector<vector<SINT64>>(3,vector<SINT64>(3)));		//3次元配列

//	Vll(data,N,N);		//2次元配列
//	Vlll(data,N,N,N);	//3次元配列

//	sort(data.begin(),data.end());
//	sort(data.begin(),data.end(),std::greater<SINT64>());
//	__gcd(A,B);

//	data.emplace_back(BUF);			//後ろに追加

//  data.erase(std::unique(data.begin(), data.end()), data.end());	//ソート後に使用 同じ値を消す

//	data.insert(data.begin() + X, 0);	//X番目の要素に0を挿入


//	隣接リスト
//	vector<vector<SINT64>> data(N);
//	data[ A ].emplace_back( B );


/*
	vector<Pll> data(N);
	rep(i,0,N) {
		cin >> data[i].F;
		cin >> data[i].S;
	}
	sort(data.begin(),data.end());
*/

/*
	vector<Plll> data(N);
	rep(i,0,N) {
		cin >> data[i].F;
		cin >> data[i].S.F;
		cin >> data[i].S.S;
	}
	sort(data.begin(),data.end());
*/


// posi = lower_bound(data.begin(),data.end(), X) - data.begin();				// X以上を探す
// posi = lower_bound(data.begin(),data.end(),make_pair(X,0)) - data.begin();	//pair


/* 文字列回転
	string N;
	cin >> N;
	N = N[N.length()-1] + N.substr(0,N.length()-1);


	s = to_string(i);	//ストリング変換
*/
/* 文字列合成
	string N,M;
	cin >> N >> M;
	SINT64 ans = 0;
	ans = stoi(N+M);
*/

/*
//ワーシャルフロイド
vector<vector<SINT32>> dist(N,vector<SINT32>(N));
rep(i,0,N) {
	rep(j,0,N) {
		if (i != j) {
			dist[i][j] = INF;
		}
	}
}
rep(k,0,N) {
	rep(i,0,N) {
		rep(j,0,N) {
			dist[i][j] = MIN(dist[i][j], dist[i][k]+dist[k][j]);
		}
	}
}
*/

/*  優先度付きキュー
	priority_queue<SINT64, vector<SINT64>, greater<SINT64>> data;	//小さいほうから取り出せる
	priority_queue<SINT64, vector<SINT64>> data;					//大きいほうから取り出せる

	data.push(X);	//X を挿入
	data.top();		//先頭データ読み
	data.pop();		//先頭データ削除
*/





/* SET コンテナ
	set<SINT64> data;
	data.insert(X);				//X を挿入
	data.erase(data.begin());	//先頭を削除
	data.erase(--data.end());	//末尾を削除
	*data.begin();				//先頭要素にアクセス
	*data.rbegin();				//末尾要素にアクセス

	//全表示
    set<SINT64>::iterator it; //イテレータを用意
    for(it = data.begin(); it != data.end(); it++) {
        cout << *it << " ";
    }
	cout << endl;

	//N番目を一部表示
	set<SINT64>::iterator it; //  イテレータを用意
	it = data.begin();
	rep (i,0,N) {
		it++;
	}
	cout << *it << endl;
*/

/* map
	map<string,SINT32> mp;
	SINT32 N = 0;
	SINT32 mx = 0;

	cin >> N;
	for (SINT32 i = 0; i < N; i++) {
		string s;
		cin >> s;
		mp[s]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++) {
		mx=max(mx,it->second);
	}
*/

/*
	//順列全表示
	//sortしてからでないと全列挙にならない
	sort(data.begin(),data.end());
	do {
		cout << buf << endl;
		rep(i,0,R) {
			cout << data[i] << " ";
		}
		cout << endl;

    } while (next_permutation(data.begin(),data.end()));
*/

//  桁指定表示
//  ans = ans * M_PI;
//	cout << setprecision(15) << ans << endl;