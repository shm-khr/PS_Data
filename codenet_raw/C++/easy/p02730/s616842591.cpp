#include <iostream>
#include <string>
using namespace std;
 
int main(void){

  
//  int n,m;
    string s;
  
//  cin >> n >> m;
     cin >> s;
  
    int leng = s.size();


    for(int i=0 ; i < (leng/2)/2 ; i++){
        if (s[i] != s[(leng/2)-i] ) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i=leng/2+2 ; i < (leng/2)+2+(leng/4) ; i++){
        if (s[i] != s[(leng/2)-i] ) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
//  cout << (n*(n-1)) + (m*(m-1)) << endl;
  
  return 0;
}
