#include<bits/stdc++.h>
using namespace std;
bool vis[100003];
priority_queue<pair<int,vector<int> > >q;
int ans[100003];
vector<int>v[100003];
int main(){
	int n,a,b,k;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int p,x;
		cin>>p>>x;
		ans[p]=x;
		q.push(make_pair(p,v[p]));
		vis[p]=1;
	}
	while(!q.empty()){
		pair<int,vector<int> >tmp=q.top();
		q.pop();
		for(int i=0;i<tmp.second.size();i++)
			if(!vis[tmp.second[i]])
			{
				ans[tmp.second[i]]=ans[tmp.first]-1;
				q.push(make_pair(tmp.second[i],v[tmp.second[i]]));
				vis[tmp.second[i]]=1;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[i].size();j++)
			if(ans[i]-ans[v[i][j]]!=1&&ans[i]-ans[v[i][j]]!=-1)
			{
				cout<<"No";
				return 0;
			}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
}