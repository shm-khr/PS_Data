#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, A;
    cin >> N >> A;

    if(A % 2 == 0){
        
        
        if(!(A != 3)){
            if(!(A /= 5)){
                cout << "DENIED" << endl;
                }
            }
        
        if(A % 3 == 0 || A % 5 == 0){
            
            cout << "APPROVED" << endl;
        }
        else{
            cout << "DENIED" << endl;
        }
    }
    else{
        cout << "DENIED" << endl;
    }

}