#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b));

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);

    int t = (c-a) + (c-b);
    if(!t%2) cout << t/2 << endl;
    else cout << ((t+1)/2) + 1 << endl;

    return 0;
}