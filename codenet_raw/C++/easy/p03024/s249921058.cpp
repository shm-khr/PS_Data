#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main()
{
    string s;
    int i,j,len;
    cin>>s;
    len=s.length();
    int cnt=0;
    for(i=0; i<len; i++)
    {
        if(s[i]=='o') cnt++;
    }
    if(cnt>=7)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
