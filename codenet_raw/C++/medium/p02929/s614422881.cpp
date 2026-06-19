#include <bits/stdc++.h>

using namespace std;
long long n;
string s;
int main()
{
    cin>>n;
    n*=2;
    cin>>s;
    int b = 0, w = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W')w++;
        else b++;
    }
    if(n % 2 == 1){
        cout<<0;
        return 0;
    }
    n /= 2;
    long long z[n+1];
    z[1] = 1;
    for(long long i = 2; i <= n; i++){
        z[i] = (i*z[i-1])%(1000000007);
    }
    long long ans = ( (z[n]*n)%(1000000007)   *   (n-1)) % (1000000007);

    cout<<ans;
    return 0;
}
