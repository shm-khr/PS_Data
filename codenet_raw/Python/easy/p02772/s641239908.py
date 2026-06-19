#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <bitset>

using namespace std;

//#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

typedef long long ll;
//typedef pair<ll, ll> P;

//static const ll MOD = 1000000007;
//static const ll INF = 100000000;

int main() {
    // input
    ll N;
    vector<ll> A;
    cin >> N;
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A.emplace_back(a);
    }

    // process
    for (ll i = 0; i < N; i++) {
        if ((A[i] % 2) == 0) {
            if ((A[i] % 3) != 0) {
                if ((A[i] % 5) != 0) {
                    cout << "DENIED";
                    return 0;
                }
            }
        }
    }

    cout << "APPROVED";
    return 0;
}