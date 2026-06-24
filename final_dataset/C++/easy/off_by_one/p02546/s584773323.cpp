#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define MA 10e+18
int va=10e8+7;
ll val[200007]={0};
using namespace std;
//Conditional Operator (condition?true part:false part) eg : cout<<(y<=3?"YES":"NO")<<endl;
//string s(3,'1');
// if number of elements in array >10^5 then declare global array.
ll getmul(ll n){ll int k{0};while(n>0){k+=n%10;n=n/10;}return k;}//Sum OF n DIGITS 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    //cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=sz(s);
        if(s[n-1]!=s){
            cout<<s<<'s'<<endl;
        }
        else{
            cout<<s<<"es"<<endl;
        }
    }
 return 0;
}