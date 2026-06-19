#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
 int n,sum;
 double a,m;
 while(1){
  cin >> n;
  int s[n]={};
  if(n==0) break;

  sum=0;
  for(int i=0;i<n;++i){
   cin >> s[i];
   sum+=s[i];
  }
  m=sum/n;

  a=0;
  for(int i=0;i<n;++i){
   a+=pow(s[i]-m,2);
  }
  cout << fixed << setprecision(8) << fabs(sqrt(a/n)) << endl;
 }
 return 0;
}