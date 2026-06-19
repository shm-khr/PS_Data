#include<bits/stdc++.h>
using namespace std;

int maxEven(int n, vector<int> a){
    int index = -1;
    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            if(tmp < a[i]){
                index = i;
                tmp = a[i];
            }
        }
    }
    return index;
}

int main(){
    int N;
    int c = 0;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int i = maxEven(N, a);
    while(i != -1){
        a[i] = a[i] / 2;
        c++;
        i = maxEven(N,a);
    }
    cout << c << endl;
    return 0;
}