#include <iostream>
#include <vector>
#include <climits>

#define rep(i, c) for(int i = 0; i < (int)c; i++)

using namespace std;

int main(void){
    int A, B, M;

    cin >> A >> B >> M;

    int a[A], b[B];
    int x[M], y[M], z[M];

    rep(i, A){
        cin >> a[i];
    }
    rep(i, B){
        cin >> b[i];
    }

    rep(i, M){
        cin >> x[i] >> y[i] >> z[i];
    }

    int min = INT_MAX;
    int sum, dis;

    rep(i, A){
        rep(j, B){
            sum = a[i] + b[j];
            dis = sum;
            rep(k, M){
                if(i+1 == x[k] && j+1 == y[k] && sum-z[k] < dis){
                    dis = sum - z[k];
                }
            }

            if(min > dis){
                min = dis;
            }
        }
    }

    cout << min << endl;

    return 0;
}