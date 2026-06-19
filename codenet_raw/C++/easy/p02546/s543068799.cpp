#include <bits/stdc++.h>
using namespace std;
 
int main(){
   string s;
  cin>>s;
  int l = s.size();
  if(s[l-1] == 's'){
         s[l-1] = 'e';
         s[l] = 's'; 
  }
  else s[l] = 's';
  cout<<s<<endl;
}