#include <bits/stdc++.h>
using namespace std;
int main()
{
 	int h,c,n;
  	cin>>h>>c>>n;
	map<pair<int,int>,int> mp;
    vector<int> ans(10,0);
    vector<pair<int,int>> la;
  	for(int i=0; i<n; i++)
    {
     	int a,b;
      	cin>>a>>b;
      	for(int m=-1; m<2; m++)
          	for(int q=-1; q<2; q++)
        	    {
		         pair<int,int> p = make_pair(m+a,q+b);
			if(find(la.begin(),la.end(),p) == la.end())
				la.push_back(p);
        	       	  mp[p]++;
        	    } 
   }
/*  	for(auto val:la)
    {
      		cout<<val.first<<" "<<val.second<<"\n";
     	 
    }*/
	for(auto i : la)
	{
		if(i.first > 1 && i.second > 1 && i.first < h && i.second < c)
			ans[mp[i]]++; 

	}
	for(auto i:ans)
		cout<<i<<"\n";
  }