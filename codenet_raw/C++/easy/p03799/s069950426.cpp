#include <cstdio>


int main(){
    long long s, c;
    scanf("%lld%lld", &s, &c);
    if(2*s>c){
        printf("%lld", s);
    }else{
        printf("%lld", s+(c-2*s)/4);
    }
}
