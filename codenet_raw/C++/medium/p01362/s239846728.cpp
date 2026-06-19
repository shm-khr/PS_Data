#include<vector>
#include<queue>
#include<iostream>
#include<cstdlib>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define rotate_swap(p,a,b,c,d) swap(p[a],p[b]);swap(p[b],p[c]);swap(p[c],p[d]);
enum{FR=0,RI,BA,LE,TO,BO};
const int inf = (1<<20);

void rotate_ccw(char m[3][3]){
  static char buf[3][3];
  rep(i,3)rep(j,3)buf[i][j]=m[i][j];
  rep(i,3)rep(j,3)m[i][j]=buf[j][3-1-i];
}

void upsideDown(char m[3][3]){
  rep(j,3)swap(m[0][j],m[2][j]);
}

class Dice{
public:
  int d[6];
  char m[6][3][3];
  void rotate_b(){
    rotate_ccw(m[d[LE]]);
    rotate_ccw(m[d[RI]]);
    rotate_swap(d,TO,BA,BO,FR);
  }
  void rotate_f(){
    rep(i,3)rotate_b();
  }
  void rotate_l(){
    rotate_ccw(m[d[FR]]);
    rotate_ccw(m[d[BA]]);
    upsideDown(m[d[LE]]);
    upsideDown(m[d[BO]]);
    rotate_swap(d,TO,LE,BO,RI);
  }
  void rotate_r(){
    rep(i,3)rotate_l();
  }
  bool isok(){

    if ((m[d[FR]][2][0] =='*' || 
	 m[d[FR]][2][1] =='*' || 	
	 m[d[FR]][2][2] =='*' )
	&&
	(m[d[BA]][0][0] =='*' || 
	 m[d[BA]][0][1] =='*' || 	
	 m[d[BA]][0][2] =='*' ))return true;

    //rep(i,3)if (m[d[FR]][2][i] == '*' && m[d[BA]][0][i] == '*')return true;
    //rep(i,3)cout << (m[d[FR]][2][i]) <<" " << (m[d[BA]][0][i]) << endl;
    return false;
  }
  void op(int a){
    rep(i,3){
      rep(j,3){
	cout << m[d[a]][i][j];
      }
      cout << endl;
    }
    cout <<"Op end" << endl;
  }
};

int cost[6][6][6];
int solve(Dice & ini){
  rep(i,6)rep(j,6)rep(k,6)cost[i][j][k]=inf;
  queue<Dice> Q;
  Q.push(ini);
  cost[ini.d[0]][ini.d[1]][ini.d[2]]=0;
  while(!Q.empty()){
    Dice now = Q.front();Q.pop();
    int nc=cost[now.d[0]][now.d[1]][now.d[2]];
    if (now.isok())return nc;
    //front
    Dice next=now;next.rotate_f();
    if (cost[next.d[0]][next.d[1]][next.d[2]] == inf){
      cost[next.d[0]][next.d[1]][next.d[2]]=nc+1;
      Q.push(next);
    }

    next=now;next.rotate_b();
    if (cost[next.d[0]][next.d[1]][next.d[2]] == inf){
      cost[next.d[0]][next.d[1]][next.d[2]]=nc+1;
      Q.push(next);
    }

    next=now;next.rotate_l();
    if (cost[next.d[0]][next.d[1]][next.d[2]] == inf){
      cost[next.d[0]][next.d[1]][next.d[2]]=nc+1;
      Q.push(next);
    }

    next=now;next.rotate_r();
    if (cost[next.d[0]][next.d[1]][next.d[2]] == inf){
      cost[next.d[0]][next.d[1]][next.d[2]]=nc+1;
      Q.push(next);
    }

  }
  return -1;
}


main(){
  while(true){
    Dice ini;rep(i,6)ini.d[i]=i;
    rep(i,6){
      rep(j,3){
	string tmp;cin>>tmp;if (tmp == "#")return 0;
	rep(k,3)ini.m[i][j][k]=tmp[k];
      }
      if (i == RI || i == LE){
	rep(k,3)rotate_ccw(ini.m[i]);
      }else if (i == BA || i == BO){
	upsideDown(ini.m[i]);
      }
    }
    /*
    ini.rotate_l();
    ini.op(TO);
    ini.rotate_f();
    ini.op(FR);
    ini.op(BA);
    */
    //cout << ini.isok() << endl;
    cout << solve(ini) << endl;
  }
}