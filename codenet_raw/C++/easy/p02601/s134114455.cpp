#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int r, g, b, t, flag = 0;
    cin >> r >> g >> b >> t ;
    
    for(int i = 0; i < t; i++){
        if(b < g){
            b *= 2;
        } else if(g < r){
            g *= 2;
        } else if (b < r){
            b *= 2;
        }
        
        if(r < g && g < b){
            flag++;
            break;
        }
    }
    
    if(flag > 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}
