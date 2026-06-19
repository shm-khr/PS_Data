#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for(int i = 0; i<(int)(n); i++)
ll int n,m;
ll int x[1001],y[1001],z[1001];
int main(){
    int n;
    int ans = 0;
    cin >> n;
    REP(i,n){
    	int a;
    	cin >> a;
    	while(1){
    		if(a%2==0) break;
    		a/=2;
    		ans++;
    	}
    }
    cout << ans << endl;

}