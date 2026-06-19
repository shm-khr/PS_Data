#include<iostream>
#include<vector>

using namespace std;

int n,m,p;
int dx[26]={0,1,1,1,0,-1,-1,-1,0,1,1,1,0,-1,-1,-1,0,0,1,1,1,0,-1,-1,-1,0};
int dy[26]={1,1,0,-1,-1,1,0,-1,1,1,0,-1,-1,1,0,-1,0,1,1,0,-1,-1,1,0,-1,0};
int dz[26]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

vector<int> a[8][8];

bool check(int nx, int ny, int nz){
  if(nx<0 || ny<0 || nz<0)return false;
  if(nx>=n || ny>=m || nz>=a[nx][ny].size())return false;
  return true;
}

bool dim(int x, int y, int z, int t){
  int nx,ny,nz;
  for(int i=0;i<26;i++){
    nx = x;
    ny = y;
    nz = z;

    for(int j=0;j<2;j++){


      nx += dx[i];
      ny += dy[i];
      nz += dz[i];

      if(!check(nx,ny,nz) || a[nx][ny][nz]!=t)break;
	
      if(j==1){
	//cout << i << " " << nx <<" "<<ny <<" "<<nz<<endl;
	  return true;
      }
    }
  }
  return false;
}

int main(void){
 
  int x,y;


  while(cin >> n >> m >> p,n|m|p){
    
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	a[i][j].clear();
      }
    }
    bool fg=false;
    for(int i=0;i<p;i++){
      cin >> x >> y;
      
      if(fg)continue;
      x--;y--;
      a[x][y].push_back(i%2);
      
      for(int j=0;j<n;j++){
	for(int k=0;k<m;k++){
	  for(int l=0;l<p;l++){
	    if(check(j,k,l) && a[j][k][l]==i%2 && dim(j,k,l,i%2)){
	      if(i%2==0)cout << "Black " << i+1 << endl;
	      else if(i%2==1)cout <<"White "<< i+1 << endl;
	      fg=true;
	    }
	    if(fg)break;
	  }
	  if(fg)break;
	}
	if(fg)break;
      }
      
    }
    if(!fg)cout << "Draw" << endl;
  }

  return 0;
}