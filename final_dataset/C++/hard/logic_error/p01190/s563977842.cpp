#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  queue<int> Q;
  string s,ans;
  int i,j,n,k,start,end,BtoA=0,count=0,count2=0,flag=0,ex=0,ex2=0,ex3=0,give=0,up=0;

  cin >> n;
  scanf("\n");
  for(k=0;k<n;k++){ /* 1st */
    while(!Q.empty())Q.pop();
    ex=0;
    ex2=0;
    ex3=0;
    count=0;
    count2=0;
    flag=0;
    s.clear();
    ans.clear();
    BtoA=0;
    start=0;
    end=0; 
    give=0;
    up=0;

    getline(cin,s);
    for(i=0;i<s.length();i++){ /*2nd*/
      if(s[i] == 'a' && s.substr(i,9) == "a list of"){

	for(int gg=i+1;gg<s.length();gg++){
	  if(s[gg] == 'a'){
	    if(s.substr(gg,3) == "and"){
	      if((65<=s[gg+4] && s[gg+4]<=90)){
	     
		  ex=1;

	      }
	      break;
	    }
	  }
	}
	ans.insert(BtoA,"(");
	count2++;
	BtoA++;
	Q.push(1);
      } 
      if(65<=s[i] && s[i]<=90 && start == 0 && end ==0){
	start=i;
      }

      if(65<=s[i] && s[i]<=90 && start != 0){
	if(!(65<=s[i+1] && s[i+1]<=90))end=i; 
	if(end != 0){/*3rd*/

	  ans.insert(BtoA,s.substr(start,((end - start)+1)));
	  BtoA+=((end - start)+1);
	  count=1;
 

	  /*
	  if(ans.substr(BtoA - ((end - start)+2),1) == "(" ){
	    ans.insert(BtoA,")");
	    BtoA++;
	    count2--;

	  }
*/

     
	 
	  //  cout << "ex = " << ex << endl;

	  if(!Q.empty()){/*if*/ans.insert(BtoA," ");
	    BtoA++;
	  }/*if*/
	  start=0;
	  end=0;
	}/*3rd*/
      } 
      if(s[i] == 'a' && s.substr(i,3) == "and"){/*MEN*/
	start=i+4;
	if(s[i+4] == 'a' && s.substr(i+4,9) == "a list of")flag=1;
	for(j=i+4;;j++){
	  if(!(65<=s[j+1] && s[j+1]<=90 )){end=j;
	    break;
	  }
	}
	
	if(flag == 0){
	  ans.insert(BtoA,s.substr(start,((end - start)+1)));
	  BtoA+=((end - start)+1);
	  count++;
	  ans.insert(BtoA,")");
	  BtoA++;
	  Q.pop();
	    
	  i+=3+((end-start)+1);
	  if(!Q.empty()){
	    ans.insert(BtoA," ");
	    BtoA++;
	  }
	}
	start=0;
	end=0;
	 
	 


      }/*"MEN"*/      
       
     
    }/*2nd*/ 
   
    //  cout << ans << endl;

    if(!Q.empty() && count != 1){
      cout << "AMBIGUOUS" << endl;
    }
    else if(!Q.empty() && count == 1){
      for(int rr=0;rr<ans.length()-1;rr++)cout << ans[rr];
      for(int h=0;h<count2;h++){
	cout << ")";
      }
      cout << endl;
    }
    else{
      cout << ans << endl;
    }
     
  }/* 1st */
   

}