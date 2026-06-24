#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k ;
    cin >>n>>k ;
    int l =n/k;
    int m =(2*n/k )-l ;
    long long int x= l*l*l;
    long long int y= m*m*m ;
  if(k/2==0)
  cout << x+y << endl;
  else
  cout <<  x<< endl;
}