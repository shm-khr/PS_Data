#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n],y[n];
    int maxdiff,mindiff;
    cin>>x[0]>>y[0];
    maxdiff=abs(x[0]+y[0]);int imini=0,imaxi=0;
    mindiff=abs(x[0]+y[0]);
    for(int i=1;i<n;i++)
    {
        cin>>x[i]>>y[i];
        if(abs(x[i]+y[i])>maxdiff)
        {
          maxdiff=abs(x[i]+y[i]);
          imaxi=i;
        }
        if(abs(x[i]+y[i])<mindiff)
        {
          mindiff=abs(x[i]+y[i]);
          imini=i;
        }
    }
    cout<<abs(x[imaxi]-x[imini])+abs(y[imaxi]-y[imini]);
}