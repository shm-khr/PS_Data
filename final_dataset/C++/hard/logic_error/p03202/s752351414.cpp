#include <bits/stdc++.h>
using namespace std;

bool f(long kind, long n, const vector<long>& a){
    map<long,long> c;
    for(long i=0; i<n-1; i++){
        if(a[i]>=a[i+1]){
            auto it = c.upper_bound(a[i+1]);
            c.erase(it, c.end());
            long j = a[i+1]-1;
            c[j]++;
            while(c[j]>=kind){
                if(j<=0){
                    return false;
                }
                c[j] -= kind;
                c[j-1]++;
                j--;
            }
        }
    }
    return true;
}

int main(void){
    long n;
    cin >> n;
    vector<long> a(n);
    long imax = 0;
    for(long i=0; i<n; i++){
        cin >> a[i];
        imax = max(imax, a[i]);
    }
    long left=0, right=400000;
    for(;;){
        const long mid = (left+right)/2;
        if(right-left<=1){
            if(f(right, n, a)){
                cout << right << endl;
            }else{
                cout << left << endl;
            }
            return 0;
        }
        bool b = f(mid, n, a);
        //printf("[%ld, %ld] %ld %s\n", left, right, mid, b ? "true" : "false");
        if(b){
            right=mid;
        }else{
            left=mid;
        }
    }
}
