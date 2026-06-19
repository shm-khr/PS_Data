#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c,cnt=0;
int main(void){
    cin>>a>>b>>c;
    if((a&1)+(b&1)+(c&1)==1){
        ++cnt;
        if(a&1){
            ++b;
            ++c;
        }
        if(b&1){
            ++a;
            ++c;
        }
        if(c&1){
            ++b;
            ++a;
        }
    }
    if((a&1)+(b&1)+(c&1)==2){
        ++cnt;
        if(~a&1){
            ++b;
            ++c;
        }
        if(~b&1){
            ++a;
            ++c;
        }
        if(~c&1){
            ++b;
            ++a;
        }
    }
    int m=max({a,b,c});
    cnt+=(m-a)/2;
    cnt+=(m-b)/2;
    cnt+=(m-c)/2;
    cout<<cnt<<endl;
    return 0;
}