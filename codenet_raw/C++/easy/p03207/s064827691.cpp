#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int s;
    int max_price = 0;
    for(int i = 0; i < n; i++){
        int p;
        scanf("%d", &p);
        if(p > max_price){
            max_price = p;
        }
        s += p;
    }
    s -= max_price/2;
    printf("%d\n", s);

    return 0;
}