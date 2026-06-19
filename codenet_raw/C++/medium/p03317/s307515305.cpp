#include <bits/stdc++.h>
using namespace std;
int main () {
int ans = 0;
int n,k;
int a[100000];
cin >> n >> k;
for(int i =0;i<n;i++){
cin >> a[i];
}
int min = 100000;
int argmin = 0;
for(int i=0;i < n;i++){
if(a[i] <= min){
min = a[i];
argmin = i;
}
}
int l = argmin;
int r = n - argmin;
//while(l > 0){
//l -= k-1;
//ans++;
//}
//while(r > 0){
//r -= k-1;
//ans++;
//}
ans += l / (k-1);
ans += r / (k-1);
//if(l % (k-1) != 0) ans++;
//if(r % (k-1) != 0) ans++;
if(k==2)ans--;
if(n==k)ans = 1;
if(k > r && k > l){
ans = n /k;
if(n%k!=0)ans++;
}
cout << ans << endl;
return 0;
}