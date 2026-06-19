#include<iostream>
#include<algorithm>

using namespace std;

int F[5][5];
bool u[5][5];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

struct Die{
  int p[6];
  bool f;
  int b;
  Die():p{},f(),b(){
  }
  void set(int x){
    if(p[0]){
      f=true;
    }else{
      p[0]=x;
      b|=1<<x;
    }
  }
  void rot(int *x){
    int t=p[x[0]];
    p[x[0]]=p[x[1]];
    p[x[1]]=p[x[2]];
    p[x[2]]=p[x[3]];
    p[x[3]]=t;
  }
  void rot(int x){
    if(x>=2){
      rot(x^2);
      rot(x^2);
      rot(x^2);
    }else{
      static int r[][4]={
	{0,4,5,1},
	{0,2,5,3},
      };
      rot(r[x]);
    }
  }
  bool is_valid(){
    return b+2==1<<7&&!f&&p[0]+p[5]==7&&p[1]+p[4]==7&&p[2]+p[3]==7;
  }
};

void dfs(int y,int x,Die &d){
  if(y<0||5<=y||x<0||5<=x||F[y][x]==0||u[y][x]++)return;
  d.set(F[y][x]);
  for(int i=0;i<4;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];
    d.rot(i);
    dfs(ny,nx,d);
    d.rot(2^i);
  }
}

int main(){
  int N;
  cin>>N;
  while(N--){
    bool f=true;
    int y=0,x=0;
    int c=0;
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	cin>>F[i][j];
	if(F[i][j]){
	  y=i;
	  x=j;
	  c++;
	}
      }
    }
    fill(u[0],u[5],false);
    Die d;
    dfs(y,x,d);
    cout<<boolalpha<<(c==6&&d.is_valid())<<endl;
  }
}