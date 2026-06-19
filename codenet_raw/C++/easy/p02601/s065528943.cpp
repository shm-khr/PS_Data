#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,k;
  cin>>r>>g>>b>>k;
  string s = "No";
  for(int i=0; i<k+1; i++){
    if(b>g && g>r){
    	s="Yes";
      	break;
    }
  	else if(b>r && r>g){
    	g*=2;
    }
    else if(g>b && b>r){
    	b*=2;
    }
    else if(r>b && b>g){
    	b*=2;
    }
    else if(r>g && g>b){
    	b*=2;
    }
    else if(g>r && r>b){
    	b*=2;
    }
  }
  cout<<s;
  
return 0;}