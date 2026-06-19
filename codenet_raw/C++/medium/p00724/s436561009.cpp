#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stdlib.h>
using namespace std;

int n,k;
int X,Y;
set<pair<int,int> > Rock;
set<vector<pair<int,int> > > Done;
int dx[]={0,1,1,0,-1,-1};
int dy[]={-1,-1,0,1,1,0};

bool is_next(const pair<int,int> &a,const pair<int,int> &b){
	for(int r=0;r<6;r++)
		if(a.first+dx[r]==b.first && a.second+dy[r]==b.second) return true;
	return false;
}

bool cut(int pos,const vector<pair<int,int> > &snake,int cost){
	if(abs(snake[0].first-X)>20-cost || abs(snake[0].second-Y)>20-cost) return false;

	if(Rock.count(snake[pos])) return false;
	for(int i=0;i<=min(pos+1,n-1);i++){
		if(i==pos) continue;
		if(snake[i].first==snake[pos].first && snake[i].second==snake[pos].second) return false;
		if(i==pos-1 || i==pos+1){
			if(!is_next(snake[i],snake[pos])) return false;
		}
		else{
			if(is_next(snake[i],snake[pos])) return false;
		}
	}
	return true;
}

bool is_ok(const vector<pair<int,int> > &snake){
	for(int i=0;i<n;i++){
		if(i+1<n && !is_next(snake[i],snake[i+1])) return false;

		for(int j=i+2;j<n;j++){
			if(is_next(snake[i],snake[j])) return false;
		}
	}
	return true;
}


void make_snake(int pos,vector<pair<int,int> > snake,vector<vector<pair<int,int> > > &all,int cost){
	if(pos>=n){
		if(is_ok(snake) && !Done.count(snake)){
			all.push_back(snake); 
			Done.insert(snake);
		}
		return;
	}
	for(int r=0;r<6;r++){
		snake[pos].first+=dx[r];
		snake[pos].second+=dy[r];
		if(cut(pos,snake,cost))
			make_snake(pos+2,snake,all,cost);
		snake[pos].first-=dx[r];
		snake[pos].second-=dy[r];
	}
	make_snake(pos+1,snake,all,cost);
}

int bfs(vector<pair<int,int> > init_snake){
	queue<pair<vector<pair<int,int> >,int > > Q;
	Q.push(make_pair(init_snake,0));
	int max_cost=0;
	while(!Q.empty()){
		vector<pair<int,int> > snake=Q.front().first;
		int cost=Q.front().second;
		Q.pop();
		if(snake[0].first==X && snake[0].second==Y) return cost;
		if(cost==20) return cost;
		vector<vector<pair<int,int> > > all;
		Done.clear();
		make_snake(0,snake,all,cost);
		for(int i=0;i<all.size();i++){
			if(abs(all[i][0].first-X)>20-cost || abs(all[i][0].second-Y)>20-cost) continue;
			Q.push(make_pair(all[i],cost+1));
		}
	}
	cout<<"Error\n";
	return -1;
}

int main()
{
	while(cin>>n && n!=0){
		Rock.clear();
		Done.clear();
		vector<pair<int,int> > S;
		for(int i=0;i<n;i++){
			int x,y; cin>>x>>y; S.push_back(make_pair(x,y));
		}
		cin>>k;
		for(int i=0;i<k;i++){
			int x,y;cin>>x>>y;Rock.insert(make_pair(x,y));
		}
		cin>>X>>Y;
		cout<<bfs(S)<<endl;;
	}
	return 0;
}