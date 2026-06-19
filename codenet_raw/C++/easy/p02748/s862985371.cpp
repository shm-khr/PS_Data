#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back
#define mk make_pair
#define REP(i,a,b) for(int i=a; i<=b; i++)
#define mod 1000000007
int main()
{
    ll a,b,m,t,t1=INT_MAX, m1=INT_MAX,m2=INT_MAX;
    cin>>a>>b>>m;
    bool found = 0;
    vector<int>A(a),B(b);
    vector<int> X[3];
    vector<int> i1,i2;
    REP(i,0,a-1)
    {
        cin>>A[i];
    }
    REP(i,0,b-1)
    {
        cin>>B[i];
    }
    REP(i,0,m-1)
    {
        cin>>t;
        X[0].push_back(t);
        cin>>t;
        X[1].push_back(t);
        cin>>t;
        X[2].push_back(t);
    }
    REP(i,0,a-1)
    {
        if(A[i]<=m1)
        {m1=A[i];i1.push_back(i);}
    }
    REP(i,0,b-1)
    {
        if(B[i]<=m2)
        {m2=B[i];i2.push_back(i);}
    }
    REP(i,0,m-1)
    {
        int siz = i1.size();
        REP(j,0,siz-1)
        {
        if((X[0][i]-1)==i1[j])
        {
            // REP(j,0,m-1)
            // {
            //cout<<"aya";
            int sz = i2.size();
            REP(k,0,sz-1)
                if((X[1][i]-1)==i2[k])
                {t1=X[2][i];found =1;break;}
            //}
            
        }
        }
    }
    //cout<<m2<<'\t'<<i2;
    //cout<<i1.size()<<" "<<i2.size()<<" ";
    if(found)
    {
        cout<<m1+m2-t1;
    }
    else
    cout<<m1+m2;
  
}
