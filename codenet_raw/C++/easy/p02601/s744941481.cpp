#include<iostream>
using namespace std;

int main(){
    int a,b,c,k;
    int count=0;
    cin>>a>>b>>c;
    cin>>k;
    while(b<a&&count<k){
        if(b<a){
            b=b*2;
            count++;
        }
    }
    while(c<b&&count<k){
        if(c<b){
            c=c*2;
            count++;
        }
    }
    if(a<b&&b<c)cout<<"Yes\n";
    else cout<<"No\n";


}


                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
