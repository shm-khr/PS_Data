#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int main(){
  queue<int> Q;
  string s;
  int i,j,n,k,next2=0,next=0,anDfl=0;
  
  cin >> n;
  scanf("\n"); /*üsªXgOÉe¿·é½ß±±ÅÁïµÄ¨­*/
  for(k=0;k<n;k++){
    getline(cin,s);
    
    /*AMBIGUOUSÉÈé©Ç¤©Ì*/
    for(i=0;i<s.length();i++){
      if(s[i] == 'f' && !( 65<=s[i+2] && s[i+2]<=90)){
	next=1;
	break;
      }
    }
    if(next == 1){
      next=0;
      cout << "AMBIGUOUS" << endl;
      continue;
    }
   

    /*êñÅIíé©Ç¤©Ì*/
 for(i=0;i<s.length();i++){
      if(s[i] == 'f' && ( 65<=s[i+2] && s[i+2]<=90) && s[i+3] == '\0'){
	cout << "(" << s[i+2] << ")" << endl;
	next2=1;
	break;
      }
    }
    if(next2 == 1){
      next2=0;
      continue;
    }

    
    /*³íÉüÍ³ê½êÌ*/
    for(i=0;i<s.length();i++){
      
      if(s[i] == 'f' && ( 65<=s[i+2] && s[i+2]<=90) ){
	cout << "(";
	Q.push(1);
      }

	if(s[i] == ','){/*1*/
	  if(65<=s[i-1] && s[i-1]<=90){
	    cout <<s[i-1] << " ";
	  }
	}/*1*/

	if(s[i] == 'a' && s[i+1] == 'n' && s[i+2] == 'd'){
	  if(s[i-6] == 'a' && s[i-5] == 'n' && s[i-4] == 'd')anDfl=1;	  
	  //cout << " Flaf =" << anDfl << " " ;

	  if(anDfl == 0){
	  cout <<s[i-2]<<" " <<s[i+4] << ")";
	  i+=5;
	  }
	  else{
	    cout << s[i+4] << ")";
	      i+=5;
	      anDfl=0;
	  }
	  Q.pop();
	  if(Q.empty()){cout << endl;
	    break;
	  }
	  else cout << " ";
	}
	
      }
      
    }
    
    

  
  
  return 0;
}