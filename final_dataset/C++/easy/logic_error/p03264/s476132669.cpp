#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    if(k%2 == 0){
          printf("%d\n", (k/2) * (k/2));
    }else{
          printf("%d\n", (k/2) * (k+1)/2);

     return 0;
}