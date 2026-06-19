#include <iostream>
#include <string>
using namespace std;


int main(){
    char S[100];
    cin >> S;
    int N;
    N = strlen(S);

    bool answer = true;

    for(int i=0; i<N/2-1; i++){
        if(S[i] != S[N-1-i]){
            answer = false;
        }
    }

    for(int j=0; j<(N-1)/4; j++){
        if(S[j] != S[(N-1)/2-j-1]){
            answer = false;
        }
    }

    for(int k=0; k<(N-3)/2; k++){
        if(S[(N+3)/2-1+k] != S[N-k-1]){
            answer = false;
        }
    }

    if(answer){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}