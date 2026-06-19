#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    int sz;
    sz = str.size();
    int n, s;
    int w, e;
    n=0;
    s=0;
    w=0;
    e=0;
    for(int i=0; i<sz; i++){
        if(str[i]=='N'){
            n++;
        }else if(str[i]=='W'){
            w++;
        }else if(str[i]=='S'){
            s++;
        }else if(str[i]=='E'){
            e++;
        }
    }
    bool flg_hor=false;
    bool flg_ver=false;
    if(n==0 && s==0){
        flg_ver=true;
    }
    if(w==0 && e==0){
        flg_hor=true;
    }
    if(n>0 && s>0){
        flg_ver=true;
    }
    if(w>0 && e>0){
        flg_hor=true;
    }
    if(flg_hor && flg_ver){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
