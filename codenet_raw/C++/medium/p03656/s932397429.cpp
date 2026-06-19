#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <complex>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cctype>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <deque>
#include <stack>
#include <memory.h>
using namespace std;
#define ll long long 
int n,m;
int love[305][305];
int u[500];
vector<int> v(1000,0);
int main()
{
	cin>>n>>m;
	while(1){
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>love[i][j];
			love[i][j]--;
		}
	}
	int mx=-9;
	for(int i=0;i<n;i++){
		v.clear();
		for(int j=0;j<m;j++){
			v[i]++;
		}
		mx=-9;
		for(int k=0;k<v.size();k++){
			mx=max(v[i],mx);
		}
		u[i]=mx;
	} 
	for(int i=0;i<n;i++){
		if(u[i]==0){
			u[i]=-999;
		}
	}
	sort(u,u+n);
	int ans=0;
	int res=0;
	int i=0;
	while(ans<n){
		ans+=u[i];
		res=max(res,u[i]);
		i++;
	}
	cout<<res;
    return 0;
}