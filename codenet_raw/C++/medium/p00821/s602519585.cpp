#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2010
bool ed[MAX][MAX];
bool in[MAX][MAX];
bool us[MAX][MAX];

bool out(int y,int x){
  return y<0||MAX<=y||x<0||MAX<=x;
}

struct yx{
  int y,x;
  yx(){}
  yx(int y,int x):y(y),x(x){}
};
int main(){
  int m;
  while(cin>>m,m){
    memset(ed,0,sizeof(ed));
    memset(in,0,sizeof(in));
    memset(us,0,sizeof(us));
    int x[m],y[m];
    for(int i=0;i<m;i++) {
      cin>>x[i]>>y[i];
      y[i]*=-1;
      x[i]+=MAX/2;
      y[i]+=MAX/2;
    }
    for(int j=0;j<m;j++){
      int x1=x[j],y1=y[j],x2=x[(j+1)%m],y2=y[(j+1)%m];
      //cout<<x1<<" "<<y1<<":"<<x2<<" "<<y2<<endl;
      if(x1==x2){
	if(y1>y2) swap(y1,y2);
	for(int i=y1;i<=y2;i++){
	  ed[i][x1]=1;
	  ed[i-1][x1]=1;
	  ed[i][x1-1]=1;
	  ed[i-1][x1-1]=1;
	}
	continue;
      }

      if(y1==y2){
	if(x1>x2) swap(x1,x2);
	for(int i=x1;i<=x2;i++){
	  ed[y1][i]=1;
	  ed[y1][i-1]=1;
	  ed[y1-1][i]=1;
	  ed[y1-1][i-1]=1;
	}
	continue;
      }
      if(abs(y2-y1)<=abs(x2-x1)){
	//cout<<"a"<<endl;
	if(x1>x2){
	  swap(x1,x2);
	  swap(y1,y2);
	}
	if(y1<y2){
	  int g=(x2-x1)/__gcd(y2-y1,x2-x1);
	  //cout<<g<<endl;
	  for(int i=0;i<=x2-x1;i++){
	    int y=y1+((y2-y1)*i)/(x2-x1);
	    if(i%g){
	      in[y][x1+i]=1;
	      in[y][x1+i-1]=1;
	    }else{
	      ed[y][x1+i]=1;
	      ed[y-1][x1+i]=1;
	      ed[y][x1+i-1]=1;
	      ed[y-1][x1+i-1]=1;
	    }
	  }
	}else{
	  int g=(x2-x1)/__gcd(y1-y2,x2-x1);
	  for(int i=0;i<=x2-x1;i++){
	    int y=y1+((y2-y1)*i)/(x2-x1);
	    if(i%g){
	      in[y-1][x1+i]=1;
	      in[y-1][x1+i-1]=1;
	    }else{
	      ed[y][x1+i]=1;
	      ed[y-1][x1+i]=1;
	      ed[y][x1+i-1]=1;
	      ed[y-1][x1+i-1]=1;
	    }
	  }
	}
      }else{
	//cout<<"b"<<endl;
	if(y1>y2){
	  swap(x1,x2);
	  swap(y1,y2);
	}
	if(x1<x2){
	  int g=(y2-y1)/__gcd(y2-y1,x2-x1);
	  for(int i=0;i<=y2-y1;i++){
	    int x=x1+((x2-x1)*i)/(y2-y1);
	    if(i%g){
	      in[y1+i][x]=1;
	      in[y1+i-1][x]=1;
	    }else{
	      ed[y1+i][x]=1;
	      ed[y1+i][x-1]=1;
	      ed[y1+i-1][x]=1;
	      ed[y1+i-1][x-1]=1;
	    }
	  }
	}else{
	  int g=(y2-y1)/__gcd(y2-y1,x1-x2);
	  for(int i=0;i<=x2-x1;i++){
	    int x=x1+((x2-x1)*i)/(y2-y1);
	    if(i%g){
	      in[y1+i][x-1]=1;
	      in[y1+i-1][x-1]=1;
	    }else{
	      ed[y1+i][x]=1;
	      ed[y1+i][x-1]=1;
	      ed[y1+i-1][x]=1;
	      ed[y1+i-1][x-1]=1;
	    }
	  }
	}
      }
    }

    int ax[]={1,-1,0,0},ay[]={0,0,1,-1};
    int ans=0;
    queue<yx> q;
    q.push(yx(0,0));
    while(!q.empty()){
      yx s=q.front();q.pop();
      if(us[s.y][s.x]) continue;
      us[s.y][s.x]=1;
      if(ed[s.y][s.x]) continue;
      for(int k=0;k<4;k++){
	int ny=s.y+ay[k],nx=s.x+ax[k];
	if(out(ny,nx)) continue;
	if(!in[ny][nx]) q.push(yx(ny,nx));
      }
    }

    for(int i=0;i<MAX;i++)
      for(int j=0;j<MAX;j++)
	if(!us[i][j]) ans++;

    /*//
    for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++){
	cout<<us[i][j];
      }
      cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++){
	cout<<ed[i][j];
      }
      cout<<endl;
    }

    cout<<endl;
    for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++){
	cout<<in[i][j];
      }
      cout<<endl;
    }
    //*/
    cout<<ans<<endl;
  }
  return 0;
}