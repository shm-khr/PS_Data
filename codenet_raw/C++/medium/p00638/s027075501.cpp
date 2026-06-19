#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <stack>
#include <list>
using namespace std;
#define INF 100000000
typedef long long int lli;
typedef pair<int,int> P;

int main(){
	int n;
	while(cin>>n&&n){
		vector<P> bridge(n);
		for(int i=0; i<n; ++i){
			cin >> bridge[i].first; //weight
			cin >> bridge[i].second; //limit
		}
		for(int i=0; i<n; ++i){
			for(int j=n-1; j-1>=i; --j){
				if(bridge[j].second<bridge[j-1].second){
					swap(bridge[j],bridge[j-1]);
				} else if(bridge[j].second==bridge[j-1].second&&bridge[j].first<bridge[j-1].first){
					swap(bridge[j],bridge[j-1]);
				}
			}
		}
		bool f=true;
		int w=0;
		for(int i=0; i<n; ++i){
			if(w+bridge[i].second<=bridge[i].second){
				w+=bridge[i].first;
			} else {
				f=false;
			}
		}
		if(f){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}