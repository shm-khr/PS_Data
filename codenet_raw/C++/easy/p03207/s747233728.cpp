#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
//#include<numerice>
using namespace std;
int main(){
    int N,total;
    int  price_max=-10;
    cin>>N;
    for(int i=0;i<N;i++){
        int price;
        cin >>price;
        total+=price;
        price_max=max(price_max,price);
    }
    cout<<total-price_max+(price_max/2)<<endl;
    return 0;
}