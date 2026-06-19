#include<iostream>
#include<queue>
#include<set>
#include<iomanip>

#define N 5
using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};

struct Dice{
  int D[6];
  Dice(){for(int i = 0; i < 6; ++i)D[i]=-1;}
  void roll(int dir){
    int t;
    switch(dir){
    case NORTH:t=D[4];D[4]=D[5];D[5]=D[1];D[1]=D[0];D[0]=t;break;
    case EAST: t=D[3];D[3]=D[5];D[5]=D[2];D[2]=D[0];D[0]=t;break;
    case SOUTH:t=D[1];D[1]=D[5];D[5]=D[4];D[4]=D[0];D[0]=t;break;
    case WEST: t=D[2];D[2]=D[5];D[5]=D[3];D[3]=D[0];D[0]=t;break;
    }
  }
  bool isDice(){
    for(int i = 0; i < 3;++i){
      if(D[i]+D[5-i]!=7)return false;
    }
    return true;
  }
};

struct state{
  int i,j,pre;
  state(int i, int j, int p):i(i),j(j),pre(p){}
};

bool isinside(int i, int j){
  return 0<=i&&i<N&&0<=j&&j<N;
}

bool solve(int M[][N], int sti, int stj, int L){
  queue<state> Q;
  state st(sti,stj,1);
  int left=L;
  Dice d;
  d.D[0]=M[sti][stj];
  Q.push(st);
  while(!Q.empty()){
    state now = Q.front();Q.pop();
    for(int k = (now.pre-1+4)%4, nk=0; nk < 4; ++nk){
      state next(now.i+di[k],now.j+dj[k],k);
      Dice td=d;
      if(isinside(next.i,next.j)&&M[next.i][next.j]>0){
	td.roll(k);
	--left;
	if(left<0)break;
	if(td.D[0]==-1||td.D[0]==M[next.i][next.j]){
	  td.D[0]=M[next.i][next.j];
	  Q.push(next);
	  d=td;
	  break;
	}else return false;
      }
      ++k;
      k%=4;
    }
  }
  set<int> S;
  for(int i = 0; i < 6; ++i){
    if(d.D[i]!=-1)S.insert(d.D[i]);
  }
  return (S.size()==6)&&d.isDice()&&L==6;
}

int main(){
  int T;
  
  cin >> T;
  for(int tc=1;tc<=T;++tc){

    int M[N][N];
    int sti,stj,l=0;
    
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
	cin >> M[i][j];
	if(M[i][j]>0){
	  sti=i;
	  stj=j;
	  ++l;
	}
      }
    }
    cout << (solve(M,sti,stj,l)?"true":"false") << endl;
  }
  return 0;
}