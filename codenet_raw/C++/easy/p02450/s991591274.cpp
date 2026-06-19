#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n,a[20],tot=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i]=i;
        tot*=i;
    }
    tot*=n;
    for(int i=0;i<tot;i++){
        printf("%d",a[1]);
        for(int j=2;j<=n;j++)printf(" %d",a[j]);
        printf("\n");
        next_permutation(a+1,a+n+1);
    }
}
