#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

const int MAX_N = 10000;

map<int,int> zip;
int unzip[MAX_N];

int compress(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}

struct BIT{
    int bit[MAX_N + 1];
    int n;

    BIT(const int n): n(n){
        for (int i=0;i<MAX_N;i++) bit[i] = 0;
    }

    int sum(int i){
        int S = 0;
        while(i > 0){
            S += bit[i];
            i -= i & -i;
        }
        return S;
    }

    void add(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }

};

int main(){
    int MAX_N = 10000;
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;i++){
        cin >> a[i];
    }

    int tmpMax = 0;
    vector<int> preMax(N);
    for(int i=0;i<N;i++){
        preMax[i] = max(0, a[i] - tmpMax);
        tmpMax = max(tmpMax, a[i]);
    }

    vector<int> aTmp;
    vector<int> backSum(N);
    aTmp = a;
    int compSize = compress(aTmp);
    BIT bit(compSize);
    for (int i=0;i<N;i++){
        bit.add(zip[a[i]] + 1, 1);
    }
    for (int i=0;i<N;i++){
        backSum[i] = N - i - bit.sum(zip[a[i]]);
        bit.add(zip[a[i]] + 1, -1);
    }

    for (int i=0;i<N;i++){
        cout << preMax[i] * backSum[i] << endl;
    }
    return 0;
}