#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main(){
    int a,b,c,k;
    bool flag = false;
    cin >> a >> b >> c >> k;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= k-i; j++){
            int A = pow(a,i);
            int B = pow(b,j);
            int C = pow(c,k-i-j);
            if (A < B && B < C) flag = true;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}