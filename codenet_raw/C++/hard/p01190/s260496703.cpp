#include<iostream>
#include<cstdlib>
#include<sstream>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back

enum{LIST=-1,COMMA=-2,AND=-3};
const int N = 500;
int se[N][N];//all sexpression
int ce[N][N];//se separated by comma. se,se....,se 
int path[N][N];
int path2[N][N];
int countup2(int i,int j,vector<int> &in);

int countup(int i,int j,vector<int> &in){
  if (i==j)return in[i] >= 0;
  if (in[i] != LIST)return 0;
  int &ret=se[i][j];
  if (se[i][j] == -1){
    ret=0;
    ret=countup(i+1,j,in);
    if (ret == 1)path[i][j]=-1;
    for(int k=i+1;k<j && ret < 2;k++){
      if (in[k] == AND){
	int a=countup2(i,k-1,in);
	int b=countup(k+1,j,in);
	//cout << i <<" " <<k <<" " <<  j <<" " << a <<" " << b << endl; 
	ret+=a*b;
	if (a*b == 1)path[i][j]=k;
      }
    }
  }
  ret=min(2,ret);
  //cout << i <<" " << j <<" " << ret << endl;
  return ret;
}

int countup2(int i,int j,vector<int> &in){
  int &ret=ce[i][j];
  if (i == j)return in[i] >= 0;
  if (i+1 == j && in[i]>=0 && in[j] == COMMA)return 1;
  //if (in[i] != LIST)return 0;
  if (ret == -1){
    ret=0;
    ret=countup(i+1,j,in);
    if (ret == 1)path2[i][j]=-1;
    for(int k=i+1;k<j && ret < 2;k++){
      if (in[k] == COMMA){
	int beg=in[i]==LIST?i:i+1;
	int a=countup2(beg,k-1,in);
	int b=countup(k+1,j,in);
	//cout << "test " << in[i+1] << endl;
	//if (i==0&&j==10)
	//cout << i <<" " << k<<" " << j <<" " << a <<" " << b << endl;
	ret+=a*b;
	if (a*b == 1)path2[i][j]=k;
      }
    }
  }
  ret=min(2,ret);
  //cout << i <<" " <<j <<" " << ret << endl;
  return ret;
}

void gp2(int,int,vector<int>&,vector<string>&,bool);

void gp(int i,int j,vector<int> &in,vector<string>& str,
	bool lastp){
  //  cout << "A " <<i <<" " << j << endl;
  if (path[i][j] == -1){
    if (i ==j)cout << str[i];
    else {
      cout << '(';
      gp(i+1,j,in,str,true);
      cout << ')';
    }
  }else {
    cout << '(';
    gp2(i,path[i][j]-1,in,str,false);
    //cout <<')';
    cout <<' ';
    //cout << '(';
    gp(path[i][j]+1,j,in,str,false);
    cout <<')';
  }
}

void gp2(int i,int j,vector<int> &in,vector<string>& str,bool lastp){
  //cout <<"B " <<  i<<" " << j << endl;
  if (path2[i][j] == -1){
    if (i == j)cout << str[i];
    else if (i+1 == j && in[i]>=0 && in[j] == COMMA)cout << str[i];
    else {
      //cout << '(';
      gp(i+1,j,in,str,lastp);
      //cout <<')';
    }
  }else {
    //cout <<'(';
    int beg=in[i]==LIST?i:i+1;
    gp2(beg,path2[i][j]-1,in,str,true);
    //cout << ')';
    cout <<' ';
    //cout << '(';
    gp(path2[i][j]+1,j,in,str,false);
    //cout <<')';
  }
  return;
}

main(){
  int te;
  cin>>te;
  string tmp;
  getline(cin,tmp);
  while(te--){
    rep(i,N)rep(j,N)se[i][j]=ce[i][j]=-1;
    rep(i,N)rep(j,N)path[i][j]=path2[i][j]=-1;
    getline(cin,tmp);
    stringstream sin(tmp);
    vector<int> in;
    vector<string> str;
    int cnt=0;
    while(sin>>tmp){
      if (tmp == "a");
      else if (tmp == "list")in.pb(LIST),str.pb("");
      else if (tmp == "of");
      else if (tmp == "and")in.pb(AND),str.pb("");
      else {
	in.pb(cnt++);
	if (tmp[tmp.size()-1] == ','){
	  str.pb(tmp.substr(0,tmp.size()-1));
	}else str.pb(tmp);
	if (tmp[tmp.size()-1] == ',')in.pb(COMMA),str.pb("");
      }

    }
    //cout <<"input: " ;
    //rep(i,(int)in.size())cout << in[i]<<" ";cout << endl;

    int ans=countup(0,(int)in.size()-1,in);
    //cout << ans << endl;
    //cout << path[0][in.size()-1] << endl;
    if (ans == 1)gp(0,(int)in.size()-1,in,str,false);
    else if (ans >=2)cout <<"AMBIGUOUS";
    else exit(1); 
    cout << endl;    
    //cout <<"this case is end" << endl;
  }
  return false;
}