#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

string st;

namespace cent {

	struct Edge {
		int src;
		int dst;
		int k;
	};
	using Graph = vector<vector<Edge>>;

	class Centroid {
	private:
		int dfs(const Graph&g, const int now, const int from, vector<int>&ch_nums, const vector<int>&oks) {
			int sum = 1;
			for (auto &&e : g[now]) {
				if (e.dst == from || oks[e.dst] != -1)continue;
				else {
					sum += dfs(g, e.dst, e.src, ch_nums, oks);
				}
			}
			return ch_nums[now] = sum;
		};

		int find_centroid(const int asize, const vector<vector<Edge>>&graph, const int pre_root, const int pre_from, const vector<int>&ch_nums, const vector<int>&oks) {
			for (auto&& e : graph[pre_root]) {
				if (e.dst == pre_from)continue;
				if (oks[e.dst] != -1)continue;
				if (ch_nums[e.dst]>asize / 2)return find_centroid(asize, graph, e.dst, e.src, ch_nums, oks);
			}
			return pre_root;
		}
		void dfs2(const vector<vector<Edge>>&graph, int now, int from,int pre_from, vector<int>&len_s, pair<int,pair<int,int>>p,int dd) {
			{
				if (p.first >= 0 && p.first == p.second.first) {
					len_s.push_back(p.first);
				}
				else if (p.first <= 0 && p.first == p.second.second) {
					len_s.push_back(p.first);
				}
			}
			for (auto &&e : graph[now]) {
				if(e.dst==pre_from||e.dst==from)continue;
				if(oks[e.dst]<=dd&&oks[e.dst]!=-1)continue;
				{
					auto np(p);
					np.first+=st[e.dst]=='('?1:-1;
					np.second.first=max(np.second.first,np.first);
					np.second.second=min(np.second.second,np.first);

					dfs2(graph,e.dst,now,pre_from,len_s,np,dd);
				}
			}
		}

		int cent(const vector<vector<Edge>>&graph, vector<int>&oks, const int root, const int from, vector<vector<int>>&centroid_edges, int& fst_centroid, int depth, vector<int>&ch_nums) {
			dfs(graph, root, from, ch_nums, oks);

			int cent_id = find_centroid(ch_nums[root], graph, root, from, ch_nums, oks);

			long long int nans=0;
			

			oks[cent_id] = depth;
			if (from != -1) {
				centroid_edges[from].push_back(cent_id);
			}
			else {
				fst_centroid = cent_id;
			}

			map<int, long long int>mp;
			
			
			for (auto e : graph[cent_id]) {
				if (e.dst == from)continue;
				if(oks[e.dst]!=-1)continue;
				int e_cent_id=cent(graph, oks, e.dst, e.src, centroid_edges, fst_centroid, depth + 1, ch_nums);
				pair<int,pair<int,int>>b_p;
				if (st[e_cent_id] == '(') {
					b_p=make_pair(1,make_pair(1,0));
				}
				else {
					b_p=make_pair(-1,make_pair(0,-1));
				}
				dfs2(graph, e_cent_id, -1, cent_id, lens[e_cent_id], b_p,depth);
				//cout<<lens[e_cent_id].size()<<endl;
				map<int,int>n_mp;
				for (auto len : lens[e_cent_id]) {
					n_mp[len]++;
					mp[len]++;
				}
				for (auto m : n_mp) {
					int need=-m.first;
					if (st[cent_id] == '(') {
						need--;
					}
					else {
						need++;
					}
					{
						nans -= m.second*n_mp[need];
					}
				}
			}
			mp[0]++;
			for (auto m : mp) {
				int need = -m.first;
				if (st[cent_id] == '(') {
					need--;
				}
				else {
					need++;
				}
				{
					if (mp.find(need) != mp.end()) {

						nans += m.second*mp[need];
					}
				}
			}
			nans /= 2;
			//cout<<root<<" "<<cent_id<<" "<<nans<<endl;
			ans+=nans;

			return cent_id;
		}

	public:
		long long int ans=0;

		vector<vector<int>>lens;
		vector<vector<int>> centroid_graph;
		vector<int>parents;
		vector<int>oks;
		map<pair<int, int>, long long int>mp;

		//fst:root  snd:centroid_graph
		void init(const Graph&g) {
			lens.resize(g.size());
			oks = vector<int>(g.size(), -1);
			int root = -1;
			centroid_graph.resize(g.size());
			parents = vector<int>(g.size(), -1);
			vector<int>ch_nums(g.size());
			cent(g, oks, 0, -1, centroid_graph, root, 0, ch_nums);

			for (int i = 0; i < centroid_graph.size(); ++i) {
				for (auto&& e : centroid_graph[i]) {
					parents[e] = i;
				}
			}
			return;
		}
	}centroid;


}

int main() {
	int N;cin>>N;
	cin>>st;
	using namespace cent;
	vector<vector<Edge>>graph(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b;cin>>a>>b;a--;b--;
		graph[a].push_back(Edge{ a,b,st[b]==')' });
		graph[b].push_back(Edge{ b,a,st[a]=='(' });
	}
	centroid.init(graph);
	cout<<centroid.ans<<endl;
	return 0;
}
