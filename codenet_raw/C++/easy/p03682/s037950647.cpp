#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<functional>
#include<queue>
#include<math.h>
#define INF 999999

using namespace std;

typedef pair<int,int> P;
typedef pair<int, pair<int, int> > P2;
int visited[100050];

int main()
{
	int n;
	cin >> n;
	vector<P> x;
	vector<P> y;
	
	for (int i = 0; i < n; i++) {
		int xi, yi;
		cin >> xi >> yi;
		x.push_back(P(xi,i));
		y.push_back(P(yi,i));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<P2> road;
	for (int i = 1; i < n; i++) {
		road.push_back(P2(x[i].first - x[i - 1].first, make_pair(x[i - 1].second,x[i].second)));
		road.push_back(P2(y[i].first - y[i - 1].first, make_pair(y[i - 1].second, y[i].second)));
	}
	sort(road.begin(), road.end());

	int cost = 0;
	int edge = 0;
	int i = 0;
	while(edge<=n-1&&i<road.size()){
		if (visited[road[i].second.first] == 0 || visited[road[i].second.second] == 0) {
			cost += road[i].first;
			visited[road[i].second.first]++;
			visited[road[i].second.second]++;
			edge++;
		}
		i++;
	}

	cout << cost << endl;

	return 0;
}

