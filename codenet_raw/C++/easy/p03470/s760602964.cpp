#include<iostream>
#include<float.h>
#include<cfloat>
#include<string>
#include<ctype.h>
#include<algorithm>
#include<errno.h>
#include<cerrno>
#include<assert.h>
#include<cassert> 
#include<map>
#include<memory.h>
#include<cctype>
#include<ctype.h>
#include<math.h>
#include<vector> 
#include<cstdio> 
#include<set>
#include<string.h>
#include<stdio.h>
#include<new>
#include<memory>
#include<cmath>
#include<queue>
#include<cstring>
#define ll long long
#define fo(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define br break
#define ct continue
#define pb push_back
#define pi 3.141592653589793238462643383279502884197169
#define F first
#define S second
#define em empty()
#define vei vector<int>
#define ves vector<string>
#define qui queue<int> 
#define qu queue
using namespace std;
int a[150];
int main()
{int n;
 cin>>n;
 fo(i,0,n)
 cin>>a[i];
 sort(a,a+n);
 fo(i,0,n)
 if(a[i]==a[i+1])
 n--;
 cout<<n; 
 system("pause");
 return 0;
}