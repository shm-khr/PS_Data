#include <bits/stdc++.h>
using namespace std;

int main() {
string a;
cin>>a;
int n;
  for(int i=0;i<a.size();i++){
if(a.at(i)='o'){
n++;
}
}
if(n+15-a.size()>8){
  cout << "yes" << endl;
}
else{
  cout << "no" << endl;
}
}