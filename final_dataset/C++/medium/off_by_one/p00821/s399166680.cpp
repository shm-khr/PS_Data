#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;
 
#define MAX 5000
#define MAX_N 105
int n,x[MAX],y[MAX];
int L[MAX],R[MAX];
 
void f(int x,int y){
  L[y]=min(L[y],x);
  R[y]=max(R[y],x);
} 
 
void init(){
  for(int i=0;i<MAX;i++){
    L[i]=5000;
    R[i]=-1;
  }
}
 
int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    init();
 
    vector<P> V;
    for(int i=0;i<n;i++){
      cin>>x[i]>>y[i];
      V.push_back( P(x[i],y[i]));
      x[i]+=2005,y[i]+=2005;
    }
    double sum=0;
    for(int i=0;i<n;i++){
      sum+=arg( (V[(i+2)%n]-V[(i+1)%n])*conj(V[(i+1)%n]-V[i]) );
    }
 
    if(sum<0){
      reverse(x,x+n);
      reverse(y,y+n);
    }
 
    for(int i=0;i<n;i++){
      int sx=x[i],sy=y[i];
      int tx=x[(i+1)%n],ty=y[(i+1)%n];
      if(sx==tx){
        if(sy<ty) for(int i=sy;i<ty;i++)f(sx-1,i);
        else for(int i=ty;i<sy;i++)f(sx,i);
        continue;
      }
      if(sy==ty){
        if(sx<tx)f(sx,sy),f(tx-1,sy);
        else f(sx-1,sy-1),f(tx,sy-1);
        continue;
      }
      if(tx<sx)swap(sx,tx),swap(sy,ty);
      int vx=tx-sx,vy=ty-sy;
      long long  A=abs(vx),B=abs(vy);
      if(vy>0){
        f(sx,sy);
        for(int y=sy;y<ty;y++){
          if(A%B==0){
            f(sx+A/B-1,y);
            if(y+1<ty)f(sx+A/B-1+1,y+1);
          }else{
            f(sx+A/B,y);
            if(y+1<ty)f(sx+A/B,y+1);
          }
          A+=abs(vx);
        }
      }
       
      if(vy<0){
        f(sx,sy-1);
        for(int y=sy-1;y>=ty;y--){
          if(A%B==0){
            f(sx+A/B-1,y);
            if(y-1>=ty)f(sx+A/B-1+1,y-1);
          }else{
            f(sx+A/B,y);
            if(y-1>=ty)f(sx+A/B,y-1);
          }
          A+=abs(vx);
        }
      }
    }
    int ans=0;
    for(int i=0;i<MAX;i++)
      if(L[i]<=R[i])
        ans+=(R[i]-L[i]+1);
    cout<<ans<<endl;
  }
  return 0;
}