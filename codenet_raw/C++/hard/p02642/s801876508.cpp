#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    int answer=0;
    vector<ll>a(n);
    set<int>st;
    bool flag;
    REP(i,n){
        cin >> a[i];
    }
    SORT(a);
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    REP(i,n){
        flag = true;
        if(a[i]==1){
            if(a[1]!=1)
            cout << 1 <<endl;
            else{
                cout << 0 << endl;
            }
            return 0;
        }
        FOR(j,2,(int)sqrt(a[i])+2){
            if(a[i]%j==0 and (st.find(j)!=st.end()or st.find(a[i]/j)!=st.end())){
                flag = false;
                //cout << a[i] << endl;
            }else{
                if(i!=n-1 and a[i]==a[i+1] ){
                    flag=false;
                }
                if(i==n-1 and a[i]==a[i-1]){
                    flag = false;
                }
            }
        }
        if(flag){
            answer++;
            //cout << i << " " <<a[i] << endl;
        }
        st.insert(a[i]);
    }

    cout << answer << endl;
    return 0;
    return 0;
}