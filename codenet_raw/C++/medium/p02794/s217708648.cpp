#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>

using lli=long long int;

std::vector<std::vector<int>> t_arr;
std::vector<lli> find_path(int current, int parent, int dest){
  if(current == dest) return std::vector<lli>(1, dest);
  for(auto&& node: t_arr[current]){
    if(node == parent) continue;
    auto tmp = find_path(node, current, dest);
    if(tmp.size() > 0){
      tmp.push_back((1<<current)+(1<<node));
      return tmp;
    }
  }
  return std::vector<lli>(0);
}


int main(){
  int N;
  std::cin >> N;
  t_arr = std::vector<std::vector<int>>(N);
  for(int i = 0; i < N-1; i++){
    int a,b;
    std::cin >> a >> b;
    a--; b--;
    t_arr[a].push_back(b);
    t_arr[b].push_back(a);
  }
  int M;
  std::cin >> M;
  std::vector<std::vector<lli>> path_arr;
  for(int i = 0; i < M; i++){
    int u,v;
    std::cin >> u >> v;
    u--; v--;
    auto tmp = find_path(u, -1, v);
    path_arr.emplace_back(std::next(tmp.begin()), tmp.end());
    //path_arr.emplace_back(tmp.begin(), tmp.end());
  }
  
  lli ans = 0;
  for(int ni = 0; ni < (1<<M); ni++){
    std::unordered_set<lli> total_set;
    int nbits = 0;
    for(int di = 0; di < M; di++){
      if((1<<di)&ni){
        nbits++;
        for(auto&& it: path_arr[di]){
          total_set.insert(it);
        }
      }
    }
    lli npattern = 1<<(N-1-total_set.size());

    if(nbits&1){
      ans -= npattern;
    }else{
      ans += npattern;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}

