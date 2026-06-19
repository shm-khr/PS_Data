#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    int N;
    cin >> N;
    int D[N];
    int A[100];
    int res=0;
    for (int i=0;i<N;i++)cin>>D[i];
    for (int i=0;i<100;i++){
        for(int j=0;i<N;i++){
            if(D[j]==i+1)A[i]+=1;
        }
    }
    for (int i=0;i<100;i++){
        if(A[i])res++;
    }
    cout<<res;
}