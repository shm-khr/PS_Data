#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
    int n, k, t;
    int min = 1;
    int cnt = 0;
    int index = 0;
    cin >> n >> k;
    k;
    vector<int> vec;
    for (int i = 0; i < n; i++) cin >> t;
    for (int i = 0; i < n; i++) {
      cnt++;
      if(n >= k + (k - 1) * (cnt - 1)) break;
    }
    cout << cnt << endl;
 }