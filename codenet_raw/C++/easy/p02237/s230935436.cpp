#include <stdio.h>
#define N 100


int main(){

  int i,j,n,u[N],k[N];
  int Adj[N][N],t[N];


  scanf("%d",&n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      Adj[i][j] = 0;
    }
  }


  for(i=0; i<n; i++){

    scanf("%d %d",&u[i],&k[i]);
    for(j=0; j<k[i]; j++){
      scanf("%d",&t[j]);

      Adj[u[i]][t[j]-1] = 1;
    }

  }


  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%d ",Adj[u[i]][j]);
    }
    printf("\n");
  }
  return 0;
}