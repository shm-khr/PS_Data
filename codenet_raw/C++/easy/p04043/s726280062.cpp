#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;
    if((a=='5'&&b=='5'&&c=='7')||(b=='5'&&c=='5'&&a=='7')||(c=='5'&&a=='5'&&b=='7'))
        cout<<"Yes"
    else
        cout<<"No";
    return 0;
}
