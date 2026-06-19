#include <iostream>
#include <algorithm>
using namespace std;

int main(){

  int n,a[101],b[101],max=0;
  int ruiseki_a[101],ruiseki_b[101];

  a[0] = 0; b[0] = 0;
  cin >> n;
  for(int i =1; i<=n ; i++) {cin >> a[i]; ruiseki_a[i]=a[i]+ruiseki_a[i-1];}
  for(int i =1; i<=n ; i++) {cin >> b[i];  ruiseki_b[i] = b[i] + ruiseki_b[i-1];}

  for(int i =1; i<=n; i++){
    for(int j=n; j>=1; j--){
      max =max(ruiseki_a[i] + ruiseki_b[j],max);
    }
  }

  cout << max;
  return 0;
}
